// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankPlayerController.h"
#include "./BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* MainTank = GetControlledTank();

	if(!MainTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank possesed"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possesing tank : %s"), *(MainTank->GetName()))
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


