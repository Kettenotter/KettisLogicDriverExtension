// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/TransitionCooldown.h"

#include "ISMEditorGraphNodeInterface.h"


float UTransitionCooldown::GetRemainingCooldownTime() const
{
	if (DelayHandle.IsValid())
	{
		return GetWorld()->GetTimerManager().GetTimerRemaining(DelayHandle);
	}
	return 0;
}

UTransitionCooldown::UTransitionCooldown(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	bCanEnterTransition = true;
}

void UTransitionCooldown::ConstructionScript_Implementation()
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

void UTransitionCooldown::OnRootStateMachineStop_Implementation()
{
	Super::OnRootStateMachineStop_Implementation();

	bCanEnterTransition = true;

	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);
	}
}

void UTransitionCooldown::OnTransitionShutdown_Implementation()
{
	Super::OnTransitionShutdown_Implementation();

	
}

void UTransitionCooldown::OnTransitionEntered_Implementation()
{
	Super::OnTransitionEntered_Implementation();

	GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransitionCooldown::DelayFinished), Cooldown, false);

	bCanEnterTransition = false;
}

void UTransitionCooldown::DelayFinished()
{
	bCanEnterTransition = true;
	DelayHandle.Invalidate();
	EvaluateFromManuallyBoundEvent();
}

void UTransitionCooldown::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	
	return;

	RETURN_IF_LOADING_VERSION_LOWER(1)
	Ar << Cooldown;
}
