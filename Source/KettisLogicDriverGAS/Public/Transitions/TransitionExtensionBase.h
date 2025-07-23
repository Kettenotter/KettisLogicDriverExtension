// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMTransitionInstance.h"
#include "AbilitySystemComponent.h"
#include "SMUtils.h"
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

inline uint8 GSerializeVersion_Transition = 1;

UCLASS(Abstract, meta=(PrioritizeCategories="Ability, GameplayTransition"), AutoExpandCategories="Ability", Category = "GameplayAbility")
class KETTISLOGICDRIVERGAS_API UTransitionExtensionBase : public USMTransitionInstance
{
	GENERATED_BODY()

public:
	

	
	UTransitionExtensionBase(const FObjectInitializer& ObjectInitializer);
	
	/**
	 * The internal condition if this transition can be taken.
	 */
	uint8 bCanEnterTransition:1 = false;



#if WITH_EDITORONLY_DATA
	
	UPROPERTY()
	uint8 SerializeVersion = 0;
	
	UPROPERTY()
	UDataTable* NodeIconDataTable;

	UPROPERTY()
	FString InternalName;
	
	TArray<FString> InternalNames;
	
#endif

	template<typename T>
	T* GetTemplateAs();

	//Some transitions can provide a transition source with triggers from the gameplay ability system.
	virtual bool CanProvideSource(){return false;}

	virtual void Serialize(FArchive& Ar) override;

protected:
	
	/**
	 * Same as take transition but will set the internal state to true before.
	 * @return 
	 */
	bool SetToTrueAndEvaluate();
	
	virtual bool CanEnterTransition_Implementation() const override {return bCanEnterTransition;}
	
	void SetEditorIconFromDataTable(FName RowName);
	void SetEditorColor(bool Status, bool Invalid = false);
	
	//__Gameplay Ability System Related__//

	UAbilitySystemComponent* GetAbilitySystemComponent() const;
	FGameplayTagCountContainer* GetGameplayTagCountContainer() const;
	//Returns the Tag count, -1 if the tag count system is not available.
	int32 GetGameplayTagCount(FGameplayTag Tag) const;

#if !LOGIC_DRIVER_GAS_CUSTOM_SERIALIZE
#define RETURN_IF_LOADING_VERSION_LOWER(VERSION) return;
#endif

#if LOGIC_DRIVER_GAS_CUSTOM_SERIALIZE
#if WITH_EDITOR
#define RETURN_IF_LOADING_VERSION_LOWER(VERSION) if (SerializeVersion < VERSION ) {return;}
#else
#define RETURN_IF_LOADING_VERSION_LOWER(VERSION) {}
#endif
#endif
	
	
#if WITH_EDITOR
	
	void SetTransitionName(FString Name);

	virtual bool ValidColor(){return true;};
	
#endif
	
};

template <typename T>
T* UTransitionExtensionBase::GetTemplateAs()
{

	check(GetOwningNode());
	
	

	if (USMInstance* SMInstance = GetStateMachineInstance())
	{
		return static_cast<T*>(USMUtils::FindTemplateFromInstance(SMInstance, GetOwningNode()->GetTemplateName((this))));
	}

	return nullptr;
	
}

UCLASS(Abstract)
class KETTISLOGICDRIVERGAS_API UTransitionExtensionDelegateBinding : public UTransitionExtensionBase
{
	GENERATED_BODY()

public:
	
	UTransitionExtensionDelegateBinding(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	uint8 bInvertCondition:1;

	/*
	 * If enabled will use event based system. Will run initialize logic after the begin play of the previous node.
	 * If disabled will run the logic in the initialize phase and never call "take manually bound transition".
	 * (This is mostly for easy debugging to make sure everything works)
	 * 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	uint8 bIsEventBased:1 = true;

	
	
protected:
	
	uint8 bDelegateWasBound:1 = false;
	
	uint8 bBlockTriggerUpdate:1 = false;
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

	
	virtual void OnTransitionInitialized_Implementation() override;

	
	virtual void OnTransitionShutdown_Implementation() override;

	virtual void ConstructionScript_Implementation() override;

public:
	virtual void Serialize(FArchive& Ar) override;

	virtual void SerializeBooleans(bool bIsSaving, uint8& PackedBits);
	
};
