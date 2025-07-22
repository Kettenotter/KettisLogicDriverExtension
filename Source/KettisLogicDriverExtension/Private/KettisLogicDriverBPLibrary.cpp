// Fill out your copyright notice in the Description page of Project Settings.


#include "KettisLogicDriverBPLibrary.h"

#include "AbilitySystemInterface.h"


#include "SMStateMachineInstance.h"

#include "GameFramework/Character.h"
#include "Blueprint/UserWidgetBlueprint.h"




AActor* UKettisLogicDriverBPLibrary::GetContextAsActor(const TScriptInterface<ISMInstanceInterface> NodeInstance)
{
	return Cast<AActor>(GetContextFromObject(NodeInstance.GetObject()));
}


bool UKettisLogicDriverBPLibrary::GetContextAsActorChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, AActor*& Actor)
{

	Actor = Cast<AActor>(GetContextFromObject(NodeInstance.GetObject()));
	
	return IsValid(Actor);
}

APawn* UKettisLogicDriverBPLibrary::GetContextAsPawn(const TScriptInterface<ISMInstanceInterface> NodeInstance)
{
	return Cast<APawn>(GetContextFromObject(NodeInstance.GetObject()));
}

bool UKettisLogicDriverBPLibrary::GetContextAsPawnChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance,
	APawn*& Character)
{
	Character = Cast<APawn>(GetContextFromObject(NodeInstance.GetObject()));
	
	return IsValid(Character);
}

ACharacter* UKettisLogicDriverBPLibrary::GetContextAsCharacter(const TScriptInterface<ISMInstanceInterface> NodeInstance)
{
	return Cast<ACharacter>(GetContextFromObject(NodeInstance.GetObject()));
}

bool UKettisLogicDriverBPLibrary::GetContextAsCharacterChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, ACharacter*& Character)
{
	Character = Cast<ACharacter>(GetContextFromObject(NodeInstance.GetObject()));
	
	return IsValid(Character);
	
}



UObject* UKettisLogicDriverBPLibrary::GetContextAsCastTo(const TScriptInterface<ISMInstanceInterface> NodeInstance, TSubclassOf<UObject> ReturnClass)
{
	//We don't actually need to cast ourself it's done by the Blueprint Node itself.
	
	return  GetContextFromObject(NodeInstance.GetObject());
	
}


bool UKettisLogicDriverBPLibrary::GetContextAsCastToChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance,
														   TSubclassOf<UObject> ReturnClass, UObject*& CastContext)
{
	CastContext = GetContextFromObject(NodeInstance.GetObject())->IsA(ReturnClass) ? GetContextFromObject(NodeInstance.GetObject()) : nullptr;
	
	return IsValid(CastContext);
}

UObject* UKettisLogicDriverBPLibrary::GetContextFromObject(const UObject* Object)
{

	const ISMInstanceInterface* SMInterface = Cast<ISMInstanceInterface>(Object);
	
	if (!SMInterface)
	{
		return nullptr;
	}

	return SMInterface->GetContext();
	
	
}

bool UKettisLogicDriverBPLibrary::GetComponentFromContext(const TScriptInterface<ISMInstanceInterface> NodeInstance,
	TSubclassOf<UActorComponent> ComponentClass, UActorComponent*& Component)
{
	const AActor* ActorContext = Cast<AActor>(GetContextFromObject(NodeInstance.GetObject()));
	if (ActorContext == nullptr)
	{
		return false;
	}
	Component = ActorContext->FindComponentByClass(ComponentClass);

	return IsValid(Component);
	
}

bool UKettisLogicDriverBPLibrary::GetComponentsFromContext(const TScriptInterface<ISMInstanceInterface> NodeInstance,
	TSubclassOf<UActorComponent> ComponentClass, TArray<UActorComponent*>& Components)
{
	const AActor* ActorContext = Cast<AActor>(GetContextFromObject(NodeInstance.GetObject()));
	if (ActorContext == nullptr)
	{
		return false;
	}
	
	ActorContext->GetComponents(ComponentClass, Components);

	return !Components.IsEmpty();
}

UPrimitiveComponent* UKettisLogicDriverBPLibrary::GetContextRootAsPrimitive(
	const TScriptInterface<ISMInstanceInterface> NodeInstance)
{
	const AActor* ActorContext = Cast<AActor>(GetContextFromObject(NodeInstance.GetObject()));
	if (ActorContext == nullptr)
	{
		return nullptr;
	}

	if (UPrimitiveComponent* Prim = Cast<UPrimitiveComponent>(ActorContext->GetRootComponent()))
	{
		return Prim;
	}

	return nullptr;
}

bool UKettisLogicDriverBPLibrary::GetContextRootAsPrimitiveChecked(
	const TScriptInterface<ISMInstanceInterface> NodeInstance, UPrimitiveComponent*& PrimitiveComp)
{
	PrimitiveComp =	GetContextRootAsPrimitive(NodeInstance);

	return IsValid(PrimitiveComp);
}

UAbilitySystemComponent* UKettisLogicDriverBPLibrary::GetAbilitySystemComponentFromContext(
	const TScriptInterface<ISMInstanceInterface> NodeInstance)
{

	const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(GetContextFromObject(NodeInstance.GetObject()));
	if (ASI)
	{
		return ASI->GetAbilitySystemComponent();
	}
	return nullptr;
}

bool UKettisLogicDriverBPLibrary::GetAbilitySystemComponentFromContextChecked(
	const TScriptInterface<ISMInstanceInterface> NodeInstance, UAbilitySystemComponent*& Component)
{

	const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(GetContextFromObject(NodeInstance.GetObject()));
	if (ASI)
	{
		Component = ASI->GetAbilitySystemComponent();
	}

	return IsValid(Component);
}

AActor* UKettisLogicDriverBPLibrary::GetAvatarActorFromContext(
	const TScriptInterface<ISMInstanceInterface> NodeInstance)
{
	const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(GetContextFromObject(NodeInstance.GetObject()));
	if (ASI)
	{
		return ASI->GetAbilitySystemComponent()->GetAvatarActor();
	}
	return nullptr;
}

// Modified delay action
// FDelayAction
// A simple delay action; counts down and triggers it's output link when the time remaining falls to zero
class FDelayLocalAction : public FPendingLatentAction
{
public:
	float TimeRemaining;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TWeakObjectPtr<USMStateInstance> StateInstance;

	FDelayLocalAction(float Duration, const FLatentActionInfo& LatentInfo, USMStateInstance* InStateInstance)
		: TimeRemaining(Duration)
		, ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, StateInstance(InStateInstance)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (!StateInstance->IsActive())
		{
			// Here happens the magic!!! It will look if the state instance is still active and if not will stop the delay (without triggering it)
			Response.DoneIf(true);
		}
		else
		{
			TimeRemaining -= Response.ElapsedTime();
			Response.FinishAndTriggerIf(TimeRemaining <= 0.0f, ExecutionFunction, OutputLink, CallbackTarget);
		}

	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		static const FNumberFormattingOptions DelayTimeFormatOptions = FNumberFormattingOptions()
			.SetMinimumFractionalDigits(3)
			.SetMaximumFractionalDigits(3);
		return FText::Format(NSLOCTEXT("DelayActionLocalGraph", "DelayActionTimeFmt", "Delay ({0} seconds left)"), FText::AsNumber(TimeRemaining, &DelayTimeFormatOptions)).ToString();
	}
#endif
};



void UKettisLogicDriverBPLibrary::DelayStateMachine(USMStateInstance* NodeInstance, float Duration,
                                               FLatentActionInfo LatentInfo)
{
	
	if (UWorld* World = GEngine->GetWorldFromContextObject(NodeInstance, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FDelayLocalAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FDelayLocalAction(Duration, LatentInfo, NodeInstance));
		}
	}
	
}

bool UKettisLogicDriverBPLibrary::SwitchOnActive(USMStateInstance* NodeInstance)
{
	if (!NodeInstance)
	{
		return false;
	}
	return 	NodeInstance->IsActive();
}

#if WITH_EDITOR
#include "EditorUtilitySubsystem.h"
#include "Editor.h"
#include "Editor/EditorEngine.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "Blueprint/UserWidget.h"

#endif

class UEditorUtilitySubsystem;

UObject* UKettisLogicDriverBPLibrary::SpawnAndRegisterTab(class UUserWidgetBlueprint* Widget)
{
	#if WITH_EDITOR
	if (Cast<UEditorUtilityWidgetBlueprint>(Widget) && GEditor)
	{
		return GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>()->SpawnAndRegisterTab(Cast<UEditorUtilityWidgetBlueprint>(Widget));
	}
	

	#endif
	return nullptr;
}


