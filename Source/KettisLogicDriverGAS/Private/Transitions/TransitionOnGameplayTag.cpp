

#include "Transitions/TransitionOnGameplayTag.h"

#include "GasSmCacheSubsystem.h"

UTransitionOnGameplayTag::UTransitionOnGameplayTag(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("GameplayTag"));
}



void UTransitionOnGameplayTag::BindDelegates()
{
	Super::BindDelegates();
	
	
	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		DelegateHandle = AbilitySystemComponent->RegisterGameplayTagEvent(Tag, EGameplayTagEventType::NewOrRemoved).AddUObject(this, &UTransitionOnGameplayTag::TagChanged);
		
	}
	else if (FGameplayTagCountContainer* GameplayTagCountContainer = GetGameplayTagCountContainer())
	{
		DelegateHandle = GameplayTagCountContainer->RegisterGameplayTagEvent(Tag, EGameplayTagEventType::NewOrRemoved).AddUObject(this, &UTransitionOnGameplayTag::TagChanged);
	}
}

void UTransitionOnGameplayTag::ClearDelegates()
{
	Super::ClearDelegates();

	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		AbilitySystemComponent->UnregisterGameplayTagEvent(DelegateHandle, Tag, EGameplayTagEventType::NewOrRemoved);
		DelegateHandle.Reset();
	}
	else
	{
		//Register the virtual Ones

		if (FGameplayTagCountContainer* GameplayTagCountContainer = GetGameplayTagCountContainer())
		{
			GameplayTagCountContainer->RegisterGameplayTagEvent(Tag, EGameplayTagEventType::NewOrRemoved).Remove(DelegateHandle);
		}
		DelegateHandle.Reset();
	}
}


bool UTransitionOnGameplayTag::TestCondition()
{
	
	if (int32 TagCount = GetGameplayTagCount(Tag); TagCount >= 0)
	{
		return TagCount > 0;
	}
	
	return bInvertCondition ? true : false; //To return a false if the ASC is not valid we invert it here.
}


void UTransitionOnGameplayTag::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	if (!Tag.IsValid())
	{
		SetEditorColor(false, true);
	}

	SetTransitionName("<Tag> " + Tag.ToString());
#endif
}

void UTransitionOnGameplayTag::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	RETURN_IF_LOADING_VERSION_LOWER(1)
	
	Ar << Tag;
}

