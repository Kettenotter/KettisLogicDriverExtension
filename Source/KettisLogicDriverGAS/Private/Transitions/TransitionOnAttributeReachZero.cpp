#include "Transitions/TransitionOnAttributeReachZero.h"
#include "AbilitySystemComponent.h"

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

	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
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
	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).Remove(DelegateHandle);
		DelegateHandle.Reset();
	}
}

bool UTransitionOnAttributeReachZero::TestCondition()
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
