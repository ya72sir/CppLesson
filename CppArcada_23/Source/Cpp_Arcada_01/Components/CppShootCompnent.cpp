// Fill out your copyright notice in the Description page of Project Settings.


#include "CppShootCompnent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "myActors/ShootProjectile.h"

// Sets default values for this component's properties
UCppShootCompnent::UCppShootCompnent()
{
	ShootPeriod = 1.f;
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
	//UE_LOG(LogTemp, Log, TEXT("Shoot"));

	for (FStrShootInfo ShootInfo : arrShootInfo) {

		FActorSpawnParameters SpawnParam;

		SpawnParam.Owner = GetOwner();
		SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FVector SpawnLocation = GetOwner()->GetActorLocation() + GetOwner()->GetActorRotation().RotateVector(ShootInfo.vOffset);

		FRotator SpawnRotation = GetOwner()->GetActorRotation();
		SpawnRotation.Add(0.f, ShootInfo.fAngle, 0.f);

		AShootProjectile* Projectule = GetWorld()->SpawnActor<AShootProjectile>(ShootInfo.ShootProjectileClass, SpawnLocation, SpawnRotation, SpawnParam);
		if (Projectule) Projectule->Damage = ShootInfo.Damage;
	}



}

