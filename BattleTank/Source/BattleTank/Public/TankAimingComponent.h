// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

//Foward Declaration
class UTankBarrel; 
class UTankTurret;

//Holds Barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	//Barrel that we are gonna set to the tank
	void SetBarrelReference(UTankBarrel *BarrelToSet);

	//Turret that we are going to set to the tank
	void SetTurretReference(UTankTurret *TurretToSet);

	//TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;

	void MoveBarrel(FVector AimDirection);
	
};
