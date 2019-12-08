// Fill out your copyright notice in the Description page of Project Settings.


#include "CppShootCompnent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "myActors/ShootProjectile.h"

// Sets default values for this component's properties
UCppShootCompnent::UCppShootCompnent()
{
	ShootPeriod = 0.1f;
}


// Called when the game starts
void UCppShootCompnent::BeginPlay()
{
	Super::BeginPlay();

	StartShoot();
}

void UCppShootCompnent::StartShoot()
{
	GetWorld()->GetTimerManager().SetTimer(TimerShoot, this, &UCppShootCompnent::fShoot, ShootPeriod, true, ShootPeriod);
}

void UCppShootCompnent::StopShoot()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerShoot);
}

void UCppShootCompnent::fShoot()
{
	UE_LOG(LogTemp, Log, TEXT("Shoot"));

	FActorSpawnParameters SpawnParam;

	FVector SpawnLocation = GetOwner()->GetActorLocation();
	FRotator SpawnRotation = GetOwner()->GetActorRotation();
	//SpawnRotation.Add(0.f, 25.f, 0.f);

	GetWorld()->SpawnActor<AShootProjectile>(ShootProjectileClass, SpawnLocation, SpawnRotation, SpawnParam);
}

