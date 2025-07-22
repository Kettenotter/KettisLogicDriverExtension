// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LogicDriverGasBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API ULogicDriverGasBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	/** Adds the Tags to the GAS Component if available, if not adds it to the virtual Tag Container used by the State Machine. */
	UFUNCTION(BlueprintCallable, Category="LogicDriver|Extension|Tags")
	static bool AddLooseGameplayTags_StateMachine(AActor* Actor, const FGameplayTagContainer& GameplayTags, bool bShouldReplicate=false);

	/** Removes the Tags from the GAS Component if available, if not removes it from the virtual Tag Container used by the State Machine. */
	UFUNCTION(BlueprintCallable, Category="LogicDriver|Extension|Tags")
	static bool RemoveLooseGameplayTags_StateMachine(AActor* Actor, const FGameplayTagContainer& GameplayTags, bool bShouldReplicate=false);
	
	/** Checks if the Tag is present on the GAS Component or the State Machine */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="LogicDriver|Extension|Tags")
	static bool HasGameplayTag_StateMachine(AActor* Actor, const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="LogicDriver|Extension|Tags")
	static FGameplayTagContainer GetTags_StateMachine(AActor* Actor);
	
};
