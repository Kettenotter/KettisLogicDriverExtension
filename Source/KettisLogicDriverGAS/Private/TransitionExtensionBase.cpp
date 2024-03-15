// Fill out your copyright notice in the Description page of Project Settings.

#include "TransitionExtensionBase.h"

#include "SMStateInstance.h"
#include "AbilitySystemGlobals.h"


UTransitionExtensionBase::UTransitionExtensionBase(const FObjectInitializer& ObjectInitializer)
{
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

UTransitionExtensionDelegateBinding::UTransitionExtensionDelegateBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), bInvertCondition(false), bDelegateWasBound(false)
{
	//SetCanEvaluate(false);

	bStatus = false;
}

void UTransitionExtensionDelegateBinding::PostBeginInitialize(USMStateInstance_Base* StateInstance)
{
	if (IsInitialized())
	{
		TriggerUpdate();
	}

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
	bStatus = bInvertCondition ? !TestCondition() : TestCondition();
	if (bStatus && bIsEventBased && bAllowManualTaking /*&& GetPreviousStateInstance() && GetPreviousStateInstance()->HasUpdated()*/)
	{
		EvaluateFromManuallyBoundEvent();
	}
}

bool UTransitionExtensionDelegateBinding::TestCondition()
{
	return false;
}

UAbilitySystemComponent* UTransitionExtensionDelegateBinding::GetAbilitySystemComponent() const
{
	return UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false);
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

	bStatus = false;
}

void UTransitionExtensionDelegateBinding::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	SetEditorColor(!bInvertCondition);
#endif
	
}