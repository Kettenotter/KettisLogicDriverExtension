// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "TransitionExtensionBase.h"
#include "Nodes/Transitions/SMTransitionInstance.h"
#include "TransitionGameplayAbilityGeneric.generated.h"

struct FOnAttributeChangeData;
/**
 * 
 */

UCLASS()
class UTransitionOnGameplayEvent : public UTransitionExtensionBase
{
	GENERATED_BODY()
public:
	
	UTransitionOnGameplayEvent(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ability")
	FGameplayTag Tag;

	/**
	 * If OnlyMatchExact = false it will trigger for nested tags
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ability")
	bool OnlyMatchExact = false;

	FDelegateHandle MyHandle;

protected:
	virtual void ConstructionScript_Implementation() override;

	virtual bool CanEnterTransition_Implementation() const override;
	
	virtual void OnTransitionInitialized_Implementation() override;
	
	virtual void OnTransitionShutdown_Implementation() override;

	virtual void GameplayEventCallback(const FGameplayEventData* Payload);

	virtual void GameplayEventContainerCallback(FGameplayTag MatchingTag, const FGameplayEventData* Payload);
};

UCLASS()
class UTransitionOnGameplayEventCachedData : public UTransitionOnGameplayEvent
{
	GENERATED_BODY()
	
public:
	/**
	 * Stores the last Event Data Payload so it can be used by connected states.
	 * Its quite big so its optional. Perhaps it can be improved?
	 */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category="Ability")
	FGameplayEventData EventData;


protected:
	virtual void GameplayEventCallback(const FGameplayEventData* Payload) override;
	virtual void GameplayEventContainerCallback(FGameplayTag MatchingTag, const FGameplayEventData* Payload) override;
};

UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOnGameplayTag : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()

public:

	UTransitionOnGameplayTag(const FObjectInitializer& ObjectInitializer);

protected:

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;

	virtual bool TestCondition() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayTag Tag;

	/*UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, Category="Transition Custom")
	AActor* OptionalTarget;*/

	virtual void ConstructionScript_Implementation() override;


protected:
	
	FDelegateHandle DelegateHandle;

	virtual void TagChanged(const FGameplayTag CallbackTag, int32 NewCount){TriggerUpdate();}
	
};

UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOnGameplayTagQuery : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()

public:

	UTransitionOnGameplayTagQuery(const FObjectInitializer& ObjectInitializer);

protected:

	/*
	 * !! Important !! We bind the delegates in this case before the test.
	 * Because they also build a tag map which is needed to test.
	 *
	 * 
	 */
	
	virtual void PostBeginInitialize(USMStateInstance_Base* StateInstance) override;

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;
	
	virtual bool TestCondition() override;

	virtual void ConstructionScript_Implementation() override;

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayTagQuery TagQuery;
	
	/*UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, Category="Transition Custom")
	AActor* OptionalTarget;*/



protected:
	
	/** This will update the tags in the TargetTags container to reflect that tags that are on the target ASC. */
	void UpdateTargetTags(const FGameplayTag Tag, int32 NewCount);

	/** This is the tag container of the targets the target ASC currently has.
		NOTE: This will only contain the tags referenced in the TagQuery. */
	FGameplayTagContainer TargetTags;

	/** This is the handles to the tag changed delegate for each gameplay tag in the TagQuery. */
	TMap<FGameplayTag, FDelegateHandle> TagHandleMap;
	
};


UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOnAttributeReachZero : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()

public:

	UTransitionOnAttributeReachZero(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayAttribute Attribute;

protected:
	

	FDelegateHandle DelegateHandle;

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;

	virtual bool TestCondition() override;
	
	virtual void AttributeChanged(const FOnAttributeChangeData& Data) {TriggerUpdate();}
	
};


