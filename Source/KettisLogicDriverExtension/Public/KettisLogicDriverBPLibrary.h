// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystemComponent.h"
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
	 * Gets the State Machine Context and Casts it to the Actor class.
	 */
	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
		BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "Actor"))
	static AActor* GetContextAsActor(const TScriptInterface<ISMInstanceInterface> NodeInstance);
	
	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
		meta=(DefaultToSelf = "NodeInstance",HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", CompactNodeTitle = "Actor"))
	static bool GetContextAsActorChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, AActor*& Actor);

	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
	BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "Pawn"))
	static APawn* GetContextAsPawn(const TScriptInterface<ISMInstanceInterface> NodeInstance);

	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
		meta=(DefaultToSelf = "NodeInstance",HidePin = "NodeInstance", ExpandEnumAsExecs = "ReturnValue", CompactNodeTitle = "Pawn"))
	static bool GetContextAsPawnChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, APawn*& Character);

	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
		BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "Character"))
	static ACharacter* GetContextAsCharacter(const TScriptInterface<ISMInstanceInterface> NodeInstance);

	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
		meta=(DefaultToSelf = "NodeInstance",HidePin = "NodeInstance", ExpandEnumAsExecs = "ReturnValue", CompactNodeTitle = "Character"))
	static bool GetContextAsCharacterChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, ACharacter*& Character);

	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
		BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", DeterminesOutputType="ReturnClass", DynamicOutputParam="ReturnValue", CompactNodeTitle = "Cast"))
	static UObject* GetContextAsCastTo(const TScriptInterface<ISMInstanceInterface> NodeInstance, TSubclassOf<UObject> ReturnClass);
	
	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
		meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", DeterminesOutputType="ReturnClass", DynamicOutputParam="CastContext", CompactNodeTitle = "Cast"))
	static bool GetContextAsCastToChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, TSubclassOf<UObject> ReturnClass, UObject*& CastContext);

	static UObject* GetContextFromObject(const UObject* Object);

	//__ Component __//

	/** Component from CONTEXT
	 * Finds the first component on the context actor which has the matching class.
	 */
	UFUNCTION(BlueprintCallable, Category= "LogicDriver|Extension|Utility" ,
		meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", DeterminesOutputType="ComponentClass", DynamicOutputParam="Component", CompactNodeTitle = "Comp", Keywords = "Find"))
	static bool GetComponentFromContext(const TScriptInterface<ISMInstanceInterface> NodeInstance, TSubclassOf<UActorComponent> ComponentClass, UActorComponent*& Component);

	/** Components from CONTEXT
	 * Finds all the components on the context actor which have the matching class.
	 */
	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Utility",
		meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", DeterminesOutputType="ComponentClass", DynamicOutputParam="Components", CompactNodeTitle = "Comps", Keywords = "Find"))
	static bool GetComponentsFromContext(const TScriptInterface<ISMInstanceInterface> NodeInstance, TSubclassOf<UActorComponent> ComponentClass, TArray<UActorComponent*>& Components);

	
	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
	BlueprintPure, meta=(DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "PrimRoot"))
	static UPrimitiveComponent* GetContextRootAsPrimitive(const TScriptInterface<ISMInstanceInterface> NodeInstance);

	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Casting",
	meta=(DefaultToSelf = "NodeInstance",HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", CompactNodeTitle = "PrimRoot"))
	static bool GetContextRootAsPrimitiveChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, UPrimitiveComponent*& PrimitiveComp);
	
	//__ Ability System Component __//
	
	/** Ability System Component from CONTEXT.
	 * Uses the interface.
	 */
	UFUNCTION(BlueprintCallable, Category= "LogicDriver|Extension|Utility" ,
	BlueprintPure, meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "ASC", Keywords = "Find, ASC"))
	static UAbilitySystemComponent* GetAbilitySystemComponentFromContext(const TScriptInterface<ISMInstanceInterface> NodeInstance);
	
	/** Ability System Component from CONTEXT.
	 * Uses the interface.
	 */
	UFUNCTION(BlueprintCallable, Category= "LogicDriver|Extension|Utility" ,
		meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", ExpandBoolAsExecs = "ReturnValue", CompactNodeTitle = "ASC", Keywords = "Find, ASC"))
	static bool GetAbilitySystemComponentFromContextChecked(const TScriptInterface<ISMInstanceInterface> NodeInstance, UAbilitySystemComponent*& Component);

	/** Use this in the case if your context is not the avatar actor.
	 * For example if you run the state machine on your controller and have it as the context. (The Context still needs to Implement the GAS interface)
	 * But in most cases I would recommend to set your Context to the Avatar Actor.
	 */
	UFUNCTION(BlueprintCallable, Category= "LogicDriver|Extension|Utility" ,
	BlueprintPure, meta=( DefaultToSelf = "NodeInstance", HidePin = "NodeInstance", CompactNodeTitle = "Avatar", Keywords = "Find, ASC"))
	static AActor* GetAvatarActorFromContext(const TScriptInterface<ISMInstanceInterface> NodeInstance);

	
	
	//__ UTILITY __//

	/**
	* A delay which will stop itself it the state is not active.
	* 
	* Only scenario where it might fail is: when a state is exited and entered in the same frame.
	* Because it will abort it on the next update which happens at the end of the frame.
	* This should never happen in State Machines which use non event based logic. And even than it should be very unlikely, still something to keep in mind.
	*/
	UFUNCTION(BlueprintCallable,Category= "LogicDriver|Extension|Utility", meta=(Latent, DefaultToSelf = "NodeInstance", LatentInfo="LatentInfo", Duration="0.2", Keywords="sleep"))
	static void	DelayStateMachine(USMStateInstance* NodeInstance, float Duration, struct FLatentActionInfo LatentInfo);

	/**
	* Checks if the State is Active or no
	*/
	UFUNCTION(BlueprintCallable, Category= "LogicDriver|Extension|Utility", meta=(DefaultToSelf = "NodeInstance", ExpandBoolAsExecs = "ReturnValue"))
	static bool	SwitchOnActive(USMStateInstance* NodeInstance);
	
	//__ Editor __//

	UFUNCTION(BlueprintCallable, Category= "LogicDriver|Extension|Editor", meta=(DevelopmentOnly))
	static UObject* SpawnAndRegisterTab(class UUserWidgetBlueprint* Widget);
	
	
};
