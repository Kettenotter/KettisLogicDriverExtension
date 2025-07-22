// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "GameplayEffectTypes.h"
#include "ExtraFilterOptions.generated.h"


USTRUCT(NotBlueprintable)
struct FExtraFilterOptionsBase
{
	GENERATED_BODY()
	virtual ~FExtraFilterOptionsBase() = default;

	
};

USTRUCT(BlueprintType, DisplayName= "Tags")
struct FExtraFilterOptionsTags : public FExtraFilterOptionsBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagQuery SourceTagFilter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagQuery ContextTagFilter;
	
	bool TestActorTags(const FTagContainerAggregator& TagsContext, const FTagContainerAggregator& TagsSource) const
	{
		if (!SourceTagFilter.IsEmpty() && !SourceTagFilter.Matches(TagsSource.GetActorTags()))
		{
			return false;
		}
		if (!ContextTagFilter.IsEmpty() && !ContextTagFilter.Matches(TagsContext.GetActorTags()))
		{
			return false;
		}

		return true;
		
	}
};

USTRUCT(NotBlueprintable)
struct FFilterOptionsActorTestBase : public  FExtraFilterOptionsBase
{
	GENERATED_BODY()

public:
	virtual bool TestActors(AActor* ContextActor, AActor* OtherActor) const
	{
		return false;
	}
};

USTRUCT(BlueprintType, DisplayName= "Distance")
struct FExtraFilterOptionsDistance : public FFilterOptionsActorTestBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDistanceToOther = 100000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinDistanceToOther = 0;
	
	virtual bool TestActors(AActor* ContextActor, AActor* OtherActor) const override
	{
		if (!ContextActor || !OtherActor)
		{
			return false;
		}

		const float Distance = (ContextActor->GetActorLocation() - OtherActor->GetActorLocation()).Length();

		if (Distance < MinDistanceToOther || Distance > MaxDistanceToOther)
		{
			return false;
		}
		return true;
	}
};