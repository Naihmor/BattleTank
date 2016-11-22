// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed) {

	// Move the barrel the right amout this frame
	// Given a max elevation speed and the frame time

	// -1 is max downward speed, and +1 is max up movement.
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	// This instruction calculates the elevation, adding +7 per second (up movement) or substracting -7 per second (downward movement).
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	// USceneComponent::RelativeRotation. Here we're adding the elevation calculated previously, to the TankTurret Pitch. (?)-> Pitch(translation): elevacion, pentiente.
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	
	// Setting the rotation to USceneComponent::RelativeRotation.
	SetRelativeRotation(FRotator(0, Rotation, 0));
}