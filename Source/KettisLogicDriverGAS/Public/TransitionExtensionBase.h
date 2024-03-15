// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMTransitionInstance.h"
#include "AbilitySystemComponent.h"
#include "TransitionExtensionBase.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FNodeIconDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* NodeIcon = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D IconSize = FVector2d(30, 30);
	
};


UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionExtensionBase : public USMTransitionInstance
{
	GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	UDataTable* NodeIconDataTable;
#endif


	UTransitionExtensionBase(const FObjectInitializer& ObjectInitializer);

protected:

	
	void SetEditorIconFromDataTable(FName RowName);

	
	void SetEditorColor(bool Status, bool Invalid = false);
};

UCLASS(meta=(PrioritizeCategories="Ability"), AutoExpandCategories="Ability", Category = "GameplayAbility")
class KETTISLOGICDRIVERGAS_API UTransitionExtensionDelegateBinding : public UTransitionExtensionBase
{
	GENERATED_BODY()

public:
	
	UTransitionExtensionDelegateBinding(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	bool bInvertCondition;

	/*
	 * If enabled will use event based system. Will run initialize logic after the begin play of the previous node.
	 * If disabled will run the logic in the initialize phase and never call "take manually bound transition".
	 * (This is mostly for easy debugging to make sure everything works)
	 * 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	bool bIsEventBased = true;


protected:
	
	bool bStatus;

	bool bDelegateWasBound;
	
	/*
	 * Called after the Begin play of the previous State.
	 */
	UFUNCTION()
	virtual void PostBeginInitialize(USMStateInstance_Base* StateInstance);

	/*
	 * Binds the delegates. Is separate from post initialize because they only need to be bound if the transition was not already taken.
	 */
	UFUNCTION()
	virtual void BindDelegates();

	virtual void ClearDelegates();

	/*
	 * Updates the bStatus and will take the transition if possible.
	 * Calls TestCondition() and will use bInvertCondition.
	 * 
	 * 1. Called on PostBeginInitialize
	 * 2. Every time the delegate is triggered
	 */
	UFUNCTION()
	void TriggerUpdate(bool bAllowManualTaking = true);

	/*
	 * Test the condition. For example if the gameplay tag is present.
	 */
	UFUNCTION()
	virtual bool TestCondition();

	UAbilitySystemComponent* GetAbilitySystemComponent() const;
	
	virtual bool CanEnterTransition_Implementation() const override {return bStatus;}
	
	virtual void OnTransitionInitialized_Implementation() override;

	
	virtual void OnTransitionShutdown_Implementation() override;

	virtual void ConstructionScript_Implementation() override;
	
};
