// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/Transition_Delay.h"

#include "ISMEditorGraphNodeInterface.h"



UTransition_Delay::UTransition_Delay(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("Delay"));

}

void UTransition_Delay::SetNewDelayTime(float NewTime, bool bRestart)
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
		GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransition_Delay::DelayFinished), NewTime, false);

	}
}

void UTransition_Delay::RestartDelay()
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
	
	GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransition_Delay::DelayFinished), Delay, false);
}

float UTransition_Delay::GetRemainingTime() const
{
	if (DelayHandle.IsValid())
	{
		return GetWorld()->GetTimerManager().GetTimerRemaining(DelayHandle);
	}
	return 0;
}

void UTransition_Delay::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	if (!IsEditorExecution())
	{
		return;
	}
	
	SetEditorColor(true, !ValidColor());

	FString Name = TEXT("Delay ") + FString::SanitizeFloat(Delay, 0) + "s";
	SetTransitionName(Name);	
#endif
	
}

void UTransition_Delay::OnTransitionInitialized_Implementation()
{
	Super::OnTransitionInitialized_Implementation();

	bCanEnterTransition = false;
	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);

	}
	GetWorld()->GetTimerManager().SetTimer(DelayHandle, FTimerDelegate::CreateUObject(this, &UTransition_Delay::DelayFinished), Delay, false);
}

void UTransition_Delay::OnTransitionEntered_Implementation()
{
	Super::OnTransitionShutdown_Implementation();
	
	bCanEnterTransition = false;
	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);

	}
}

void UTransition_Delay::OnTransitionShutdown_Implementation()
{
	Super::OnTransitionShutdown_Implementation();
	
	bCanEnterTransition = false;
	if (DelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DelayHandle);
		
	}
}

void UTransition_Delay::DelayFinished()
{
	DelayHandle.Invalidate();
	bCanEnterTransition = true;
	EvaluateFromManuallyBoundEvent();
	
}

void UTransition_Delay::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	return;

	RETURN_IF_LOADING_VERSION_LOWER(1)
	Ar << Delay;
}
