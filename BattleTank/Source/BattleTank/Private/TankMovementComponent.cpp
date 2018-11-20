// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendRotateClockwise(float Throw)
{

	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector &MoveVelocity, bool bForceMaxSpeed)
{
	//Not calling super as we are completly overriding the parent function
	//Dot product of the two vector to get the direction
	auto TankFoward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto DotProduct = FVector::DotProduct(TankFoward, AIForwardIntention);

	IntendMoveFoward(DotProduct);

	auto CrossProduct = FVector::CrossProduct(TankFoward, AIForwardIntention);
	IntendRotateClockwise(CrossProduct.Z);
	
	/*UE_LOG(LogTemp, Warning, TEXT("Right: %f, Foward: %f "), CrossProduct.Z, DotProduct)*/
}


