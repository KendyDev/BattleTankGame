// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* MainTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();

	if (!MainTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI posses a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Possesing tank : %s"), *(MainTank->GetName()))
	}


	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Found Player Tank : %s"), *(MainTank->GetName()), *(PlayerTank->GetName()))
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO Move towards the player

		//TODO aim at the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation(), GetControlledTank()->LaunchSpeed);

		//TODO Fire if ready

	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


