// Fill out your copyright notice in the Description page of Project Settings.

#include "SMStateMachineInstance.h"
#include "KettisLogicDriverBPLibrary.h"

#include "GameFramework/Character.h"

AActor* UKettisLogicDriverBPLibrary::GetContextAsActor(const TScriptInterface<ISMInstanceInterface> NodeInstance)
{
	
	return Cast<AActor>(GetContextFromObject(NodeInstance.GetObject()));
	
}


bool UKettisLogicDriverBPLibrary::GetContextAsActorChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, AActor*& Actor)
{

	Actor = Cast<AActor>(GetContextFromObject(NodeInstance.GetObject()));
	
	return Actor != nullptr;
}

ACharacter* UKettisLogicDriverBPLibrary::GetContextAsCharacter(const TScriptInterface<ISMInstanceInterface> NodeInstance)
{
	return Cast<ACharacter>(GetContextFromObject(NodeInstance.GetObject()));
}

bool UKettisLogicDriverBPLibrary::GetContextAsCharacterChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, ACharacter*& Character)
{
	Character = Cast<ACharacter>(GetContextFromObject(NodeInstance.GetObject()));
	
	return Character != nullptr;
	
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
	
	return CastContext != nullptr;
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
