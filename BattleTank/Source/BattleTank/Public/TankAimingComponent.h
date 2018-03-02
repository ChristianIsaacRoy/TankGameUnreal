#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

// Forward declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

// Holds barrel's properties and elvate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* NewBarrel, UTankTurret* NewTurret);

	void AimAt(FVector WorldSpaceAim);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSec = 3;

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;
	
	double LastFireTime = 0;

	UTankAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);
};
