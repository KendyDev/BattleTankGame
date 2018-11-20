// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankPlayerController.h"
#include "TankAimingComponent.h"
#include "./BattleTank.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//ATank* MainTank = GetControlledTank();
	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();

	if(ensure(AimingComponent))
	{
		FoundAimingComponent(AimingComponent);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller can't find aiming component"))
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
	if (!ensure(GetControlledTank())) { return; }

	FVector HitLocation; //OUT Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation, GetControlledTank()->LaunchSpeed);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//Find crosshair position in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	//De-project Screen position to world position in order for us to ray cast
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line-trace along that Look Direction
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}



	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	//Line trace didn't suceed
	HitLocation = FVector(0);
	return false;
}




