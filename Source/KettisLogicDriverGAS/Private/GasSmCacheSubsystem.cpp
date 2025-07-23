// Fill out your copyright notice in the Description page of Project Settings.


#include "GasSmCacheSubsystem.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "SMInstance.h"
#include "SMNodeInstance.h"
#include "SMStateMachineComponent.h"
#include "Transitions/TransitionOn_GameplayEvent.h"

void FVirtualTagData::UpdateTagMap_Internal(const FGameplayTagContainer& Container, int32 CountDelta)
{
	// For removal, reorder calls so that FillParentTags is only called once
	if (CountDelta > 0)
	{
		for (auto TagIt = Container.CreateConstIterator(); TagIt; ++TagIt)
		{
			const FGameplayTag& Tag = *TagIt;
			if (GameplayTagCountContainer.UpdateTagCount(Tag, CountDelta))
			{
				//OnTagUpdated(Tag, true);
			}
		}
	}
	else if (CountDelta < 0)
	{
		// Defer FillParentTags and calling delegates until all Tags have been removed
		TArray<FGameplayTag> RemovedTags;
		RemovedTags.Reserve(Container.Num()); // pre-allocate max number (if all are removed)
		TArray<FDeferredTagChangeDelegate> DeferredTagChangeDelegates;

		for (auto TagIt = Container.CreateConstIterator(); TagIt; ++TagIt)
		{
			const FGameplayTag& Tag = *TagIt;
			if (GameplayTagCountContainer.UpdateTagCount_DeferredParentRemoval(Tag, CountDelta, DeferredTagChangeDelegates))
			{
				RemovedTags.Add(Tag);
			}
		}

		// now do the work that was deferred
		if (RemovedTags.Num() > 0)
		{
			GameplayTagCountContainer.FillParentTags();
		}

		for (FDeferredTagChangeDelegate& Delegate : DeferredTagChangeDelegates)
		{
			Delegate.Execute();
		}

		// Notify last in case OnTagUpdated queries this container
		for (FGameplayTag& Tag : RemovedTags)
		{
			//OnTagUpdated(Tag, false);
		}
	}
}

FDelegateHandle FVirtualTagData::AddGameplayEventTagContainerDelegate(const FGameplayTagContainer& TagFilter,
	const FGameplayEventTagMulticastDelegate::FDelegate& Delegate)
{
	TPair<FGameplayTagContainer, FGameplayEventTagMulticastDelegate>* FoundPair = nullptr;

	for (TPair<FGameplayTagContainer, FGameplayEventTagMulticastDelegate>& SearchPair : GameplayEventTagContainerDelegates)
	{
		if (TagFilter == SearchPair.Key)
		{
			FoundPair = &SearchPair;
			break;
		}
	}

	if (!FoundPair)
	{
		FoundPair = new(GameplayEventTagContainerDelegates) TPair<FGameplayTagContainer, FGameplayEventTagMulticastDelegate>(TagFilter, FGameplayEventTagMulticastDelegate());
	}

	return FoundPair->Value.Add(Delegate);
}

void FVirtualTagData::RemoveGameplayEventTagContainerDelegate(const FGameplayTagContainer& TagFilter,
	FDelegateHandle DelegateHandle)
{
	// Look for and remove delegate, remove from array if no more delegates are bound
	for (int32 Index = 0; Index < GameplayEventTagContainerDelegates.Num(); Index++)
	{
		TPair<FGameplayTagContainer, FGameplayEventTagMulticastDelegate>& SearchPair = GameplayEventTagContainerDelegates[Index];
		if (TagFilter == SearchPair.Key)
		{
			SearchPair.Value.Remove(DelegateHandle);
			if (!SearchPair.Value.IsBound())
			{
				GameplayEventTagContainerDelegates.RemoveAt(Index);
			}
			break;
		}
	}
}

int32 FVirtualTagData::HandleGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload)
{
	int32 TriggeredCount = 0;

	if (FGameplayEventMulticastDelegate* Delegate = GenericGameplayEventCallbacks.Find(EventTag))
	{
		// Make a copy before broadcasting to prevent memory stomping
		FGameplayEventMulticastDelegate DelegateCopy = *Delegate;
		DelegateCopy.Broadcast(Payload);
	}

	// Make a copy in case it changes due to callbacks
	TArray<TPair<FGameplayTagContainer, FGameplayEventTagMulticastDelegate>> LocalGameplayEventTagContainerDelegates = GameplayEventTagContainerDelegates;
	for (TPair<FGameplayTagContainer, FGameplayEventTagMulticastDelegate>& SearchPair : LocalGameplayEventTagContainerDelegates)
	{
		if (SearchPair.Key.IsEmpty() || EventTag.MatchesAny(SearchPair.Key))
		{
			SearchPair.Value.Broadcast(EventTag, Payload);
		}
	}

	return TriggeredCount;
}

UGasSmCacheSubsystem* UGasSmCacheSubsystem::Get(const UObject* WorldContext)
{
	if (WorldContext)
	{
		if (UWorld* World = WorldContext->GetWorld())
		{
			return World->GetSubsystem<UGasSmCacheSubsystem>();
		}
	}
	return nullptr;
}

void UGasSmCacheSubsystem::StoreEventData(USMNodeInstance* TargetNodeInstance, const FGameplayEventData* EventData)
{

	TargetNodeInstance->GetStateMachineInstance()->OnStateMachineStateChangedEvent.AddUniqueDynamic(this, &UGasSmCacheSubsystem::OnStateChangedCleanData);

	FCachedSmGameplayEvent CachedData;

	CachedData.EventData = *EventData;

	EventMap.Add(TargetNodeInstance, CachedData);
	

}

void UGasSmCacheSubsystem::StoreEffectData(USMNodeInstance* TargetNodeInstance,
	const FCachedEffectApplication& EventData)
{
	TargetNodeInstance->GetStateMachineInstance()->OnStateMachineStateChangedEvent.AddUniqueDynamic(this, &UGasSmCacheSubsystem::OnStateChangedCleanData);

	EffectDataMap.Add(TargetNodeInstance, EventData);
}

void UGasSmCacheSubsystem::RemoveEventData(USMNodeInstance* TargetNodeInstance)
{
	EventMap.Remove(TargetNodeInstance);
}

void UGasSmCacheSubsystem::RemoveEffectData(USMNodeInstance* TargetNodeInstance)
{
	EffectDataMap.Remove(TargetNodeInstance);
}

bool UGasSmCacheSubsystem::GetTransitionDataGameplayEvent(USMNodeInstance* NodeInstance, FGameplayEventData& EventData)
{
	if (!NodeInstance || !NodeInstance->GetWorld())
	{
		return false;
	}

	UGasSmCacheSubsystem* Sub = NodeInstance->GetWorld()->GetSubsystem<UGasSmCacheSubsystem>();
	
	
	FCachedSmGameplayEvent* DataFound = Sub->EventMap.Find(NodeInstance);

	if (DataFound)
	{
		EventData = DataFound->EventData;
		return true;
	}

	return false;
}

bool UGasSmCacheSubsystem::GetTransitionDataGameplayEffect(USMNodeInstance* NodeInstance,
	FCachedEffectApplication& EffectData)
{
	if (!NodeInstance || !NodeInstance->GetWorld())
	{
		return false;
	}

	UGasSmCacheSubsystem* Sub = NodeInstance->GetWorld()->GetSubsystem<UGasSmCacheSubsystem>();

	return false;
}

bool UGasSmCacheSubsystem::GetTransitionDataSourceActor(USMNodeInstance* NodeInstance,
	AActor*& SourceActor)
{

	if (!NodeInstance || !NodeInstance->GetWorld())
	{
		return false;
	}

	UGasSmCacheSubsystem* Sub = NodeInstance->GetWorld()->GetSubsystem<UGasSmCacheSubsystem>();


	if (auto* Data = 	Sub->EventMap.Find(NodeInstance))
	{

		const AActor* Const = Data->EventData.Instigator;
		AActor* NoConstActor = const_cast<AActor*>(Const);
		SourceActor = NoConstActor;
		return true;
	}
	else if (auto* DataEffect = Sub->EffectDataMap.Find(NodeInstance))
	{
		
		SourceActor = DataEffect->SourceActor;
		if (SourceActor)
		{
			return true;

		}
		
	}


	return false;
}

void UGasSmCacheSubsystem::OnStateChangedCleanData(USMInstance* Instance, FSMStateInfo NewState, FSMStateInfo PreviousState)
{
	if (USMNodeInstance* NodeInstance = 	PreviousState.NodeInstance)
	{
		EventMap.Remove(NodeInstance);
		EffectDataMap.Remove(NodeInstance);
	}
}

void UGasSmCacheSubsystem::TryWriteLastTransition(USMTransitionInstance* Instance)
{
	if (LastTransitionWriteTarget)
	{
		*LastTransitionWriteTarget = Instance;
		LastTransitionWriteTarget = nullptr; //Clear out the Value
	}
}

void UGasSmCacheSubsystem::SendGameplayEventToActor_StateMachine(AActor* Actor, FGameplayTag EventTag,
                                                                 FGameplayEventData Payload, bool& bTransitionWasTaken, USMTransitionInstance*& TransitionTaken)
{
	if (!Actor)
	{
		bTransitionWasTaken = false;
		TransitionTaken = nullptr;
		return;
	}
	UGasSmCacheSubsystem* Sub = Actor->GetWorld()->GetSubsystem<UGasSmCacheSubsystem>();

	
	Payload.EventTag = EventTag; //Write the Tag to the payload.
	//UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Actor, EventTag, Payload);

	Sub->LastTransitionWriteTarget = &TransitionTaken; //We Point it to the Local Scope ptr
	
	if (::IsValid(Actor))
	{
		UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);
		if (AbilitySystemComponent != nullptr && IsValidChecked(AbilitySystemComponent))
		{
			FScopedPredictionWindow NewScopedWindow(AbilitySystemComponent, true);
			AbilitySystemComponent->HandleGameplayEvent(EventTag, &Payload);
		}
		else if (FVirtualTagData* Data = GetVirtualTagData(Actor, false))
		{
			Data->HandleGameplayEvent(EventTag, &Payload);
			
			//Old Logic
			
			/*if (bSendToSmIfNoGAS)
			{
				if (USMStateMachineComponent* Component = Actor->FindComponentByClass<USMStateMachineComponent>())
				{
					if (Component->GetInstance())
					{
						TArray<USMTransitionInstance*> Transitions;
						Component->GetInstance()->GetAllTransitionInstances(Transitions);
						for (auto* Element: Transitions)
						{
							if (Cast<UTransitionOnGameplayEvent>(Element) && Cast<UTransitionOnGameplayEvent>(Element)->IsInitialized())
							{
								Cast<UTransitionOnGameplayEvent>(Element)->SimulateEventCallback(EventTag, &Payload);
							}
						}
					}
				}
			}*/
			
		}
	}

	//Check if it still points to self
	if (Sub->LastTransitionWriteTarget == &TransitionTaken)
	{
		Sub->LastTransitionWriteTarget = nullptr;
	}
	
	bTransitionWasTaken = TransitionTaken != nullptr;
}

FVirtualTagData* UGasSmCacheSubsystem::GetVirtualTagData(const UObject* Object, bool AddIfMissing)
{
	UGasSmCacheSubsystem* Sub = UGasSmCacheSubsystem::Get(Object);

	if (!Sub)
	{
		return nullptr;
	}
	
	if (AddIfMissing)
	{
		return &Sub->VirtualTagContainers.FindOrAdd(Object);
	}
	else
	{
		return Sub->VirtualTagContainers.Find(Object);
	}
}
