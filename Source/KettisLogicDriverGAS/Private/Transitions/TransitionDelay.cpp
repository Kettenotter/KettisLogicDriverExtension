// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/TransitionDelay.h"

#include "ISMEditorGraphNodeInterface.h"

void UTransitionDelay::SetNewDelayTime(float NewTime, bool bRestart)
{
	Delay = NewTime; //Always set the new time
	
	if (!IsInitialized())
	{
		return;
	}

	bCanEnterTransition = false;
	
	if (DelayHandle.IsValid())
	{
		if (!bRestart)
		{
			NewTime = NewTime - GetWorld()->GetTimerManager().GetTimerElapsed(DelayHandle);
		}
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);

	}

	if (NewTime < 0.0f)
	{
		DelayFinished();
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransitionDelay::DelayFinished), NewTime, false);

	}
}

void UTransitionDelay::RestartDelay()
{
	if (!IsInitialized())
	{
		return;
	}

	bCanEnterTransition = false;
	
	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);

	}
	
	GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransitionDelay::DelayFinished), Delay, false);
}

float UTransitionDelay::GetRemainingTime() const
{
	if (DelayHandle.IsValid())
	{
		return GetWorld()->GetTimerManager().GetTimerRemaining(DelayHandle);
	}
	return 0;
}

void UTransitionDelay::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	if (!IsEditorExecution())
	{
		return;
	}


	FString Name = TEXT("Delay ") + FString::SanitizeFloat(Delay, 0) + "s";
	SetTransitionName(Name);	
#endif
	
}

void UTransitionDelay::OnTransitionInitialized_Implementation()
{
	Super::OnTransitionInitialized_Implementation();

	bCanEnterTransition = false;
	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);

	}
	GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransitionDelay::DelayFinished), Delay, false);
}

void UTransitionDelay::OnTransitionEntered_Implementation()
{
	Super::OnTransitionShutdown_Implementation();
	
	bCanEnterTransition = false;
	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);

	}
}

void UTransitionDelay::OnTransitionShutdown_Implementation()
{
	Super::OnTransitionShutdown_Implementation();
	
	bCanEnterTransition = false;
	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);
		
	}
}

void UTransitionDelay::DelayFinished()
{
	DelayHandle.Invalidate();
	bCanEnterTransition = true;
	EvaluateFromManuallyBoundEvent();
	
}

void UTransitionDelay::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	return;

	RETURN_IF_LOADING_VERSION_LOWER(1)
	Ar << Delay;
}
