// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions/TransitionOn_GameplayEffect.h"

#include "GasSmCacheSubsystem.h"
#include "ISMEditorGraphNodeInterface.h"
#include "SMNode_Base.h"
#include "SMStateInstance.h"
#include "SMUtils.h"
#include "TransitionFilter/ExtraFilterOptions.h"


UTransitionOn_GameplayEffect::UTransitionOn_GameplayEffect(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	SetCanEvaluate(false);

	if (Cast<UTransitionOn_GameplayEffect>(ObjectInitializer.GetArchetype()))
	{
		EffectTransitionData = Cast<UTransitionOn_GameplayEffect>(ObjectInitializer.GetArchetype())->EffectTransitionData;
	}
	if (Cast<UTransitionOn_GameplayEffect>(GetDefault<UTransitionOn_GameplayEffect>(ObjectInitializer.GetClass())))
	{
		EffectTransitionData = Cast<UTransitionOn_GameplayEffect>(GetDefault<UTransitionOn_GameplayEffect>(ObjectInitializer.GetClass()))->EffectTransitionData;
	}

	
}

void UTransitionOn_GameplayEffect::OnRootStateMachineStart_Implementation()
{
	Super::OnRootStateMachineStart_Implementation();

	//Frees the memory.
	EffectTransitionData.Reset();
}

FTransitionOnGameplayEffectSparseData UTransitionOn_GameplayEffect::GetOptionalData(FTransitionOnGameplayEffectSparseData& MyData, bool& bIsSet, bool& bIsSetTemplate)
{
	
	bIsSet = EffectTransitionData.IsSet();
	MyData = EffectTransitionData.Get(FTransitionOnGameplayEffectSparseData());
	bIsSetTemplate = false;


	if (UTransitionOn_GameplayEffect* Template =	UTransitionExtensionBase::GetTemplateAs<UTransitionOn_GameplayEffect>())
	{

		if (Template->EffectTransitionData.IsSet())
		{
			bIsSetTemplate = true;
			return Template->EffectTransitionData.GetValue();
		}
			
	}
	return FTransitionOnGameplayEffectSparseData();
}

void UTransitionOn_GameplayEffect::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

	
#if WITH_EDITOR

	if (!IsEditorExecution())
	{
		return;
	}

	if (!EffectTransitionData.IsSet())
	{
		EffectTransitionData = FTransitionOnGameplayEffectSparseData();
	}
	
	SetEditorIconFromDataTable(FName("Effect"));
	
	if (!EffectTransitionData.IsSet())
	{
		NodeIconTintColor = FColor::White;
		NodeIconTintColor.A = 0.2;
	}
	else
	{
		NodeIconTintColor = FColor::White;
		NodeIconTintColor.A = 1;
	}

	FString DisplayName = TEXT("Effect");
	if (EffectTransitionData)
	{
		if (EffectTransitionData->EffectTag.IsValid())
		{
			DisplayName += " <Tag> ";
			DisplayName += EffectTransitionData->EffectTag.ToString() + " ";
		}
		
		if (!EffectTransitionData->EffectTagFilter.IsEmpty())
		{
			DisplayName += " <Query> " + EffectTransitionData->EffectTagFilter.GetDescription() + " ";
		}
		

		if (EffectTransitionData->EffectClassFilter)
		{
			DisplayName += " <Class> " + EffectTransitionData->EffectClassFilter->GetName() + " ";

		}
	}
	SetTransitionName(DisplayName);
#endif

}

void UTransitionOn_GameplayEffect::OnTransitionInitialized_Implementation()
{
	Super::OnTransitionInitialized_Implementation();

	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		/*OnApplyGameplayEffectCallbackDelegateHandle =*/
		if (Target == EEffectTransitionType::AppliedToSelf)
		{
			ASC->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UTransitionOn_GameplayEffect::OnApplyGameplayEffectCallback);

		}
		else if (Target == EEffectTransitionType::AppliedFromSelf)
		{
			ASC->OnGameplayEffectAppliedDelegateToTarget.AddUObject(this, &UTransitionOn_GameplayEffect::OnApplyGameplayEffectCallback);
		}
	}
}

void UTransitionOn_GameplayEffect::OnTransitionShutdown_Implementation()
{
	Super::OnTransitionShutdown_Implementation();

	/*if (!OnApplyGameplayEffectCallbackDelegateHandle.IsValid())
	{
		return;
	}*/
	
	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		ASC->OnGameplayEffectAppliedDelegateToSelf.RemoveAll(this);
	}
	
}


void UTransitionOn_GameplayEffect::OnApplyGameplayEffectCallback(UAbilitySystemComponent* inTarget,
                                                                const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle)
{
	UTransitionOn_GameplayEffect* Template =	GetTemplateAs<class UTransitionOn_GameplayEffect>();

	if (!Template || !Template->EffectTransitionData.IsSet())
	{
		return;
	}

	const FTransitionOnGameplayEffectSparseData& Data = *Template->EffectTransitionData;

	if (Data.EffectTag.IsValid() && !SpecApplied.Def->GetAssetTags().HasTag(Data.EffectTag))
	{
		return;
	}
	if (!Data.EffectTagFilter.IsEmpty() && !Data.EffectTagFilter.Matches(SpecApplied.Def->GetAssetTags()))
	{
		return;
	}

	if (!Data.SourceTagFilter.IsEmpty() && !Data.SourceTagFilter.Matches(SpecApplied.CapturedSourceTags.GetActorTags()))
	{
		return;
	}

	if (!Data.TargetTagFilter.IsEmpty() && !Data.TargetTagFilter.Matches(SpecApplied.CapturedTargetTags.GetActorTags()))
	{
		return;
	}
	
	if (Data.EffectClassFilter)
	{
		if (SpecApplied.Def && !SpecApplied.Def.IsA(Template->EffectTransitionData->EffectClassFilter))
		{
			return;
		}
	}

	for (auto& ExtraFilter : Data.FilterOptions)
	{
		if (!ExtraFilter.IsValid())
		{
			continue;
		}

		if (const FFilterOptionsActorTestBase* ActorTest = ExtraFilter.GetPtr<FFilterOptionsActorTestBase>())
		{
			if (!ActorTest->TestActors(Cast<AActor>(GetContext()), SpecApplied.GetContext().GetInstigator()))
			{
				return;
			}
		}
	}
	
	AActor* AvatarActor = inTarget ? inTarget->GetAvatarActor_Direct() : nullptr;
	


	FGameplayEffectSpecHandle SpecHandle(new FGameplayEffectSpec(SpecApplied));

	
	FCachedEffectApplication CachedData;
	CachedData.SourceActor = AvatarActor;
	CachedData.SpecHandle = SpecHandle;
	CachedData.ActiveHandle = ActiveHandle;
	
	GetWorld()->GetSubsystem<UGasSmCacheSubsystem>()->StoreEffectData(Cast<USMStateInstance>(GetNextStateInstance()), CachedData);

	SetToTrueAndEvaluate();
}

void UTransitionOn_GameplayEffect::Serialize(FArchive& Ar)
{
	//Clear out defaults to save memory.
	if (Ar.IsCooking())
	{
		if (EffectTransitionData.IsSet() && EffectTransitionData == FTransitionOnGameplayEffectSparseData())
		{
			EffectTransitionData.Reset();
		}
	}
	Super::Serialize(Ar);
	
	RETURN_IF_LOADING_VERSION_LOWER(1)
	Ar.SerializeBits(&Target, 4);
	//Ar << Target;
	//EffectTransitionData.Serialize(Ar);
	
}


/*
const FTransitionOnGameplayEffectSparseData& UTransitionOnGameplayEffect::GetSparseClassData()
{
	return  *static_cast<const FTransitionOnGameplayEffectSparseData*>(GetClass()->GetSparseClassData(EGetSparseClassDataMethod::ArchetypeIfNull));
	
}
*/
