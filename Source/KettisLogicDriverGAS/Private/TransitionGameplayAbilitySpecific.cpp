// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\TransitionGameplayAbilitySpecific.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"


void UTransitionOnCanPayMana::OnPreCompileValidate_Implementation(USMCompilerLog* CompilerLog) const
{
	Super::OnPreCompileValidate_Implementation(CompilerLog);

#if !WITH_KETTENOTTER_SPECIFIC 
	CompilerLog->Log(ESMCompilerLogType::Error, TEXT("This node uses project specific Logic and you will need to implement your own code to make it working."));
#endif
}

UTransitionOnCanPayMana::UTransitionOnCanPayMana(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetEditorIconFromDataTable(FName("CanPayMana"));
}


#if WITH_KETTENOTTER_SPECIFIC

#include "AsmAttributeSetCore.h"
#include "AsmAttributeSetCreature.h"

void UTransitionOnCanPayMana::BindDelegates()
{
	Super::BindDelegates();

	if (DelegateHandle.IsValid())
	{
		return;
	}
	if (UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		if (const UAsmAttributeSetCreature* CreatureSet = Cast<UAsmAttributeSetCreature>(AbilitySystemComponent->GetAttributeSet(UAsmAttributeSetCore::StaticClass())))
		{
			DelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CreatureSet->GetAbilityPointsAttribute()).AddUObject(this, &UTransitionOnCanPayMana::AttributeChanged);
			
			
		}

		
	}
}

void UTransitionOnCanPayMana::ClearDelegates()
{
	Super::ClearDelegates();

	if (!DelegateHandle.IsValid())
	{
		return;
	}
	
	if (UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		if (const UAsmAttributeSetCreature* CreatureSet = Cast<UAsmAttributeSetCreature>(AbilitySystemComponent->GetAttributeSet(UAsmAttributeSetCore::StaticClass())))
		{
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CreatureSet->GetAbilityPointsAttribute()).Remove(DelegateHandle);
			DelegateHandle.Reset();
			
		}
		
	}
}

bool UTransitionOnCanPayMana::TestCondition()
{
	
	if (const UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Cast<AActor>(GetContext()), false))
	{
		if (const UAsmAttributeSetCreature* CreatureSet = Cast<UAsmAttributeSetCreature>(AbilitySystemComponent->GetAttributeSet(UAsmAttributeSetCreature::StaticClass())))
		{
			if (CreatureSet->GetAbilityPoints() >= CreatureSet->GetMaxAbilityPoints() - 0.001)
			{
				
				return true;
				
				
			}
			
		}

		
	}
	return false;
}

#endif