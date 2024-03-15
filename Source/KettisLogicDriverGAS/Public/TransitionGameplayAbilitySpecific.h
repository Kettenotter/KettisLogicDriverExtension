// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "TransitionExtensionBase.h"
#include "UObject/Object.h"
#include "TransitionGameplayAbilitySpecific.generated.h"

/**
 * 
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOnCanPayMana : public UTransitionExtensionDelegateBinding
{
	
	GENERATED_BODY()

protected:
	virtual void OnPreCompileValidate_Implementation(USMCompilerLog* CompilerLog) const override;

public:
	
	UTransitionOnCanPayMana(const FObjectInitializer& ObjectInitializer);
	
#if WITH_KETTENOTTER_SPECIFIC
	
protected:
	
	FDelegateHandle DelegateHandle;

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;

	virtual bool TestCondition() override;
	
	virtual void AttributeChanged(const FOnAttributeChangeData& Data) {TriggerUpdate();}

#endif

};

