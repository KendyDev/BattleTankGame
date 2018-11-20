// Copyright KendyDev.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation, float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000; //Starting value of 1000 m/s
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent *TankAimingComponent = nullptr;

private:

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	 void BeginPlay() override;

	//Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; //TODO remove

	double LastFireTime = 0.0;
};
