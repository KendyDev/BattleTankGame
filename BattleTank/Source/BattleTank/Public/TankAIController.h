// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	
private: 
	//How close can the AI tank get to the player before shooting
	float AcceptanceRadius = 3000;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


};
