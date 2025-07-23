

#include "Transitions/TransitionOn_GameplayTag.h"

#include "GasSmCacheSubsystem.h"

UTransitionOn_GameplayTag::UTransitionOn_GameplayTag(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("GameplayTag"));
}



void UTransitionOn_GameplayTag::BindDelegates()
{
	Super::BindDelegates();
	
	
	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		DelegateHandle = AbilitySystemComponent->RegisterGameplayTagEvent(Tag, EGameplayTagEventType::NewOrRemoved).AddUObject(this, &UTransitionOn_GameplayTag::TagChanged);
		
	}
	else if (FGameplayTagCountContainer* GameplayTagCountContainer = GetGameplayTagCountContainer())
	{
		DelegateHandle = GameplayTagCountContainer->RegisterGameplayTagEvent(Tag, EGameplayTagEventType::NewOrRemoved).AddUObject(this, &UTransitionOn_GameplayTag::TagChanged);
	}
}

void UTransitionOn_GameplayTag::ClearDelegates()
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


bool UTransitionOn_GameplayTag::TestCondition()
{
	
	if (int32 TagCount = GetGameplayTagCount(Tag); TagCount >= 0)
	{
		return TagCount > 0;
	}
	
	return bInvertCondition ? true : false; //To return a false if the ASC is not valid we invert it here.
}


void UTransitionOn_GameplayTag::ConstructionScript_Implementation()
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

void UTransitionOn_GameplayTag::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	RETURN_IF_LOADING_VERSION_LOWER(1)
	
	Ar << Tag;
}

