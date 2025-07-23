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
	UFUNCTION(BlueprintCallable, Category="LogicDriver|Extension|Tags", meta=(AdvancedDisplay="bShouldReplicate", AutoCreateRefTerm = "GameplayTags"))
	static bool AddLooseGameplayTags_StateMachine(AActor* Actor, const FGameplayTagContainer& GameplayTags, bool bShouldReplicate=false);

	/** Removes the Tags from the GAS Component if available, if not removes it from the virtual Tag Container used by the State Machine. */
	UFUNCTION(BlueprintCallable, Category="LogicDriver|Extension|Tags", meta=(AdvancedDisplay="bShouldReplicate", AutoCreateRefTerm = "GameplayTags"))
	static bool RemoveLooseGameplayTags_StateMachine(AActor* Actor, const FGameplayTagContainer& GameplayTags, bool bShouldReplicate=false);

	/** Add/Remove the Tag from the GAS Component if available, if not Add/Remove it from the virtual Tag Container used by the State Machine. */
	UFUNCTION(BlueprintCallable, Category="LogicDriver|Extension|Tags", meta=(AdvancedDisplay="bShouldReplicate", AutoCreateRefTerm = "GameplayTag"))
	static bool AddOrRemoveGameplayTag_StateMachine(AActor* Actor, const FGameplayTag& GameplayTag, bool bRemoveTag, bool bShouldReplicate=false);
	
	/** Checks if the Tag is present on the GAS Component or the State Machine */
	UFUNCTION(BlueprintCallable, BlueprintPure,  Category="LogicDriver|Extension|Tags", meta=(AutoCreateRefTerm = "Tag"))
	static bool HasGameplayTag_StateMachine(AActor* Actor, const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="LogicDriver|Extension|Tags")
	static FGameplayTagContainer GetTags_StateMachine(AActor* Actor);

	//__ Inside State Machine __//
	
	UFUNCTION(BlueprintCallable, Category= "LogicDriver|Extension|Utility" ,
	BlueprintPure, meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", AutoCreateRefTerm = "Tag", CompactNodeTitle = "Tag?"))
	static bool HasGameplayTag(const TScriptInterface<ISMInstanceInterface> NodeInstance, const FGameplayTag& Tag);
	
};


