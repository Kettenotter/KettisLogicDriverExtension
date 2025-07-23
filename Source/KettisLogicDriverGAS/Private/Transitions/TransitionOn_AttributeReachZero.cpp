#include "Transitions/TransitionOn_AttributeReachZero.h"
#include "AbilitySystemComponent.h"

UTransitionOn_AttributeReachZero::UTransitionOn_AttributeReachZero(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("AttributeZero"));
}

void UTransitionOn_AttributeReachZero::BindDelegates()
{
	Super::BindDelegates();

	if (DelegateHandle.IsValid())
	{
		return;
	}

	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		DelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &UTransitionOn_AttributeReachZero::AttributeChanged);
	}
}

void UTransitionOn_AttributeReachZero::ClearDelegates()
{
	Super::ClearDelegates();

	if (!DelegateHandle.IsValid())
	{
		return;
	}
	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).Remove(DelegateHandle);
		DelegateHandle.Reset();
	}
}

bool UTransitionOn_AttributeReachZero::TestCondition()
{
	
	if (const UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		if (AbilitySystemComponent->GetNumericAttribute(Attribute) < 0.001)
		{
			return true;
		}		
	}
	return false;
}
