// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "Nodes/States/SMStateInstance.h"
#include "Components/ActorComponent.h"
#include "State_SpawnParticleSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStateParticleFinishedSignature);

// Forward declare this class, so the header file knows it is valid
class UNiagaraSystem;


UENUM()
enum class EFinishType : uint8
{
	Spawned,
	Finished,
	Delay,
	FinishedOrDelay UMETA(Tooltip= "Will trigger the delegate either when the particle system has finished or the delay was triggered."),
};

UENUM()
enum class EExitBehavior : uint8
{
	None,
	DisableAndReleaseToPool UMETA(Tooltip="Will use the Pooling system. Either pool when the state leaves or when the particle system finishes."),
	Disable,
	Destroy,
	PooledOneShot
	
};

UENUM()
enum class ECharacterAttachment : uint8
{
	None UMETA(Tooltip="Default behavior -> uses the root component of the character."),
	CapsuleBottom UMETA(Tooltip="Attaches to the bottom of the capsule component."),
	SkeletalMesh UMETA(Tooltip= "Attaches to the skeletal mesh component of the Character"),
};

/**
 * 
 */
UCLASS(DisplayName="SpawnParticleSystem")
class KETTISLOGICDRIVEREXTENSION_API UState_SpawnParticleSystem : public USMStateInstance
{
	GENERATED_BODY()

public:
	/**
	 * Gets triggered depending on the exit condition.
	 */
	UPROPERTY(BlueprintAssignable)
	FStateParticleFinishedSignature OnStateParticleFinished;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	TObjectPtr<UNiagaraSystem> ParticleSystem;
	

	/**
	 * Provide an attachment component.
	 * If none is provided we will try to attach to the root of the context.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	USceneComponent* AttachComponent;

	/**
	 * If disabled will only use the transform of the Component and not attach it.
	 * The spawn transform will look the same if attachment is enabled or not!
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	uint8 bAttachToComp:1 = true;

	/**
	 * Will use the provided Transform as absolute!
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	uint8 bUseAbsoluteTransform:1 = false;

	/**
	 * The socket the particle system will attach to.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	FName Socket = NAME_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	FTransform SpawnTransform = FTransform::Identity;

	/**
	 * Controlls when the the Delegate OnStateParticleFinished is called
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Advanced")
	EFinishType ExitCondition = EFinishType::Finished;

	/**
	 * If the Exit Condition is delay will use the delay specified.
	 * TODO: Remove this?... Can just use a delay Transition instead.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Advanced")
	float Delay = 1.0f;

	/**
	 * What happens to the particle system when the state exits?
	 * Disabling will let the particle system finish and then destroy it.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ParticleSystem")
	EExitBehavior ExitBehavior = EExitBehavior::DisableAndReleaseToPool;

	/**
	 * While attached will ignore the rotation of the parent.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ParticleSystem")
	ECharacterAttachment CharacterAttachment = ECharacterAttachment::SkeletalMesh;
	
	/**
	 * While attached will ignore the rotation of the parent.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ParticleSystem")
	uint8 bAbsoluteRotation:1 = false;

	/**
	 * While attached will ignore the scale of the parent.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ParticleSystem")
	uint8 bAbsoluteScale:1 = true;

	/**
	 * 
	 */
	/*UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ParticleSystem")
	uint8 bPoolAndReleaseAfterLeaveState:1 = true;*/
	
	/**
	 * The system this State has spawned.
	 * Use this to set Niagara variables and so on.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ParticleSystem")
	TObjectPtr<UNiagaraComponent> SpawnedNiagaraSystem;

	UFUNCTION()
	void OnParticleFinished(UNiagaraComponent* PSystem);

	UPROPERTY()
	FTimerHandle TimerHandle;
	
protected:
	virtual void OnStateBegin_Implementation() override;
	virtual void OnStateEnd_Implementation() override;
};
