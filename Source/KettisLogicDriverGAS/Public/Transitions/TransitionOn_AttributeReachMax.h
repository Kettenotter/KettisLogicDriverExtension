// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TransitionExtensionBase.h"
#include "TransitionOn_AttributeReachMax.generated.h"

/**
 * Takes the Transition once the Attribute reaches the value of the max Attribute.
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOn_AttributeReachMax : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()
	
public:

	UTransitionOn_AttributeReachMax(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayAttribute TestAttribute;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayAttribute MaxAttribute;

protected:
	

	FDelegateHandle DelegateHandle;
	FDelegateHandle DelegateHandleMax;

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;

	virtual bool TestCondition() override;
	
	virtual void AttributeChanged(const FOnAttributeChangeData& Data) {TriggerUpdate();}

#if WITH_EDITOR

	virtual bool ValidColor() override {return TestAttribute.IsValid() && MaxAttribute.IsValid();};
	
#endif
};
