// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TanksAndTurretsGameMode.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATanksAndTurretsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor *DeadActor);

protected:
	virtual void BeginPlay() override;

private:
	class ATank *Tank;
	class ATanksAndTurretsPlayerController *TanksAndTurretsPlayerController;
	float StartDelay = .5f;
	void HandleDelayStart();
};
