// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

class UTankAimingComponent;

/*
* Responsible to help the player aim
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent *AimingCompRef);

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnPlayerDeath();

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	virtual void SetPawn(APawn *InPawn) override;

	//Move barrrel to the crosshair
	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
};
