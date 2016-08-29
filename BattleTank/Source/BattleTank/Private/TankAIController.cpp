// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto Controlled = GetControlledTank();
	if (Controlled)
	{
		UE_LOG(LogTemp, Warning, TEXT("*** AI \"%s\" Begins Play ***"), *(Controlled->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("*** AIController not possessing a Tank ***"));
	}

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("*** AI found \"%s\" PlayerTank ***"), *(Controlled->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("*** AI cannot find PlayerTank***"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerPawn) 
		return Cast<ATank>(PlayerPawn);
	else 
		return nullptr;
}