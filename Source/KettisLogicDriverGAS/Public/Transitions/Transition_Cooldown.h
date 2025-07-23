// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TransitionExtensionBase.h"
#include "Transition_Cooldown.generated.h"

/**
 * Will instantly be set to true. But can only be taken again after the cooldown has finished.
 */
UCLASS(DisplayName="Cooldown")
class KETTISLOGICDRIVERGAS_API UTransition_Cooldown : public UTransitionExtensionBase
{
	GENERATED_BODY()
	
public:
	UTransition_Cooldown(const FObjectInitializer& ObjectInitializer);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Cooldown", meta=(Delta = 0.01, UIMin = 0))
	float Cooldown = 1;

	UFUNCTION(BlueprintCallable)
	float GetRemainingCooldownTime() const;
	
protected:
	
	virtual void ConstructionScript_Implementation() override;

	FTimerHandle DelayHandle;
	
	virtual bool CanEnterTransition_Implementation() const override{return bCanEnterTransition;};
	
	virtual void OnRootStateMachineStop_Implementation() override;

	virtual void OnTransitionShutdown_Implementation() override;

	virtual void OnTransitionEntered_Implementation() override;
	
	void DelayFinished();

	//UFUNCTION(BlueprintCallable)
	//void ClearCooldown
	virtual void Serialize(FArchive& Ar) override;
};
