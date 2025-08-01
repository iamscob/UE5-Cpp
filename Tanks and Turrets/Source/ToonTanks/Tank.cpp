// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
   SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
   SpringArm->SetupAttachment(RootComponent);

   Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
   Camera->SetupAttachment(SpringArm);
}
void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) // Input Bindings
{
   Super::SetupPlayerInputComponent(PlayerInputComponent);
   PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
   PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
   PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);

   if (TankPlayerController)
   {
      FHitResult HitResult;
      TankPlayerController->GetHitResultUnderCursor(
          ECollisionChannel::ECC_Visibility,
          false,
          HitResult);
      RotateTurret(HitResult.ImpactPoint);
   }
}

void ATank::HandleDestruction()
{
   Super::HandleDestruction();
   SetActorHiddenInGame(true);
   SetActorTickEnabled(false);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
   Super::BeginPlay();
   TankPlayerController = Cast<APlayerController>(GetController());
}
// Tank movement !UP TO DATE WITH IA!
void ATank::Move(float Value)
{
   FVector DeltaLocation = FVector::ZeroVector;
   DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
   AddActorLocalOffset(DeltaLocation, true);
}
// TANK TURNING !UP TO DATE WITH IA!
void ATank::Turn(float Value)
{
   FRotator DeltaRotation = FRotator::ZeroRotator;
   DeltaRotation.Yaw = Value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
   AddActorLocalRotation(DeltaRotation, true);
}
