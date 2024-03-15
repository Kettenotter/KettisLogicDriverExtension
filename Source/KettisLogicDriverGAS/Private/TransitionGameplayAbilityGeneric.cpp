// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\TransitionGameplayAbilityGeneric.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "SMStateInstance.h"


UTransitionOnGameplayTagPresent::UTransitionOnGameplayTagPresent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("GameplayTag"));
}



void UTransitionOnGameplayTagPresent::BindDelegates()
{
	Super::BindDelegates();
	
	
	if (UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		DelegateHandle = AbilitySystemComponent->RegisterGameplayTagEvent(Tag, EGameplayTagEventType::NewOrRemoved).AddUObject(this, &UTransitionOnGameplayTagPresent::TagChanged);
		
	}
}

void UTransitionOnGameplayTagPresent::ClearDelegates()
{
	Super::ClearDelegates();

	if (UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		AbilitySystemComponent->UnregisterGameplayTagEvent(DelegateHandle, Tag, EGameplayTagEventType::NewOrRemoved);
		DelegateHandle.Reset();
	}
}


bool UTransitionOnGameplayTagPresent::TestCondition()
{
	if (const UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		return  AbilitySystemComponent->GetGameplayTagCount(Tag) > 0;
		
	}
	
	return bInvertCondition ? true : false;
}


void UTransitionOnGameplayTagPresent::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	if (!Tag.IsValid())
	{
		SetEditorColor(false, true);
	}
#endif
}

UTransitionOnGameplayTagQuery::UTransitionOnGameplayTagQuery(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("GameplayTagQuery"));
}

void UTransitionOnGameplayTagQuery::PostBeginInitialize(USMStateInstance_Base* StateInstance)
{
	// !! Delegates are bound before we test.
	if (!bDelegateWasBound)
	{
		BindDelegates();
	}
	
	Super::PostBeginInitialize(StateInstance);
}

void UTransitionOnGameplayTagQuery::BindDelegates()
{
	Super::BindDelegates();

	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		
		TArray<FGameplayTag> QueryTags;
		TagQuery.GetGameplayTagArray(QueryTags);

		for (const FGameplayTag& Tag : QueryTags)
		{
			if (!TagHandleMap.Contains(Tag))
			{
				UpdateTargetTags(Tag, ASC->GetTagCount(Tag));
				TagHandleMap.Add(Tag, ASC->RegisterGameplayTagEvent(Tag).AddUObject(this, &UTransitionOnGameplayTagQuery::UpdateTargetTags));
			}
		}
		
	}
	
}

void UTransitionOnGameplayTagQuery::ClearDelegates()
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

	TagHandleMap.Empty();
	TargetTags.Reset();
	
}


bool UTransitionOnGameplayTagQuery::TestCondition()
{
	if (TagQuery.IsEmpty())
	{
		return false;
	}

	return TagQuery.Matches(TargetTags);
}

void UTransitionOnGameplayTagQuery::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();
	
#if WITH_EDITOR
	if (TagQuery.IsEmpty())
	{
		SetEditorColor(false, true);
	}
#endif
	
}

void UTransitionOnGameplayTagQuery::UpdateTargetTags(const FGameplayTag Tag, int32 NewCount)
{
	if (NewCount <= 0)
	{
		TargetTags.RemoveTag(Tag);
	}
	else
	{
		/*//Micro optimization don't do anything if the tag is already present.
		if (TargetTags.HasTagExact(Tag))
		{
			return;
		}*/
		
		TargetTags.AddTag(Tag);
	
	}

	TriggerUpdate();
}

UTransitionOnAttributeReachZero::UTransitionOnAttributeReachZero(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("AttributeZero"));
}

void UTransitionOnAttributeReachZero::BindDelegates()
{
	Super::BindDelegates();

	if (DelegateHandle.IsValid())
	{
		return;
	}

	if (UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		DelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &UTransitionOnAttributeReachZero::AttributeChanged);
	}
}

void UTransitionOnAttributeReachZero::ClearDelegates()
{
	Super::ClearDelegates();

	if (!DelegateHandle.IsValid())
	{
		return;
	}
	if (UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).Remove(DelegateHandle);
		DelegateHandle.Reset();
	}
}

bool UTransitionOnAttributeReachZero::TestCondition()
{
	
	if (const UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		if (AbilitySystemComponent->GetNumericAttribute(Attribute) < 0.001)
		{
			return true;
		}		
	}
	return false;
}


