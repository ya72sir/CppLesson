// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "myActors/ShootProjectile.h"

#include "CppShootCompnent.generated.h"


USTRUCT(BlueprintType)
struct FStrShootInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
		TSubclassOf<AShootProjectile> ShootProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
		FVector vOffset;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot")
		float fAngle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
		float Damage;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_ARCADA_01_API UCppShootCompnent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCppShootCompnent();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	FTimerHandle TimerShoot;
	void fShoot();

public:	

	UFUNCTION(BlueprintCallable, Category = "Shoot" )
		void StartShoot();
	UFUNCTION(BlueprintCallable, Category = "Shoot")
		void StopShoot();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shoot")
		float ShootPeriod;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shoot")
		TArray<FStrShootInfo> arrShootInfo;
};
