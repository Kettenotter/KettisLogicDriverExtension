// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/TransitionOnAttributeReachMax.h"

#include "AbilitySystemGlobals.h"


UTransitionOnAttributeReachMax::UTransitionOnAttributeReachMax(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("AttributeZero"));
}

void UTransitionOnAttributeReachMax::BindDelegates()
{
	Super::BindDelegates();

	if (DelegateHandle.IsValid())
	{
		return;
	}

	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		DelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TestAttribute).AddUObject(this, &UTransitionOnAttributeReachMax::AttributeChanged);
		DelegateHandleMax = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MaxAttribute).AddUObject(this, &UTransitionOnAttributeReachMax::AttributeChanged);

	}
}

void UTransitionOnAttributeReachMax::ClearDelegates()
{
	Super::ClearDelegates();

	if (!DelegateHandle.IsValid())
	{
		return;
	}
	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TestAttribute).Remove(DelegateHandle);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MaxAttribute).Remove(DelegateHandleMax);

		DelegateHandle.Reset();
	}
}

bool UTransitionOnAttributeReachMax::TestCondition()
{
	
	if (const UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		if (AbilitySystemComponent->GetNumericAttribute(TestAttribute) >= AbilitySystemComponent->GetNumericAttribute(MaxAttribute))
		{
			return true;
		}		
	}
	return false;
}