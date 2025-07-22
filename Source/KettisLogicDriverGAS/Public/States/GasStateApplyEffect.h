// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GasStateBase.h"
#include "GasStateApplyEffect.generated.h"

/**
 * 
 */

UENUM(Blueprintable, BlueprintType)
enum EEffectTargetOption  :uint8
{
	Self UMETA(ToolTip = "The Context of the SM"), 
	CustomTarget UMETA(ToolTip = "The Custom Input Parameter"),
	TransitionSource UMETA(ToolTip = "Set from the Transition entered the State. The Actor who applied an effect to us or the Actor set in the Gameplay Event Instigator")
};
UCLASS()
class KETTISLOGICDRIVERGAS_API UGasStateApplyEffect : public UGasStateBase
{
	GENERATED_BODY()

protected:
	virtual void OnPreCompileValidate_Implementation(USMCompilerLog* CompilerLog) const override;

	virtual void ConstructionScript_Implementation() override;

public:
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Default")
	TSubclassOf<UGameplayEffect> Effect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Default")
	TEnumAsByte<EEffectTargetOption> TargetMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Default")
	TObjectPtr<AActor> CustomTarget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Default")
	uint8 bRemoveOnEnd:1;

	
	
	/**
	 * The Chached Target ASC and the handle are used to remove the Effect when the state ends.
	 */
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> CachedTargetASC;
	
	FActiveGameplayEffectHandle Handle;
	
	virtual void OnStateBegin_Implementation() override;

	virtual void OnStateEnd_Implementation() override;
	

	virtual void UpdateLog(FString& Text) override;

};

