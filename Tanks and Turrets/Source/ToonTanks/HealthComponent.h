// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth = 100.f;
	float Health = 0.f;
	UFUNCTION()
	void DamageTaken(AActor *DamagedActor, float Damage, const UDamageType *DamageType, class AController *Instigator, AActor *DamageCauser);
	class ATanksAndTurretsGameMode *TanksAndTurretsGameMode;

public:
	// Called every frame
	virtual void
	TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
