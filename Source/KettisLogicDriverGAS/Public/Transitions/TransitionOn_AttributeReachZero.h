
#pragma once

#include "TransitionExtensionBase.h"
#include "TransitionOn_AttributeReachZero.generated.h"


/**
 * Takes the Transition once the Attribute reaches zero.
 */
UCLASS()
class KETTISLOGICDRIVERGAS_API UTransitionOn_AttributeReachZero : public UTransitionExtensionDelegateBinding
{
	GENERATED_BODY()

public:

	UTransitionOn_AttributeReachZero(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	FGameplayAttribute Attribute;

protected:
	

	FDelegateHandle DelegateHandle;

	virtual void BindDelegates() override;

	virtual void ClearDelegates() override;

	virtual bool TestCondition() override;
	
	virtual void AttributeChanged(const FOnAttributeChangeData& Data) {TriggerUpdate();}

#if WITH_EDITOR

	virtual bool ValidColor() override {return Attribute.IsValid();};
	
#endif
	
};