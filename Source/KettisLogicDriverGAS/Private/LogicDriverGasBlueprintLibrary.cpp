// Fill out your copyright notice in the Description page of Project Settings.


#include "LogicDriverGasBlueprintLibrary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "GasSmCacheSubsystem.h"
#include "KettisLogicDriverBPLibrary.h"

bool ULogicDriverGasBlueprintLibrary::AddLooseGameplayTags_StateMachine(AActor* Actor,
                                                                        const FGameplayTagContainer& GameplayTags, bool bShouldReplicate)
{
	if (UAbilitySystemComponent* AbilitySysComp = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor))
	{
		return UAbilitySystemBlueprintLibrary::AddLooseGameplayTags(Actor, GameplayTags, bShouldReplicate);
	}

	if (UGasSmCacheSubsystem* Sub = UGasSmCacheSubsystem::Get(Actor))
	{
		FVirtualTagData& DataFound = Sub->VirtualTagContainers.FindOrAdd(Actor);
		DataFound.UpdateTagMap_Internal(GameplayTags, 1);
		return true;
	}
	
	return false;
}

bool ULogicDriverGasBlueprintLibrary::RemoveLooseGameplayTags_StateMachine(AActor* Actor,
	const FGameplayTagContainer& GameplayTags, bool bShouldReplicate)
{
	if (UAbilitySystemComponent* AbilitySysComp = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor))
	{
		return UAbilitySystemBlueprintLibrary::RemoveLooseGameplayTags(Actor, GameplayTags, bShouldReplicate);
	}
	if (UGasSmCacheSubsystem* Sub = UGasSmCacheSubsystem::Get(Actor))
	{
		FVirtualTagData& DataFound = Sub->VirtualTagContainers.FindOrAdd(Actor);
		DataFound.UpdateTagMap_Internal(GameplayTags, -1);
		return true;
	}
	
	return false;
}

bool ULogicDriverGasBlueprintLibrary::AddOrRemoveGameplayTag_StateMachine(AActor* Actor,
	const FGameplayTag& GameplayTag, bool bRemoveTag, bool bShouldReplicate)
{
	if (bRemoveTag)
	{
		return RemoveLooseGameplayTags_StateMachine(Actor, FGameplayTagContainer(GameplayTag), bShouldReplicate);
	}
	else
	{
		return AddLooseGameplayTags_StateMachine(Actor, FGameplayTagContainer(GameplayTag), bShouldReplicate);
	}
}

bool ULogicDriverGasBlueprintLibrary::HasGameplayTag_StateMachine(AActor* Actor, const FGameplayTag& Tag)
{
	if (UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, false))
	{
		return ASC->GetTagCount(Tag) > 0;
	}

	if (!Actor)
	{
		return false;
	}

	if (FVirtualTagData* FoundData = UGasSmCacheSubsystem::Get(Actor)->VirtualTagContainers.Find(Actor))
	{
		return FoundData->GameplayTagCountContainer.GetTagCount(Tag) > 0;
	}

	return false;
	
	
}

FGameplayTagContainer ULogicDriverGasBlueprintLibrary::GetTags_StateMachine(AActor* Actor)
{
	if (UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, false))
	{
		return ASC->GetOwnedGameplayTags();
	}

	if (!Actor)
	{
		return FGameplayTagContainer();
	}

	if (FVirtualTagData* FoundData = UGasSmCacheSubsystem::Get(Actor)->VirtualTagContainers.Find(Actor))
	{
		return FoundData->GameplayTagCountContainer.GetExplicitGameplayTags();
		
	}
	return FGameplayTagContainer();

}
bool ULogicDriverGasBlueprintLibrary::HasGameplayTag(const TScriptInterface<ISMInstanceInterface> NodeInstance,
	const FGameplayTag& Tag)
{
	//Checks on the GAS System 
	if (UAbilitySystemComponent* ASC = UKettisLogicDriverBPLibrary::GetAbilitySystemComponentFromContext(NodeInstance))
	{
		return ASC->GetGameplayTagCount(Tag) > 0;
	}

	//Checks on the Virtual Container
	if (UObject* Context = UKettisLogicDriverBPLibrary::GetContextFromObject(NodeInstance.GetObject()))
	{
		if (FVirtualTagData* Data = UGasSmCacheSubsystem::GetVirtualTagData(Context, false))
		{
			return Data->GameplayTagCountContainer.GetTagCount(Tag) > 0;
		}
		return false;
	}
	return false;
}