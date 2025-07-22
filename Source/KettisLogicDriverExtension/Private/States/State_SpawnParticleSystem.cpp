// Fill out your copyright notice in the Description page of Project Settings.


#include "States/State_SpawnParticleSystem.h"
#include "Components/SceneComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"


void UState_SpawnParticleSystem::OnStateBegin_Implementation()
{
	Super::OnStateBegin_Implementation();
	if (!ParticleSystem)
	{
		OnStateParticleFinished.Broadcast();
		return;
	}
	USceneComponent* FoundAttachComponent = AttachComponent;

	ECharacterAttachment FoundCharacterAttachment = ECharacterAttachment::None;
	if (FoundAttachComponent == nullptr)
	{
		if (Cast<AActor>(GetContext()))
		{
			if (Cast<ACharacter>(GetContext()) && CharacterAttachment != ECharacterAttachment::None)
			{
				if (CharacterAttachment == ECharacterAttachment::CapsuleBottom)
				{
					FoundAttachComponent = Cast<ACharacter>(GetContext())->GetCapsuleComponent();
					FoundCharacterAttachment = ECharacterAttachment::CapsuleBottom;

				}
				else if (CharacterAttachment == ECharacterAttachment::SkeletalMesh)
				{
					FoundAttachComponent = Cast<ACharacter>(GetContext())->GetMesh();
					FoundCharacterAttachment = ECharacterAttachment::SkeletalMesh;
				}
			}
			else
			{
				FoundAttachComponent = Cast<AActor>(GetContext())->GetRootComponent();

			}
		}
	}
	
	if (!FoundAttachComponent)
	{
		OnStateParticleFinished.Broadcast();
		return;
	}

	FTransform AttachmentTransform = SpawnTransform;
	
	if (!bUseAbsoluteTransform)
	{
		
		if (FoundCharacterAttachment == ECharacterAttachment::CapsuleBottom)
		{
			AttachmentTransform.AddToTranslation(FVector(0, 0, -Cast<UCapsuleComponent>(FoundAttachComponent)->GetUnscaledCapsuleHalfHeight()));
		}
		
		//Relative to World.
		AttachmentTransform = FoundAttachComponent->GetSocketTransform(Socket) * AttachmentTransform;

		if (bAbsoluteRotation)
		{
			AttachmentTransform.SetRotation(SpawnTransform.GetRotation());
		}
		if (bAbsoluteScale)
		{
			AttachmentTransform.SetScale3D(SpawnTransform.GetScale3D());
		}
	}
	
	FFXSystemSpawnParameters SpawnParams;
	SpawnParams.SystemTemplate = ParticleSystem;
	SpawnParams.WorldContextObject = GetContext();
	SpawnParams.AttachToComponent = bAttachToComp ? FoundAttachComponent : nullptr;
	SpawnParams.AttachPointName = Socket;
	SpawnParams.Location = AttachmentTransform.GetLocation();
	SpawnParams.Rotation = FRotator(AttachmentTransform.GetRotation());
	SpawnParams.Scale = AttachmentTransform.GetScale3D();
	SpawnParams.LocationType = EAttachLocation::Type::KeepRelativeOffset; //We will apply the transform ourself after the spawn.
	SpawnParams.bAutoDestroy = true;
	SpawnParams.bAutoActivate = true;
	SpawnParams.PoolingMethod = ExitBehavior == EExitBehavior::PooledOneShot ? ToPSCPoolMethod(ENCPoolMethod::AutoRelease) : (ExitBehavior == EExitBehavior::DisableAndReleaseToPool ? ToPSCPoolMethod(ENCPoolMethod::ManualRelease) : ToPSCPoolMethod(ENCPoolMethod::None));
	SpawnParams.bPreCullCheck = false;

	if (bAttachToComp)
	{
		SpawnedNiagaraSystem = UNiagaraFunctionLibrary::SpawnSystemAttachedWithParams(SpawnParams);

	}
	else
	{
		SpawnedNiagaraSystem = UNiagaraFunctionLibrary::SpawnSystemAtLocationWithParams(SpawnParams);

	}

	if (!SpawnedNiagaraSystem)
	{
		return;
	}

	if (bAttachToComp)
	{
		if (bAbsoluteScale)
		{
			SpawnedNiagaraSystem->SetUsingAbsoluteScale(true);
		
		}
		if (bAbsoluteRotation)
		{
			SpawnedNiagaraSystem->SetUsingAbsoluteRotation(true);
		}
	}
	

	SpawnedNiagaraSystem->SetWorldTransform(AttachmentTransform);
	
	if (ExitCondition == EFinishType::Spawned)
	{
		OnStateParticleFinished.Broadcast();
	}

	if (ExitBehavior == EExitBehavior::PooledOneShot)
	{
		auto LamdbdaFunction = [this]()
		{
			SpawnedNiagaraSystem = nullptr;
		};

		GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateWeakLambda(this, LamdbdaFunction));
	}
	else
	{
		SpawnedNiagaraSystem->OnSystemFinished.AddUniqueDynamic(this, &UState_SpawnParticleSystem::OnParticleFinished);

		if (ExitCondition == EFinishType::Delay || ExitCondition == EFinishType::FinishedOrDelay)
		{
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
				OnStateParticleFinished.Broadcast();
			}, Delay, false);
		}
		
	}
	
	
	
	
}

void UState_SpawnParticleSystem::OnParticleFinished(UNiagaraComponent* PSystem)
{
	ensure(PSystem == SpawnedNiagaraSystem);
	
	if (ExitBehavior == EExitBehavior::DisableAndReleaseToPool)
	{
		//SpawnedNiagaraSystem->ReleaseToPool();

		//Make sure its pooled even when it finishes by itself!
		SpawnedNiagaraSystem->PoolingMethod = ENCPoolMethod::ManualRelease_OnComplete;

		SpawnedNiagaraSystem = nullptr;

		auto LamdbdaFunction = [this]()
		{
			//Clear Delegate
			if (IsValid(SpawnedNiagaraSystem))
			{
				SpawnedNiagaraSystem->OnSystemFinished.RemoveDynamic(this, &UState_SpawnParticleSystem::OnParticleFinished);

			}
		};

		GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateWeakLambda(this, LamdbdaFunction));
	}
	


	if (ExitCondition == EFinishType::Finished || ExitCondition == EFinishType::FinishedOrDelay)
	{
		OnStateParticleFinished.Broadcast();
	}
}

void UState_SpawnParticleSystem::OnStateEnd_Implementation()
{
	Super::OnStateEnd_Implementation();

	if (ExitBehavior != EExitBehavior::PooledOneShot)
	{
		if (IsValid(SpawnedNiagaraSystem))
		{
		
			SpawnedNiagaraSystem->OnSystemFinished.RemoveDynamic(this, &UState_SpawnParticleSystem::OnParticleFinished);

			if (ExitBehavior == EExitBehavior::DisableAndReleaseToPool)
			{
				SpawnedNiagaraSystem->ReleaseToPool();
			}
			else if (ExitBehavior == EExitBehavior::Disable)
			{
				SpawnedNiagaraSystem->Deactivate();
			}
			else if (ExitBehavior == EExitBehavior::Destroy)
			{
				SpawnedNiagaraSystem->DeactivateImmediate();
			}
		
			SpawnedNiagaraSystem == nullptr;
		}
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}

}
