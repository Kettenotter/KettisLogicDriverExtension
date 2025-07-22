// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TransitionExtensionBase.h"
#include "TransitionOnAttributeReachMax.generated.h"

/**
 * 
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOnAttributeReachMax : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()
	
public:

	UTransitionOnAttributeReachMax(const FObjectInitializer& ObjectInitializer);

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
};
