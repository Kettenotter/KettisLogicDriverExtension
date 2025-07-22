#pragma once

#include "TransitionExtensionBase.h"
#include "TransitionOnGameplayTag.generated.h"


UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOnGameplayTag : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()

public:

	UTransitionOnGameplayTag(const FObjectInitializer& ObjectInitializer);

protected:

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;

	virtual bool TestCondition() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayTag Tag;

	/*UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, Category="Transition Custom")
	AActor* OptionalTarget;*/

	virtual void ConstructionScript_Implementation() override;


protected:
	
	FDelegateHandle DelegateHandle;

	virtual void TagChanged(const FGameplayTag CallbackTag, int32 NewCount) {TriggerUpdate();}

	virtual void Serialize(FArchive& Ar) override;
	
};

