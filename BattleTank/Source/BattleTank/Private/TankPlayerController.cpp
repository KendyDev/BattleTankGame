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



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardCrosshair();


}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Turn the barrel towards the crosshair in the UI
void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //OUT Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
	
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//Find crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *(ScreenLocation.ToString()));


	return true;
}


