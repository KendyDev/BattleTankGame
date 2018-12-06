// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SprungWheel.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"


/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UTankTrack();

	TArray<ASprungWheel*> GetWheels() const;

	void DriveTrack(float CurrentThrottle);

public:
	//Sets a throttle between -1 and + 1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	//Max force per track
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.0;
};
