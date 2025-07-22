// Fill out your copyright notice in the Description page of Project Settings.


#include "States/GasStateBase.h"

#include "AbilitySystemInterface.h"


UAbilitySystemComponent* UGasStateBase::GetAbilitySystemComponent() const
{
	const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(GetContext());
	if (ASI)
	{
		return ASI->GetAbilitySystemComponent();
	}
	return nullptr;
}

void UGasStateBase::ConstructionScript_Implementation()
{
	Super::ConstructionScript_Implementation();

#if WITH_EDITOR
	
	FString Text;
	UpdateLog(Text);

	EditorLog.Result = FText::FromString(Text);
	
	if (FSMGraphProperty* GraphProperty = FindOrAddExposedPropertyOverrideByName(FName("EditorLog")))
    {
		GraphProperty->bHidden = Text.IsEmpty();
		EditorLog.WidgetInfo.BackgroundColor = FLinearColor::Red;
		EditorLog.bIsInArray = Text.IsEmpty();
		
    }

	//EditorLog.WidgetInfo.EditableTextStyle.EditableTextBoxStyle.ForegroundColor = FColor::Red;
#endif
	
}

void UGasStateBase::UpdateLog(FString& Text)
{
	
}

void UGasStateBase::Serialize(FArchive& Ar)
{
#if WITH_EDITOR
	if (Ar.IsSaving())
	{
		SerializeVersion = 	SerializeVersion = LOGIC_DRIVER_GAS_CUSTOM_SERIALIZE ? GSerializeVersion_GasState : 0;
	}
#endif
	
	Super::Serialize(Ar);
	
}
