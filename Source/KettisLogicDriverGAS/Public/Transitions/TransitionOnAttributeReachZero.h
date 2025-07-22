
#pragma once

#include "TransitionExtensionBase.h"
#include "TransitionOnAttributeReachZero.generated.h"

UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOnAttributeReachZero : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()

public:

	UTransitionOnAttributeReachZero(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayAttribute Attribute;

protected:
	

	FDelegateHandle DelegateHandle;

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;

	virtual bool TestCondition() override;
	
	virtual void AttributeChanged(const FOnAttributeChangeData& Data) {TriggerUpdate();}
	
};