// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* NewBarrel);

	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);

	void MoveBarrelTowards(FVector AimDirection);
	
private:
	UStaticMeshComponent* Barrel = nullptr;
	
};