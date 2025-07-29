// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
ATurret::ATurret() {}
// Called every frame
void ATurret::Tick(float DeltaTime)
{

   Super::Tick(DeltaTime);

   if (InFireRange())
   {
      RotateTurret(TankRef->GetActorLocation());
   }
}

void ATurret::HandleDestruction()
{
   Super::HandleDestruction();
   Destroy();
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
   Super::BeginPlay();

   TankRef = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
   GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATurret::CheckFireCondition, FireRate, true);
}
void ATurret::CheckFireCondition()
{
   if (InFireRange())
   {
      Fire();
   }
}
bool ATurret::InFireRange()
{
   if (TankRef)
   {
      float Distance = FVector::Dist(GetActorLocation(), TankRef->GetActorLocation());
      if (Distance <= FireRange)
      {
         return true;
      }
   }
   return false;
}