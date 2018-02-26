// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerTank || !ControlledTank)
	{
		return;
	}

	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	ControlledTank->Fire();
}
