// Fill out your copyright notice in the Description page of Project Settings.


#include "States/GasStateApplyEffect.h"

#include "AbilitySystemGlobals.h"
#include "GasSmCacheSubsystem.h"
#include "Transitions/TransitionExtensionBase.h"

void UGasStateApplyEffect::OnPreCompileValidate_Implementation(USMCompilerLog* CompilerLog) const
{
	Super::OnPreCompileValidate_Implementation(CompilerLog);

	
	
	
}

void UGasStateApplyEffect::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR

	if (FSMGraphProperty* GraphProperty = FindOrAddExposedPropertyOverrideByName(FName("CustomTarget")))
	{

		GraphProperty->bHidden = TargetMode != EEffectTargetOption::CustomTarget;

		
	}
#endif
}

void UGasStateApplyEffect::OnStateBegin_Implementation()
{
	Super::OnStateBegin_Implementation();


	UAbilitySystemComponent* TargetASC = nullptr;
	if (TargetMode == EEffectTargetOption::Self)
	{
		TargetASC = GetAbilitySystemComponent();
	}
	else if (TargetMode == EEffectTargetOption::CustomTarget)
	{
		TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(CustomTarget, false);
		
	}
	else if (TargetMode == EEffectTargetOption::TransitionSource)
	{

		AActor* SourceActor = nullptr;
		UGasSmCacheSubsystem::GetTransitionDataSourceActor(this, SourceActor);
		if (SourceActor)
		{
			TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(SourceActor, false);
		}
	}

	if (!TargetASC || !GetAbilitySystemComponent())
	{
		return;
	}


	CachedTargetASC = TargetASC;
	
	Handle = GetAbilitySystemComponent()->ApplyGameplayEffectToTarget(Effect->GetDefaultObject<UGameplayEffect>(), TargetASC, 1);
	if (!bRemoveOnEnd)
	{
		Handle.Invalidate();
	}
}

void UGasStateApplyEffect::OnStateEnd_Implementation()
{
	Super::OnStateEnd_Implementation();

	if (bRemoveOnEnd && CachedTargetASC && Handle.IsValid())
	{
		CachedTargetASC->RemoveActiveGameplayEffect(Handle);
		Handle.Invalidate();
		CachedTargetASC = nullptr;
	}
}

void UGasStateApplyEffect::UpdateLog(FString& Text)
{
	Super::UpdateLog(Text);
	
	if (TargetMode == EEffectTargetOption::TransitionSource)
	{
		bool bSourceIsProvided = false;
		
		TArray<USMTransitionInstance*> Transitions;
		GetIncomingTransitions(Transitions, false);
		for (auto* Trans: Transitions)
		{
		
			if (Cast<UTransitionExtensionBase>(Trans) && Cast<UTransitionExtensionBase>(Trans)->CanProvideSource())
			{
				bSourceIsProvided = true;
			}
		}

		if (!bSourceIsProvided)
		{
			Text.Append(TEXT("No Transition provides a Source!!"));
		}
	}
	
}
