// Fill out your copyright notice in the Description page of Project Settings.

#include "TanksAndTurretsGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Turret.h"
#include "TanksAndTurretsPlayerController.h"
void ATanksAndTurretsGameMode::BeginPlay()
{
   Super::BeginPlay();
   ATanksAndTurretsGameMode::HandleDelayStart();
}
void ATanksAndTurretsGameMode::HandleDelayStart()
{
   Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
   TanksAndTurretsPlayerController = Cast<ATanksAndTurretsPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
   if (TanksAndTurretsPlayerController)
   {
      TanksAndTurretsPlayerController->SetPlayerEnabledState(false);

      FTimerHandle PlayerEnableTimerHandle;
      FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
          TanksAndTurretsPlayerController,
          &ATanksAndTurretsPlayerController::SetPlayerEnabledState,
          true);
      GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
                                      PlayerEnableTimerDelegate,
                                      StartDelay,
                                      false);
   }
}

void ATanksAndTurretsGameMode::ActorDied(AActor *DeadActor)
{
   if (DeadActor == Tank)
   {
      Tank->HandleDestruction();
      if (TanksAndTurretsPlayerController)
      {
         TanksAndTurretsPlayerController->SetPlayerEnabledState(false);
      }
   }
   else if (ATurret *DestroyedTurret = Cast<ATurret>(DeadActor))
   {
      DestroyedTurret->HandleDestruction();
   }
}