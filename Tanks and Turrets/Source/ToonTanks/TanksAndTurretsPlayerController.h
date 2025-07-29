// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TanksAndTurretsPlayerController.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATanksAndTurretsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnabledState(bool bPlayerEnabled);
};
