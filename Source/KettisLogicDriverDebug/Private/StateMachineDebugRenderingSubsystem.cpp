// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineDebugRenderingSubsystem.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "LogicDriverGasBlueprintLibrary.h"
#include "SMInstance.h"
#include "SMStateInstance.h"


static TAutoConsoleVariable<bool> CVarDrawStateMachineDebug(
	TEXT("StateMachineExtension.DrawDebug"),
	false, //Default Value
	TEXT("Draw each state machine in the world and their active states.")
);
static TAutoConsoleVariable<bool> CVarDrawStateMachineDebugTags(
	TEXT("StateMachineExtension.DrawDebug.DrawTags"),
	true, //Default Value
	TEXT("Draws the text each state machine has.")
);

static TAutoConsoleVariable<bool> CVarDrawStateMachineDebugSingle(
	TEXT("StateMachineExtension.DrawDebug.SingleStateMachine"),
	true, //Default Value
	TEXT("Only debug one state machine at a time.")
);

void UStateMachineDebugRenderingSubsystem::Tick(float DeltaTime)
{
	if (!CVarDrawStateMachineDebug.GetValueOnGameThread())
	{
		return;
	}

	bool bShouldDrawString = true;
	if (GetWorld()->IsPaused() && bDrawOnceOnPause)
	{
		//return;
		bShouldDrawString = false;
	}
	
	bDrawOnceOnPause = GetWorld()->IsPaused();


	bool bBestMatchSingle = CVarDrawStateMachineDebugSingle.GetValueOnGameThread();
	
	AActor* BestMatch = nullptr;
	USMInstance* BestMatchInstance = nullptr;
	
	float BestMatchDot = 0.95f;
	float IgnoreDistance = 40.0f;

	TArray<AActor*> AnyActiveActors;
	TMap<AActor*, int32> AmountOfStateMachinesFirst;
	
	for (TObjectIterator<USMInstance> StateMachineIt; StateMachineIt; ++StateMachineIt)
	{
		USMInstance* StateMachine = *StateMachineIt;
		if (StateMachine->GetWorld() != GetWorld() )
		{
			continue;
		}

		AActor* ActorContext = Cast<AActor>(StateMachine->GetContext());

		if (!ActorContext)
		{
			continue;
		}

		if (UAbilitySystemComponent* GAS = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(ActorContext))
		{
			if (GAS->GetAvatarActor())
			{
				ActorContext = GAS->GetAvatarActor();
				
			}
		}
		int32& Amount = AmountOfStateMachinesFirst.FindOrAdd(ActorContext);
	
		
		FVector WorldLocation = ActorContext->GetActorLocation();
		if (bBestMatchSingle)
		{
			WorldLocation += FVector(0, 0, Offset) * Amount;
		}
		Amount += 1;
		
		APlayerCameraManager* CameraManager = GetWorld()->GetFirstPlayerController() ? GetWorld()->GetFirstPlayerController()->PlayerCameraManager : nullptr;

		if (!CameraManager)
		{
			continue;
		}
		if (!StateMachine->IsInEndState())
		{
			AnyActiveActors.Add(ActorContext);
		}
		
		if (FVector::Dist(WorldLocation * 0.2, CameraManager->GetCameraLocation() * 0.2) < IgnoreDistance)
		{
			continue;
		}
		if (CameraManager)
		{
			FVector NormalToLocation = FVector(WorldLocation - CameraManager->GetCameraLocation()).GetSafeNormal();

			if (CameraManager->GetActorForwardVector().Dot(NormalToLocation) > BestMatchDot)
			{
				if (bBestMatchSingle)
				{
					BestMatchInstance = StateMachine;
				}
				else
				{
					BestMatch = Cast<AActor>(StateMachine->GetContext());

				}
				BestMatchDot = CameraManager->GetActorForwardVector().Dot(NormalToLocation);
			}
		}
	}

	TArray<AActor*> NoStrings;
	TMap<AActor*, FString> DebugStrings;

	TMap<AActor*, FVector> DebugStringLocation;

	TMap<AActor*, int32> AmountOfStateMachines;
	
	for (TObjectIterator<USMInstance> StateMachineIt; StateMachineIt; ++StateMachineIt)
	{
		USMInstance* StateMachine = *StateMachineIt;
		if (StateMachine->GetWorld() != GetWorld() )
		{
			continue;
		}
		
		AActor* ActorContext = Cast<AActor>(StateMachine->GetContext());

		if (!ActorContext)
		{
			continue;
		}

		if (UAbilitySystemComponent* GAS = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(ActorContext))
		{
			if (GAS->GetAvatarActor())
			{
				ActorContext = GAS->GetAvatarActor();
				
			}
		}
		
		bool bDrawDetails = bBestMatchSingle ? StateMachine == BestMatchInstance : ActorContext == BestMatch;

		

		if (!ActorContext)
		{
			continue;
		}
		
		FColor Color = StateMachine->IsInEndState() ? FColor::Red : FColor::Green;
		float Size = bDrawDetails ? 5.0f : 1.0f;

		int32& Amount = AmountOfStateMachines.FindOrAdd(ActorContext);
		//DrawDebugPoint(GetWorld(), ActorContext->GetActorLocation(), Size, Color, false, 0.001);
		DrawDebugSphere(GetWorld(), ActorContext->GetActorLocation() + FVector(0, 0, Offset) * Amount, 12, 4, Color, false, 0.001f, 1, Size);

		if (bBestMatchSingle && bDrawDetails)
		{
			DebugStringLocation.Add(ActorContext, ActorContext->GetActorLocation() + FVector(0, 0, Offset) * Amount);
		}
		
		//NoStrings.Add(ActorContext);
		Amount += 1;
		/*if (!NoStrings.Contains(ActorContext))
		{
			
		}*/
		
		if (!bDrawDetails)
		{
			continue;
		}
		FString Text = StateMachine->GetArchetype()->GetName();
		for (auto ActiveState : StateMachine->GetAllActiveStates())
		{
			Text += FString("\n >") + ActiveState->GetNodeName() + "| " + FString::Printf(TEXT("%.1f"), ActiveState->GetActiveTime()) + "s";
		}

		if (DebugStrings.Contains(ActorContext))
		{
			Text = FString("\n") + Text;
		}

		DebugStrings.FindOrAdd(ActorContext).Append(Text);
		//DrawDebugString(GetWorld(), ActorContext->GetActorLocation() + FVector(0, 0, 40), Text, nullptr, FColor::White, 0.0001, true, 1);
	}
	

	if (APlayerCameraManager* CameraManager = GetWorld()->GetFirstPlayerController() ? GetWorld()->GetFirstPlayerController()->PlayerCameraManager : nullptr)
	{
		DrawDebugPoint(GetWorld(), CameraManager->GetActorForwardVector() * 100.0f + CameraManager->GetCameraLocation(), 5, FColor::White, false, 0.001f, 1);
		 
	}
	if (bShouldDrawString)
	{
		for (auto ToDraw : DebugStrings)
		{
			FVector Location = ToDraw.Key->GetActorLocation();
			if (DebugStringLocation.Contains(ToDraw.Key))
			{
				Location = DebugStringLocation[ToDraw.Key];
			}
			if (APlayerCameraManager* CameraManager = GetWorld()->GetFirstPlayerController() ? GetWorld()->GetFirstPlayerController()->PlayerCameraManager : nullptr)
			{
				DrawDebugLine(GetWorld(), CameraManager->GetActorForwardVector() * 300.0f + CameraManager->GetCameraLocation(), Location, FColor(255, 255, 255, 50), false, 0.001f, 1, 0.4);
		 
			}
			DrawDebugString(GetWorld(), Location, ToDraw.Value, nullptr, FColor::White, 0.0001, true, 1);

			if (CVarDrawStateMachineDebugTags.GetValueOnGameThread())
			{
				FGameplayTagContainer Tags = ULogicDriverGasBlueprintLibrary::GetTags_StateMachine(ToDraw.Key);
				if (!Tags.IsEmpty())
				{
					FString TagString = FString();
					for (FGameplayTag Tag : Tags.GetGameplayTagArray())
					{
						if (!TagString.IsEmpty())
						{
							TagString += FString("\n");
						}
						TagString += Tag.ToString();
					}
					float OffsetText = 30;
					if (APlayerCameraManager* CameraManager = GetWorld()->GetFirstPlayerController() ? GetWorld()->GetFirstPlayerController()->PlayerCameraManager : nullptr)
					{
						float Distance = FVector::Dist(CameraManager->GetCameraLocation(), ToDraw.Key->GetActorLocation());
						TArray<FString> Lines;
						ToDraw.Value.ParseIntoArray(Lines, TEXT("\n"), true);
						OffsetText = Distance * 0.0235f * Lines.Num();
						// Offset by the other line numbers

						OffsetText += Distance * 0.01f;
					}

					FColor Color = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(ToDraw.Key, false) ? FColor::Cyan : FColor::Green;
					if (UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(ToDraw.Key, false))
					{
						
					}
					DrawDebugString(GetWorld(), Location - FVector(0,0, OffsetText), TagString, nullptr, Color, 0.0001, true, 1);
				
				}
			}
			
		}
	}

	
}

TStatId UStateMachineDebugRenderingSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FStateMachineDebugDrawTicker, STATGROUP_Tickables );

}

bool UStateMachineDebugRenderingSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

bool UStateMachineDebugRenderingSubsystem::IsTickableWhenPaused() const
{
	return true;
}
