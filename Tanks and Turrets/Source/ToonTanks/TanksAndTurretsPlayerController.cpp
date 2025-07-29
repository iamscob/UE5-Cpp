// Fill out your copyright notice in the Description page of Project Settings.

#include "TanksAndTurretsPlayerController.h"
#include "GameFramework/Pawn.h"

void ATanksAndTurretsPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
   if (bPlayerEnabled)
   {
      GetPawn()->EnableInput(this);
   }
   else
   {
      GetPawn()->DisableInput(this);
   }
   bShowMouseCursor = bPlayerEnabled;
}
