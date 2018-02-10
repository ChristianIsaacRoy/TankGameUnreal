// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelComponent(UTankBarrel* NewBarrel);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretComponent(UTankTurret* NewTurret);

	UFUNCTION(BlueprintCallable)
	void Fire();

	void AimAt(FVector HitLocation);

protected:
	UTankAimingComponent* AimingComponent;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* MovementComponent;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000; // TODO: Find sensible launch speed

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSec = 3;

	// Barrel reference for spawning projectiles
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
