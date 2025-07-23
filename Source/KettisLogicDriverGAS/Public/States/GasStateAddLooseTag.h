// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GasStateBase.h"
#include "GasStateAddLooseTag.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Add Tag", Category = "GAS")
class KETTISLOGICDRIVERGAS_API UGasStateAddLooseTag : public UGasStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Default")
	FGameplayTagContainer TagsToAdd;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
	uint8 bRemoveOnExit:1 = true;

	/**
	 * Either have the loose gameplay tags +1 and -1 or set them directly to 1 or 0.
	 * For example if different systems add and remove tags having it not Additve can mess things up.
	 * But if you want to be sure that it's always set to the amount non additve is fine.
	 * 
	 * For more controll I would always recommend to put the tags on infinite effects so that stacking and removing is more reliable.
	 * But for simple things this is fine.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
	uint8 bAdditive:1 = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
	uint8 bReplicate:1 = true;

protected:
	
	
	
	virtual void OnStateBegin_Implementation() override;
	virtual void OnStateEnd_Implementation() override;

	virtual void Serialize(FArchive& Ar) override;
	
};
