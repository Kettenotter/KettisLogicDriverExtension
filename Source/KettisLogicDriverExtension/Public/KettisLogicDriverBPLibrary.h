// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KettisLogicDriverBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KETTISLOGICDRIVEREXTENSION_API UKettisLogicDriverBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	//__ Cast to Context functions __//

	/*
	 * Gets the State Machine Context and Casts it to the Actor c
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "Actor"))
	static AActor* GetContextAsActor(const TScriptInterface<ISMInstanceInterface> NodeInstance);
	
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf = "NodeInstance",HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", CompactNodeTitle = "Actor"))
	static bool GetContextAsActorChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, AActor*& Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "Character"))
	static ACharacter* GetContextAsCharacter(const TScriptInterface<ISMInstanceInterface> NodeInstance);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf = "NodeInstance",HidePin = "NodeInstance", ExpandEnumAsExecs = "ReturnValue", CompactNodeTitle = "Character"))
	static bool GetContextAsCharacterChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, ACharacter*& Character);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", DeterminesOutputType="ReturnClass", DynamicOutputParam="ReturnValue", CompactNodeTitle = "Cast"))
	static UObject* GetContextAsCastTo(const TScriptInterface<ISMInstanceInterface> NodeInstance, TSubclassOf<UObject> ReturnClass);
	
	UFUNCTION(BlueprintCallable, meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", DeterminesOutputType="ReturnClass", DynamicOutputParam="CastContext", CompactNodeTitle = "Cast"))
	static bool GetContextAsCastToChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, TSubclassOf<UObject> ReturnClass, UObject*& CastContext);

	static UObject* GetContextFromObject(const UObject* Object);

	
	//__ Delay __//

	/**
	* A delay which will stop itself it the state is not active.
	* 
	* Only scenario where it might fail is: when a state is exited and entered in the same frame.
	* Because it will abort it on the next update which happens at the end of the frame.
	* This should never happen in State Machines which use non event based logic. And even than it should be very unlikely, still something to keep in mind.
	*/
	UFUNCTION(BlueprintCallable, Category="Utilities|FlowControl", meta=(Latent, DefaultToSelf = "NodeInstance", LatentInfo="LatentInfo", Duration="0.2", Keywords="sleep"))
	static void	DelayStateMachine(USMStateInstance* NodeInstance, float Duration, struct FLatentActionInfo LatentInfo);

	

};
