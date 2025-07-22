// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMTransitionInstance.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Subsystems/WorldSubsystem.h"
#include "GasSmCacheSubsystem.generated.h"


USTRUCT()
struct FCachedSmGameplayEvent
{
	GENERATED_BODY()

	UPROPERTY()
	FGameplayEventData EventData;
	
};

USTRUCT(BlueprintType)
struct FCachedEffectApplication
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<AActor> SourceActor;

	UPROPERTY(BlueprintReadWrite)
	FGameplayEffectSpecHandle SpecHandle;

	UPROPERTY(BlueprintReadWrite)
	FActiveGameplayEffectHandle ActiveHandle;
};

USTRUCT()
struct FVirtualTagData
{
	GENERATED_BODY()
	FVirtualTagData() = default;

	FGameplayTagCountContainer GameplayTagCountContainer;

	void UpdateTagMap_Internal(const FGameplayTagContainer& Container, int32 CountDelta);
};

UENUM()
enum class ETransitionDataType : uint8
{
	None,
	GameplayEvent,
	GameplayEffect,
};
/**
 * This Subsystem is used to store Data from GAS interactions when we want to allocate memory only when needed.
 * For example the GameplayEvent Data. If we store them on the Transitions the memory is always allocated.
 * Instead we store this Data only when needed. And release it when the state is left.
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API UGasSmCacheSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static UGasSmCacheSubsystem* Get(const UObject* WorldContext);
	
	/**
	 * When an Gameplay Event caused a transition we store the data here.
	 */
	UPROPERTY()
	TMap<TObjectPtr<USMNodeInstance> , FCachedSmGameplayEvent> EventMap;

	/**
	 * When an Effect Application Caused a transition we store the data here.
	 */
	UPROPERTY()
	TMap<TObjectPtr<USMNodeInstance> , FCachedEffectApplication> EffectDataMap;
	

	
	
	//TODO: Implement tags without Ability System Components. Or spawn proxy ASCs? Only for the purpose of tags?
	/** Sometimes we don't want to use Ability System Components.
	* This is an alternative workflow where we store the tags on the State Machine Component.
	*/ 
	//UPROPERTY()
	//TMap<TObjectPtr<USMStateMachineComponent>, FGameplayTagContainer> LooseTags;
	
public:

	void StoreEventData(USMNodeInstance* TargetNodeInstance, const FGameplayEventData* EventData);
	
	UFUNCTION()
	void StoreEffectData(USMNodeInstance* TargetNodeInstance, const FCachedEffectApplication& EventData);

	UFUNCTION()
	void RemoveEventData(USMNodeInstance* TargetNodeInstance);

	UFUNCTION()
	void RemoveEffectData(USMNodeInstance* TargetNodeInstance);

	//UFUNCTION(BlueprintCallable)
	//static FGameplayTagContainer GetStateMachineTags(AActor* Target);
	
	UFUNCTION(BlueprintCallable, meta=(ExpandBoolAsExecs = "ReturnValue", DefaultToSelf = "NodeInstance"))
	static bool GetTransitionDataGameplayEvent(USMNodeInstance* NodeInstance, FGameplayEventData& EventData);

	UFUNCTION(BlueprintCallable, meta=(ExpandBoolAsExecs = "ReturnValue", DefaultToSelf = "NodeInstance"))
	static bool GetTransitionDataGameplayEffect(USMNodeInstance* NodeInstance, FCachedEffectApplication& EffectData);

	/**
	 * Depending on what caused the transition will return:
	 * For Events = Returns the Instigator.
	 * For Effects = Returns the Actor who Applied the Effect.
	 * 
	 * @param NodeInstance 
	 * @param EffectData 
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, meta=(ExpandBoolAsExecs = "ReturnValue", DefaultToSelf = "NodeInstance"))
	static bool GetTransitionDataSourceActor(USMNodeInstance* NodeInstance, AActor*& SourceActor);

	
	
	UFUNCTION()
	void OnStateChangedCleanData( class USMInstance* Instance, struct FSMStateInfo NewState, struct FSMStateInfo PreviousState);
	
	bool bCacheTransitionWasTaken;
	USMTransitionInstance* LastTransitionTaken;

	//TODO: Implement send event to State Machine

	/**
	 * This function works the same as Send Gameplay Event to Actor but will return the transition if one was taken.
	 * From this Transition you can get the state machine, the node it is connected to, the context... additional information you stored on the transition.
	 * 
	 * Set the Instigator in the Payload to the one who send the Event.
	 */
	UFUNCTION(BlueprintCallable, Category = Ability, Meta = (Tooltip = "Same as the Send Gameplay Event to Actor but will return the transition if one was taken."))
	static void SendGameplayEventToActor_StateMachine(AActor* Actor, FGameplayTag EventTag, FGameplayEventData Payload, bool& bTransitionWasTaken, USMTransitionInstance*& TransitionTaken, bool bSendToSmIfNoGAS = true);

	static FVirtualTagData* GetVirtualTagData(const UObject* Object, bool AddIfMissing);
	
	/**
	 * Instead of having them inside 
	 */
	UPROPERTY()
	TMap<TObjectPtr<const UObject>, FVirtualTagData> VirtualTagContainers;
};
