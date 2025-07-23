// Fill out your copyright notice in the Description page of Project Settings.

#include "Transitions/TransitionExtensionBase.h"

#include "SMStateInstance.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemInterface.h"
#include "GasSmCacheSubsystem.h"
#include "ISMEditorGraphNodeInterface.h"
#include "SMUtils.h"


UTransitionExtensionBase::UTransitionExtensionBase(const FObjectInitializer& ObjectInitializer)
{
	SetCanEvaluate(false);
}

void UTransitionExtensionBase::Serialize(FArchive& Ar)
{
#if WITH_EDITOR
	
	if (Ar.IsSaving() && SerializeVersion < 200)
	{
		SerializeVersion = LOGIC_DRIVER_GAS_CUSTOM_SERIALIZE ? GSerializeVersion_Transition : 0;
	}
#endif
	
	Super::Serialize(Ar);
	
}

bool UTransitionExtensionBase::SetToTrueAndEvaluate()
{
	bool DidSetItToTrue = false;
	
	if (!bCanEnterTransition)
	{
		DidSetItToTrue = true;
		bCanEnterTransition = true;

	}
	const bool Result = EvaluateFromManuallyBoundEvent();

	if (DidSetItToTrue)
	{
		bCanEnterTransition = false;
	}

	return Result;
	
}

void UTransitionExtensionBase::SetEditorIconFromDataTable(FName RowName)
{
#if WITH_EDITOR
	if (!NodeIconDataTable)
	{
		static ConstructorHelpers::FObjectFinder<UDataTable> BarFillObj(TEXT("/Script/Engine.DataTable'/KettisLogicDriverExtension/DT_NodeIcons.DT_NodeIcons'"));
		
		NodeIconDataTable = BarFillObj.Object;
	}
	
	if (NodeIconDataTable)
	{
		FString String;

		if (FNodeIconDataTableRow* RowFound = NodeIconDataTable->FindRow<FNodeIconDataTableRow>(RowName, String))
		{
			bDisplayCustomIcon = true;
			NodeIcon  = RowFound->NodeIcon;
			NodeIconSize = RowFound->IconSize;
		}
	}

#endif
	
		
	
}



void UTransitionExtensionBase::SetEditorColor(bool Status, bool Invalid)
{
#if WITH_EDITOR

	if (Invalid)
	{
		//NodeIconTintColor = FLinearColor::LerpUsingHSV(NodeIconTintColor, FLinearColor(0,0,0), 0.5);

		NodeIconTintColor.A = 0.2;
		return;
	}
	if (Status)
	{
		NodeIconTintColor = FLinearColor(0.015236, 1, 0);
	}
	else
	{
		NodeIconTintColor = FLinearColor(1, 0, 0.04);
	}
#endif
}

UAbilitySystemComponent* UTransitionExtensionBase::GetAbilitySystemComponent() const
{
	const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(GetContext());
	if (ASI)
	{
		return ASI->GetAbilitySystemComponent();
	}
	return nullptr;
}

FGameplayTagCountContainer* UTransitionExtensionBase::GetGameplayTagCountContainer() const
{
	
	if (UObject* Context = GetContext())
	{
		if (UGasSmCacheSubsystem* Sub = UGasSmCacheSubsystem::Get(Context))
		{
			return &Sub->VirtualTagContainers.FindOrAdd(Context).GameplayTagCountContainer;
			
		}
	}
	return nullptr;
}

int32 UTransitionExtensionBase::GetGameplayTagCount(FGameplayTag Tag) const
{
	if (const UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		return AbilitySystemComponent->GetGameplayTagCount(Tag);
		
	}
	else
	{
		if (FGameplayTagCountContainer* GameplayTagCountContainer = GetGameplayTagCountContainer())
		{
			return GameplayTagCountContainer->GetTagCount(Tag);
		}
	}

	return -1;
}

#if WITH_EDITOR
void UTransitionExtensionBase::SetTransitionName(FString Name)
{

	
	InternalName = Name;

	UTransitionExtensionBase* OwnerInstance = Cast<UTransitionExtensionBase>(GetStackOwnerInstance());
	
	TArray<USMTransitionInstance*> Instances;
	GetAllTransitionStackInstances(Instances);

	FString CombinedString;

	if (OwnerInstance)
	{
		CombinedString = OwnerInstance->InternalName;

	}
	
	for (auto* Instance: Instances)
	{
		if (auto* Base = Cast<UTransitionExtensionBase>(Instance))
		{
			if (!Base->InternalName.IsEmpty())
			{
				CombinedString += " + " + Base->InternalName;
			}
			/*if (CombinedString.IsEmpty())
			{
				CombinedString = Base->InternalName;
			}
			else
			{
				
			}*/
			
			
		}
		
		
	}
	FText Text;

	if (!GetOwningEditorGraphNode())
	{
		return;
	}
	GetOwningEditorGraphNode()->SetNodeName(CombinedString, Text);
	return;
	
	InternalNames.SetNum(FMath::Min(GetTransitionIndexInStack(this) + 1, InternalNames.Num()), false);
	
	if (!IsEditorExecution())
	{
		return;
	}
	

	if (GetTransitionStackCount() <= 1)
	{
		GetOwningEditorGraphNode()->SetNodeName(Name, Text);
		return;
	}
	
	
	InternalNames[GetTransitionIndexInStack(this)] = Name;

	

	
	
}
#endif

UTransitionExtensionDelegateBinding::UTransitionExtensionDelegateBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), bInvertCondition(false), bDelegateWasBound(false)
{
	//SetCanEvaluate(false);
}

void UTransitionExtensionDelegateBinding::PostBeginInitialize(USMStateInstance_Base* StateInstance)
{
	if (IsInitialized())
	{
		TriggerUpdate();
	}

	//We will never bind the Delegates if its already taken.
	if (IsInitialized() && !bDelegateWasBound)
	{
		BindDelegates();
	}
	
}

void UTransitionExtensionDelegateBinding::BindDelegates()
{
	bDelegateWasBound = true;
}

void UTransitionExtensionDelegateBinding::ClearDelegates()
{
	bDelegateWasBound = false;
}

void UTransitionExtensionDelegateBinding::TriggerUpdate(bool bAllowManualTaking)
{
	if (bBlockTriggerUpdate)
	{
		return;
	}
	bCanEnterTransition = bInvertCondition ? !TestCondition() : TestCondition();
	if (bCanEnterTransition && bIsEventBased && bAllowManualTaking /*&& GetPreviousStateInstance() && GetPreviousStateInstance()->HasUpdated()*/)
	{
		EvaluateFromManuallyBoundEvent();
	}
}

bool UTransitionExtensionDelegateBinding::TestCondition()
{
	return false;
}



void UTransitionExtensionDelegateBinding::OnTransitionInitialized_Implementation()
{
	Super::OnTransitionInitialized_Implementation();

	

	if (bIsEventBased)
	{
		if (!GetPreviousStateInstance())
		{
			return;
		}
		GetPreviousStateInstance()->OnPostStateBeginEvent.AddUniqueDynamic(this, &UTransitionExtensionDelegateBinding::PostBeginInitialize);
	}
	else
	{
		PostBeginInitialize(nullptr);
	}
	

	//TriggerUpdate(false);
}


void UTransitionExtensionDelegateBinding::OnTransitionShutdown_Implementation()
{
	Super::OnTransitionShutdown_Implementation();

	ClearDelegates();
	bDelegateWasBound = false;
	
	GetPreviousStateInstance()->OnPostStateBeginEvent.RemoveDynamic(this, &UTransitionExtensionDelegateBinding::PostBeginInitialize);

	bCanEnterTransition = false;
}

void UTransitionExtensionDelegateBinding::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	SetEditorColor(!bInvertCondition, !ValidColor());
#endif
	
}

void UTransitionExtensionDelegateBinding::Serialize(FArchive& Ar)
{
	
	
	Super::Serialize(Ar);
	
	return;
	RETURN_IF_LOADING_VERSION_LOWER(1)

	FArchive_Serialize_BitfieldBool(Ar, bInvertCondition);
	FArchive_Serialize_BitfieldBool(Ar, bIsEventBased);

	/*uint8 PackedBits = 0;
	if (Ar.IsSaving())
	{
		SerializeBooleans(true, PackedBits);
		Ar << PackedBits;

	}
	else if (Ar.IsLoading())
	{
		Ar << PackedBits;
		SerializeBooleans(false, PackedBits);

	}*/
	
}

void UTransitionExtensionDelegateBinding::SerializeBooleans(bool bIsSaving, uint8& PackedBits)
{
	// Manually pack bits into a byte
	
	if (bIsSaving)
	{
		PackedBits |= bInvertCondition << 0;
		PackedBits |= bIsEventBased << 1;
	}
	else
	{
		bInvertCondition = (PackedBits & (1 << 0)) != 0;
		bIsEventBased = (PackedBits & (1 << 1)) != 0;
		
	}
}
