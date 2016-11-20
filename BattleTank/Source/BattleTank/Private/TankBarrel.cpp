// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {

	// Move the barrel the right amout this frame
	// Given a max elevation speed and the frame time
	
	// -1 is max downward speed, and +1 is max up movement.
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	// This instruction calculates the elevation, adding +5 per second (up movement) or substracting -5 per second (downward movement).
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	// USceneComponent::RelativeRotation. Here we're adding the elevation calculated previously, to the TankBarrel Pitch. (?)-> Pitch(translation): elevacion, pentiente.
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	// Clamping the new calculated elevation with max & min elevation degrees constants.
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	// Setting the rotation to USceneComponent::RelativeRotation.
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}