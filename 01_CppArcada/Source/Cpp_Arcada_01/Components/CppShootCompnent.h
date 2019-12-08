// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "myActors/ShootProjectile.h"

#include "CppShootCompnent.generated.h"


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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controls")
		float ShootPeriod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shoot")
		TSubclassOf<AShootProjectile> ShootProjectileClass;


		
};
