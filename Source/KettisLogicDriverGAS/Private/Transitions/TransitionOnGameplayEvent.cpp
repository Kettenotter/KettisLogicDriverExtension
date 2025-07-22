
#include "Transitions/TransitionOnGameplayEvent.h"

#include "GasSmCacheSubsystem.h"

UTransitionOnGameplayEvent::UTransitionOnGameplayEvent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("GameplayEvent"));
	SetCanEvaluate(false);
}

void UTransitionOnGameplayEvent::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR

	if (!IsEditorExecution())
	{
		return;
	}
	
	if (Tag.IsValid())
	{
		NodeIconTintColor = FColor::White;
		NodeIconTintColor.A = 1;
	}
	else
	{
		NodeIconTintColor = FColor::White;
		NodeIconTintColor.A = 0.2;
	}

	FString DisplayName = "<Event> " + Tag.ToString();
	SetTransitionName(DisplayName);

#endif
	
	
}

void UTransitionOnGameplayEvent::OnTransitionInitialized_Implementation()
{
	Super::OnTransitionInitialized_Implementation();

	if (GameplayEventHandle.IsValid())
	{
		return;
	}
	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		if (bOnlyMatchExact)
		{
			GameplayEventHandle = ASC->GenericGameplayEventCallbacks.FindOrAdd(Tag).AddUObject(this, &UTransitionOnGameplayEvent::GameplayEventCallback);
		}
		else
		{
			GameplayEventHandle = ASC->AddGameplayEventTagContainerDelegate(FGameplayTagContainer(Tag), FGameplayEventTagMulticastDelegate::FDelegate::CreateUObject(this, &UTransitionOnGameplayEvent::GameplayEventContainerCallback));
		}
	}
}

void UTransitionOnGameplayEvent::OnTransitionShutdown_Implementation()
{
	Super::OnTransitionShutdown_Implementation();

	bCanEnterTransition = false;
	
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (ASC && GameplayEventHandle.IsValid())
	{
		if (bOnlyMatchExact)
		{
			ASC->GenericGameplayEventCallbacks.FindOrAdd(Tag).Remove(GameplayEventHandle);
		}
		else
		{
			ASC->RemoveGameplayEventTagContainerDelegate(FGameplayTagContainer(Tag), GameplayEventHandle);
		}
		GameplayEventHandle.Reset();

	}
}

void UTransitionOnGameplayEvent::GameplayEventCallback(const FGameplayEventData* Payload)
{
	if (bRemainTrueUntilExit)
	{
		bCanEnterTransition = true;
	}
	
	UGasSmCacheSubsystem* CacheSub = GetWorld()->GetSubsystem<UGasSmCacheSubsystem>();
 	CacheSub->StoreEventData(GetNextStateInstance(), Payload);
	if (SetToTrueAndEvaluate())
	{
		CacheSub->bCacheTransitionWasTaken = true;
		CacheSub->LastTransitionTaken = this;
	}
	else
	{
		CacheSub->RemoveEventData(GetNextStateInstance());
	}
}

void UTransitionOnGameplayEvent::GameplayEventContainerCallback(FGameplayTag MatchingTag,
	const FGameplayEventData* Payload)
{
	GameplayEventCallback(Payload);
}

void UTransitionOnGameplayEvent::SimulateEventCallback(FGameplayTag EventTag, const FGameplayEventData* Payload)
{
	if (bOnlyMatchExact)
	{
		if (EventTag == Tag)
		{
			GameplayEventCallback(Payload);
		}
	}
	else
	{
		FGameplayTag CurrentTag = EventTag;
		while (CurrentTag.IsValid())
		{
			if (CurrentTag == Tag)
			{
				CurrentTag = FGameplayTag::EmptyTag;
				GameplayEventCallback(Payload);
			}

			CurrentTag = CurrentTag.RequestDirectParent();
		}
	}
}

void UTransitionOnGameplayEvent::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	RETURN_IF_LOADING_VERSION_LOWER(1)

	return;
	
	Ar << Tag;
	FArchive_Serialize_BitfieldBool(Ar, bOnlyMatchExact);
	FArchive_Serialize_BitfieldBool(Ar, bRemainTrueUntilExit);
}


bool UTransitionOnGameplayEventCachedData::GetLastGameplayEventData(FGameplayEventData& EventData)
{
	if (CachedEventData.IsSet())
	{
		EventData = CachedEventData.GetValue();
		return true;
	}
	return false;
	
}

void UTransitionOnGameplayEventCachedData::GameplayEventCallback(const FGameplayEventData* Payload)
{
	CachedEventData = *Payload;
	Super::GameplayEventCallback(Payload);
}

void UTransitionOnGameplayEventCachedData::GameplayEventContainerCallback(FGameplayTag MatchingTag,
	const FGameplayEventData* Payload)
{
	CachedEventData = *Payload;
	Super::GameplayEventContainerCallback(MatchingTag, Payload);
}






