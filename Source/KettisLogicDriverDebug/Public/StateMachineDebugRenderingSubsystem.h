// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StateMachineDebugRenderingSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class KETTISLOGICDRIVERDEBUG_API UStateMachineDebugRenderingSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

	virtual bool IsTickableWhenPaused() const override;

	bool bDrawOnceOnPause;

	float Offset = 20.0f;
};
