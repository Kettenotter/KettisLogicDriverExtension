// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TransitionExtensionBase.h"
#include "Transition_Delay.generated.h"

/**
 * Will automatically try to take the transition after the Delay.
 */
UCLASS(DisplayName="Delay")
class KETTISLOGICDRIVERGAS_API UTransition_Delay : public UTransitionExtensionBase
{
	GENERATED_BODY()
public:

	UTransition_Delay(const FObjectInitializer& ObjectInitializer);


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Delay", meta=(Delta = 0.01, UIMin = 0))
	float Delay = 1;

	/**
	 * If the elapsed time of the delay is greater than the NewTime will turn the transition to true instantly.
	 * 
	 * @param NewTime The new time the delay will have.
	 * @param bRestart Will keep the elapsed time on false but restart with the full time if true.
	 */
	UFUNCTION(BlueprintCallable)
	void SetNewDelayTime(float NewTime, bool bRestart = false);

	/**
	 * Restart the delay.
	 * If the delay already finished will change the internal state to false and restart.
	 */
	UFUNCTION(BlueprintCallable)
	void RestartDelay();

	/**
	 * When this delay is active returns the remaining time.
	 * @return 
	 */
	UFUNCTION(BlueprintCallable)
	float GetRemainingTime() const;
	
protected:
	FTimerHandle DelayHandle;
	
	virtual void ConstructionScript_Implementation() override;
	
	virtual bool CanEnterTransition_Implementation() const override{return bCanEnterTransition;};

	virtual void OnTransitionInitialized_Implementation() override;

	virtual void OnTransitionEntered_Implementation() override;
	virtual void OnTransitionShutdown_Implementation() override;
	
	void DelayFinished();

	virtual void Serialize(FArchive& Ar) override;

#if WITH_EDITOR

	virtual bool ValidColor() override {return Delay > 0.0;};
#endif
	
	
};
