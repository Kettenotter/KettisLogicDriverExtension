// Fill out your copyright notice in the Description page of Project Settings.


#include "States/GasStateAddLooseTag.h"

#include "AbilitySystemComponent.h"
#include "GasSmCacheSubsystem.h"
#include "LogicDriverGasBlueprintLibrary.h"
#include "TagAccessors.h"

void UGasStateAddLooseTag::OnStateBegin_Implementation()
{
	Super::OnStateBegin_Implementation();
	if (UAbilitySystemComponent* GAS = GetAbilitySystemComponent())
	{
		for (const FGameplayTag& Tag : TagsToAdd)
		{
			if (bReplicate)
			{
				if (bAdditive)
				{
					GAS->AddReplicatedLooseGameplayTag(Tag);

				}
				else
				{
					GAS->SetReplicatedLooseGameplayTagCount(Tag, 1);

				}

			}
			else
			{

				if (bAdditive)
				{
					GAS->AddLooseGameplayTag(Tag);
				}
				else
				{
					GAS->AddLooseGameplayTag(Tag, 1);

				}
			}
		}
	}
	else if (GetContext())
	{
		if (bAdditive)
		{
			UGasSmCacheSubsystem::GetVirtualTagData(GetContext(), true)->GameplayTagCountContainer.UpdateTagCount(TagsToAdd, 1);

		}
		else
		{
			FGameplayTagCountContainer& Data = UGasSmCacheSubsystem::GetVirtualTagData(GetContext(), true)->GameplayTagCountContainer;
			for (const FGameplayTag& Tag : TagsToAdd)
			{
				if (Data.GetExplicitTagCount(Tag) <= 0)
				{
					Data.UpdateTagCount(TagsToAdd, 1);
				}
					
			}
		}
	}
}

void UGasStateAddLooseTag::OnStateEnd_Implementation()
{
	Super::OnStateEnd_Implementation();
	if (!bRemoveOnExit)
	{
		return;
	}
	if (UAbilitySystemComponent* GAS = GetAbilitySystemComponent())
	{
		for (auto& tag : TagsToAdd)
		{
			if (bReplicate)
			{
				if (bAdditive)
				{
					GAS->RemoveReplicatedLooseGameplayTag(tag);

				}
				else
				{
					GAS->SetReplicatedLooseGameplayTagCount(tag, 0);

				}

			}
			else
			{

				if (bAdditive)
				{
					GAS->RemoveLooseGameplayTag(tag);
				}
				else
				{
					GAS->SetLooseGameplayTagCount(tag, 0);

				}
			}
		}
	}
	else if (GetContext())
	{
		if (bAdditive)
		{
			UGasSmCacheSubsystem::GetVirtualTagData(GetContext(), true)->GameplayTagCountContainer.UpdateTagCount(TagsToAdd, -1);

		}
		else
		{
			FGameplayTagCountContainer& Data = UGasSmCacheSubsystem::GetVirtualTagData(GetContext(), true)->GameplayTagCountContainer;
			for (const FGameplayTag& Tag : TagsToAdd)
			{
				if (Data.GetExplicitTagCount(Tag) > 0)
				{
					Data.UpdateTagCount(TagsToAdd, Data.GetExplicitTagCount(Tag) * -1);
				}
					
			}
		}
			
	}
	
}

void UGasStateAddLooseTag::Serialize(FArchive& Ar)
{
	
	Super::Serialize(Ar);
	
	return;

	RETURN_IF_LOADING_VERSION_LOWER(1)
	
	// Manually pack bits into a byte
	uint8 PackedBits = 0;
	if (Ar.IsSaving())
	{
		PackedBits |= bAdditive << 0;
		PackedBits |= bReplicate << 1;
		PackedBits |= bRemoveOnExit << 2;
		// ... (add more flags)
		Ar << PackedBits; // Write 1 byte
	}
	else if (Ar.IsLoading())
	{
		Ar << PackedBits; // Read 1 byte
		bAdditive = (PackedBits & (1 << 0)) != 0;
		bReplicate = (PackedBits & (1 << 1)) != 0;
		bRemoveOnExit = (PackedBits & (1 << 2)) != 0;
		// ... (extract more flags)
	}

	if (Ar.IsSaving())
	{
		TArray<FGameplayTag> Tags = TagsToAdd.GetGameplayTagArray();
		Ar << Tags;
	}
	else if (Ar.IsLoading())
	{
		TArray<FGameplayTag> Tags;
		Ar << Tags;
		TagsToAdd = FGameplayTagContainer::CreateFromArray(Tags);
	}
}
