// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"
#include "BattleTank.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//clamp relative speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	//Move the barrel the right amount this frame
	auto EvelationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + EvelationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	//Pass elevation to the barrel
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
