// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/TransitionOn_GameplayTagQuery.h"


UTransitionOn_GameplayTagQuery::UTransitionOn_GameplayTagQuery(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("GameplayTagQuery"));
}

void UTransitionOn_GameplayTagQuery::PostBeginInitialize(USMStateInstance_Base* StateInstance)
{
	// !! Delegates are bound before we test.
	if (!bDelegateWasBound)
	{
		BindDelegates();
	}
	
	Super::PostBeginInitialize(StateInstance);
}

void UTransitionOn_GameplayTagQuery::BindDelegates()
{
	Super::BindDelegates();

	bBlockTriggerUpdate = true;
	
	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		
		TArray<FGameplayTag> QueryTags;
		TagQuery.GetGameplayTagArray(QueryTags);

		for (const FGameplayTag& Tag : QueryTags)
		{
			if (!TagHandleMap.Contains(Tag))
			{
				UpdateTargetTags(Tag, ASC->GetTagCount(Tag));
				TagHandleMap.Add(Tag, ASC->RegisterGameplayTagEvent(Tag).AddUObject(this, &UTransitionOn_GameplayTagQuery::UpdateTargetTags));
			}
		}
		
	}
	else if (FGameplayTagCountContainer* GameplayTagCountContainer = GetGameplayTagCountContainer())
	{
		TArray<FGameplayTag> QueryTags;
		TagQuery.GetGameplayTagArray(QueryTags);

		for (const FGameplayTag& Tag : QueryTags)
		{
			if (!TagHandleMap.Contains(Tag))
			{
				UpdateTargetTags(Tag, GameplayTagCountContainer->GetTagCount(Tag));
				TagHandleMap.Add(Tag, GameplayTagCountContainer->RegisterGameplayTagEvent(Tag).AddUObject(this, &UTransitionOn_GameplayTagQuery::UpdateTargetTags));
			}
		}
	}
	
	bBlockTriggerUpdate = false;
	
	//Dont need to call Trigger Update, will be called from the Parent Code already.
	//TriggerUpdate();
	
}

void UTransitionOn_GameplayTagQuery::ClearDelegates()
{
	Super::ClearDelegates();
	
	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		for (TPair<FGameplayTag, FDelegateHandle> Pair : TagHandleMap)
		{
			if (Pair.Value.IsValid())
			{
				ASC->UnregisterGameplayTagEvent(Pair.Value, Pair.Key);
			}
		}
	}
	else if (FGameplayTagCountContainer* GameplayTagCountContainer = GetGameplayTagCountContainer())
	{
		for (TPair<FGameplayTag, FDelegateHandle> Pair : TagHandleMap)
		{
			if (Pair.Value.IsValid())
			{
				GameplayTagCountContainer->RegisterGameplayTagEvent(Pair.Key).Remove(Pair.Value);
			}
		}
	}

	TagHandleMap.Empty();
	TargetTags.Reset();
	
}


bool UTransitionOn_GameplayTagQuery::TestCondition()
{
	if (TagQuery.IsEmpty())
	{
		return false;
	}

	return TagQuery.Matches(TargetTags);
}

void UTransitionOn_GameplayTagQuery::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();
	
#if WITH_EDITOR

	if (!IsEditorExecution()){return;}
	
	if (TagQuery.IsEmpty())
	{
		SetEditorColor(false, true);
	}
	SetTransitionName("<TagQuery> " + TagQuery.GetDescription());
	
#endif
	
}

void UTransitionOn_GameplayTagQuery::UpdateTargetTags(const FGameplayTag Tag, int32 NewCount)
{
	// Micro optimization don't do anything if the tag is already present.
	// Wait the delegate should only trigger on added or removed so this is not needed?
	if (NewCount > 0 == TargetTags.HasTagExact(Tag))
	{
		return;
	}
	
	if (NewCount <= 0)
	{
		TargetTags.RemoveTag(Tag);
	}
	else
	{
		
		TargetTags.AddTag(Tag);
	
	}
	TriggerUpdate();
	
}

void UTransitionOn_GameplayTagQuery::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	
	RETURN_IF_LOADING_VERSION_LOWER(1)
	TagQuery.Serialize(Ar);
}
