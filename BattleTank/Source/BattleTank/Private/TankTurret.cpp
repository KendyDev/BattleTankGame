// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//clamp relative speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	//Move the barrel the right amount this frame
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	//Pass Rotation to the barrel
	SetRelativeRotation(FRotator(0, Rotation, 0));
}




