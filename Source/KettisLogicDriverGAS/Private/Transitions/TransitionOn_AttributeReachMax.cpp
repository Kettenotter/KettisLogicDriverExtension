// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/TransitionOn_AttributeReachMax.h"

#include "AbilitySystemGlobals.h"


UTransitionOn_AttributeReachMax::UTransitionOn_AttributeReachMax(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("AttributeMax"));
}

void UTransitionOn_AttributeReachMax::BindDelegates()
{
	Super::BindDelegates();

	if (DelegateHandle.IsValid())
	{
		return;
	}

	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		DelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TestAttribute).AddUObject(this, &UTransitionOn_AttributeReachMax::AttributeChanged);
		DelegateHandleMax = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MaxAttribute).AddUObject(this, &UTransitionOn_AttributeReachMax::AttributeChanged);

	}
}

void UTransitionOn_AttributeReachMax::ClearDelegates()
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

bool UTransitionOn_AttributeReachMax::TestCondition()
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