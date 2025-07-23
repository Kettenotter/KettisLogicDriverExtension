// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/Transition_Cooldown.h"

#include "ISMEditorGraphNodeInterface.h"


float UTransition_Cooldown::GetRemainingCooldownTime() const
{
	if (DelayHandle.IsValid())
	{
		return GetWorld()->GetTimerManager().GetTimerRemaining(DelayHandle);
	}
	return 0;
}

UTransition_Cooldown::UTransition_Cooldown(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	bCanEnterTransition = true;
	SetEditorIconFromDataTable("Cooldown");
}

void UTransition_Cooldown::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	if (!IsEditorExecution())
	{
		return;
	}


	FString Name = TEXT("Cooldown ") + FString::SanitizeFloat(Cooldown, 0) + "s";
	SetTransitionName(Name);
	
#endif
	
}

void UTransition_Cooldown::OnRootStateMachineStop_Implementation()
{
	Super::OnRootStateMachineStop_Implementation();

	bCanEnterTransition = true;

	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);
	}
}

void UTransition_Cooldown::OnTransitionShutdown_Implementation()
{
	Super::OnTransitionShutdown_Implementation();

	
}

void UTransition_Cooldown::OnTransitionEntered_Implementation()
{
	Super::OnTransitionEntered_Implementation();

	GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransition_Cooldown::DelayFinished), Cooldown, false);

	bCanEnterTransition = false;
}

void UTransition_Cooldown::DelayFinished()
{
	bCanEnterTransition = true;
	DelayHandle.Invalidate();
	EvaluateFromManuallyBoundEvent();
}

void UTransition_Cooldown::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	
	return;

	RETURN_IF_LOADING_VERSION_LOWER(1)
	Ar << Cooldown;
}
