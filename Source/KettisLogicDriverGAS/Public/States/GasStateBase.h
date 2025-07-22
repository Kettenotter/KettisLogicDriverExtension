// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMStateInstance.h"
#include "AbilitySystemComponent.h"
#include "SMTextGraphProperty.h"
#include "GasStateBase.generated.h"


inline uint8 GSerializeVersion_GasState = 0;
/**
 * 
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API UGasStateBase : public USMStateInstance
{
	GENERATED_BODY()

public:
	
	UAbilitySystemComponent* GetAbilitySystemComponent() const;


#if WITH_EDITORONLY_DATA

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Default", meta=(DisplayPriority= -5))
	FSMTextGraphProperty EditorLog;
	
	UPROPERTY()
	uint8 SerializeVersion = 0;
#endif

protected:

#if !LOGIC_DRIVER_GAS_CUSTOM_SERIALIZE
#define RETURN_IF_LOADING_VERSION_LOWER(VERSION) return;
#endif

#if LOGIC_DRIVER_GAS_CUSTOM_SERIALIZE
	#if WITH_EDITOR
	#define RETURN_IF_LOADING_VERSION_LOWER(VERSION) if (SerializeVersion < VERSION ) {return;}
	#else
	#define RETURN_IF_LOADING_VERSION_LOWER(VERSION) {}
	#endif
#endif
	

	
	virtual void ConstructionScript_Implementation() override;

	virtual void UpdateLog(FString& Text);

	virtual void Serialize(FArchive& Ar) override;
};
