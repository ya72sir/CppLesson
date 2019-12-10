// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnController.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Pawns/EnemyPawn.h"



// Called when the game starts
void UEnemySpawnController::BeginPlay()
{
	Super::BeginPlay();

	// ...

	Random.GenerateNewSeed();

	StartSpawnEnemy();
	
}

void UEnemySpawnController::StartSpawnEnemy()
{

	SpawnStage = SpawnStages[Random.RandRange(0, SpawnStages.Num() - 1)];

	GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnController::SpawnEnemy, SpawnStage.SpawnDelay, true);

}

void UEnemySpawnController::SpawnEnemy()
{
	// UE_LOG(LogTemp, Log, TEXT("EnemySpawn"));

	FActorSpawnParameters SpawnParametrs;
	GetWorld()->SpawnActor<AEnemyPawn>(SpawnStage.EnemyClass, SpawnStage.SpawnTransform, SpawnParametrs);

	EnemisSpawned++;

	if (EnemisSpawned >= SpawnStage.NumOfEnemies)
	{
		GetWorld()->GetTimerManager().ClearTimer(EnemySpawnTimer);

		Random.GenerateNewSeed();
		SpawnStage = SpawnStages[Random.RandRange(0, SpawnStages.Num() - 1)];

		GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnController::SpawnEnemy, SpawnStage.SpawnDelay, true);
		
		EnemisSpawned = 0;
	}

}