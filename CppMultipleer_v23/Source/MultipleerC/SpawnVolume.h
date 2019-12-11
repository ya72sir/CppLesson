// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"


UCLASS()

class MULTIPLEERC_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Return the spawn volume box component
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	//Find a random point withim the box component
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointVolume();

protected:
	// This is the pickup to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickUp> WhatToSpawn;

	// Access to the timer for recurring spawning
	FTimerHandle SpawnTimer;

	//Minimun Spawn Delay (seconds)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning" )
	float SpawnDelayRangeLow;

	//Maximum spawn delay (seconds)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

private:
	// The spawn area where pickups will be created
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", Meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	//Handle spawning a new pickup
	void SpawnPickup();

	// Actual time (seconds) before spawning the next pickup.
	float SpawnDelay;

};
