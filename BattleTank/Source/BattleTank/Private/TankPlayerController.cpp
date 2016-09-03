// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto Controlled = GetControlledTank();
	if (Controlled)
	{
		UE_LOG(LogTemp, Warning, TEXT("*** Player \"%s\" Begins Play ***"), *(Controlled->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("*** PlayerController not possessing a Tank ***"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{

	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	return false;
}
