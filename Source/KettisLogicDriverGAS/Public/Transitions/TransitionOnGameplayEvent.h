#pragma once


#include "TransitionExtensionBase.h"
#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "TransitionExtensionBase.h"
#include "Nodes/Transitions/SMTransitionInstance.h"

#include "TransitionOnGameplayEvent.generated.h"


struct FOnAttributeChangeData;

/**
 * Takes the transitions when the Gameplay event is received.
 */

UCLASS()
class UTransitionOnGameplayEvent : public UTransitionExtensionBase
{
	GENERATED_BODY()
public:
	
	UTransitionOnGameplayEvent(const FObjectInitializer& ObjectInitializer);

	/**
	 * The tag event tag which triggers the transition.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ability")
	FGameplayTag Tag;

	/**
	 * 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ability")
	uint8 bOnlyMatchExact:1 = true;

	/**
	 * If enabled, once the event is triggered the internal state will be set to true and remain there until the transition is shutdown.
	 * This allows to chain events. Wait until event x and event y and then take the transition.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ability")
	uint8 bRemainTrueUntilExit:1 = false;
	
	// Perhaps we should store this one sparse too? It's a 64 bit Integer/  8 bytes
	FDelegateHandle GameplayEventHandle;
	
	virtual bool CanProvideSource() override {return true;}

protected:
	
	virtual void ConstructionScript_Implementation() override;
	
	
	virtual void OnTransitionInitialized_Implementation() override;
	
	virtual void OnTransitionShutdown_Implementation() override;

	virtual void GameplayEventCallback(const FGameplayEventData* Payload);

	virtual void GameplayEventContainerCallback(FGameplayTag MatchingTag, const FGameplayEventData* Payload);

public:
	virtual void SimulateEventCallback(FGameplayTag EventTag, const FGameplayEventData* Payload);

	virtual void Serialize(FArchive& Ar) override;
	
};


/**
 * DEPRECATED!!!
 * We store the event data in sparse way now.
 * 
 */
UCLASS(meta=(DeprecatedNode))
class UTransitionOnGameplayEventCachedData : public UTransitionOnGameplayEvent
{
	GENERATED_BODY()
	
public:

	
	/**
	 * Stores the last Event Data Payload so it can be used by connected states.
	 * Its quite big so its optional.
	 *
	 * TODO: Make sure the pointers inside TOptional are not wonky donky.
	 */
	
	TOptional<FGameplayEventData> CachedEventData;

	UFUNCTION(BlueprintCallable)
	bool GetLastGameplayEventData(FGameplayEventData& EventData);

protected:
	virtual void GameplayEventCallback(const FGameplayEventData* Payload) override;
	virtual void GameplayEventContainerCallback(FGameplayTag MatchingTag, const FGameplayEventData* Payload) override;
};

