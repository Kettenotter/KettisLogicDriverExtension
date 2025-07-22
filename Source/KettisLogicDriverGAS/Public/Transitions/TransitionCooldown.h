// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TransitionExtensionBase.h"
#include "TransitionCooldown.generated.h"

/**
 * Will instantly be set to true. But can only be taken again after the cooldown has finished.
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionCooldown : public UTransitionExtensionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Cooldown", meta=(Delta = 0.01, UIMin = 0))
	float Cooldown = 1;

	UFUNCTION(BlueprintCallable)
	float GetRemainingCooldownTime() const;
	
	UTransitionCooldown(const FObjectInitializer& ObjectInitializer);
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
