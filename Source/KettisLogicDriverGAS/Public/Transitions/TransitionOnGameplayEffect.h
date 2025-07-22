// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "TransitionExtensionBase.h"
#include "TransitionOnGameplayEffect.generated.h"


UENUM()
enum class EEffectTransitionType : uint8
{
	AppliedToSelf UMETA(ToolTip = "Triggers when another AbilitySystemComponent applies an Effect to self"),
	AppliedFromSelf UMETA(ToolTip = "Triggers when this AbilitySystemComponent applies an Effect to another ASC"),
};

USTRUCT(BlueprintType)
struct FTransitionOnGameplayEffectSparseData
{
	GENERATED_BODY()
 
	FTransitionOnGameplayEffectSparseData()
	: EffectTagFilter(FGameplayTagQuery::EmptyQuery)
	{ }

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Ability")
	FGameplayTag EffectTag;
	
	/**
	 * The Tags on the Effect Asset which need to be matched.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Ability")
	FGameplayTagQuery EffectTagFilter;

	/**
	* The Tags which need to be present on Actor who applied the effect to us. 
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Ability")
	FGameplayTagQuery SourceTagFilter;

	/**
	 * Usually the Context of the SM.
	 * 
	 * Example: You only want to counter attacks when you are in a frenzy state. So you check if the tag is present.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Ability")
	FGameplayTagQuery TargetTagFilter;

	/**
	 * In most cases I would recommend to use the EffectTagQuery instead!
	 * For example on your MeleeDamageEffect just put a "Damage.Melee" Tag and set it to be matched on the EffectTagQuery.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Ability")
	TSubclassOf<UGameplayEffect> EffectClassFilter;

	UPROPERTY(EditAnywhere, Category= "Ability", meta=(BaseStruct="/Script/KettisLogicDriverGAS.ExtraFilterOptionsBase"))
	TArray<FInstancedStruct> FilterOptions;

	friend bool operator==(const FTransitionOnGameplayEffectSparseData& Lhs,
		const FTransitionOnGameplayEffectSparseData& RHS)
	{
		return Lhs.EffectTag == RHS.EffectTag
			&& Lhs.EffectTagFilter == RHS.EffectTagFilter
			&& Lhs.SourceTagFilter == RHS.SourceTagFilter
			&& Lhs.TargetTagFilter == RHS.TargetTagFilter
			&& Lhs.EffectClassFilter == RHS.EffectClassFilter
			&& Lhs.FilterOptions == RHS.FilterOptions;
	}

	friend bool operator!=(const FTransitionOnGameplayEffectSparseData& Lhs,
		const FTransitionOnGameplayEffectSparseData& RHS)
	{
		return !(Lhs == RHS);
	}
};

/**
 * Takes the transition once a gameplay effect is applied to the context ASC or applies it to another which matches the requirements.
 */
UCLASS(/*SparseClassDataTypes= TransitionOnGameplayEffectSparseData,*/)
class KETTISLOGICDRIVERGAS_API UTransitionOnGameplayEffect : public UTransitionExtensionBase
{
	GENERATED_BODY()
public:

	UTransitionOnGameplayEffect(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void OnRootStateMachineStart_Implementation() override;

public:

	UPROPERTY(EditAnywhere, Category="Event Trigger")
	EEffectTransitionType Target = EEffectTransitionType::AppliedToSelf;
	
	UPROPERTY(EditAnywhere, Category="Event Trigger")
	TOptional<FTransitionOnGameplayEffectSparseData> EffectTransitionData;
	
	UFUNCTION(BlueprintCallable)
	FTransitionOnGameplayEffectSparseData GetOptionalData(FTransitionOnGameplayEffectSparseData& MyData, bool& bIsSet, bool& bIsSetTemplate);
	
	
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagQuery EffectTagQuery;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayEffect> EffectClassFilter;
	*/
	
	/*
	 * At the moment we remove the delegate by ptr to this object to save on memory.
	 * 
	 * FDelegateHandle OnApplyGameplayEffectCallbackDelegateHandle;
	 * 
	 */
	
	virtual void ConstructionScript_Implementation() override;
	
	virtual void OnTransitionInitialized_Implementation() override;
	
	virtual void OnTransitionShutdown_Implementation() override;

	void OnApplyGameplayEffectCallback(UAbilitySystemComponent* inTarget, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle);
	
	virtual bool CanProvideSource() override {return true;}

	virtual void Serialize(FArchive& Ar) override;
	//const FTransitionOnGameplayEffectSparseData& GetSparseClassData();
};
