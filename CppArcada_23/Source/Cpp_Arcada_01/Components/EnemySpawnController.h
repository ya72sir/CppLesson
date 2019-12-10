// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "EnemySpawnController.generated.h"


USTRUCT(BlueprintType)
struct FEnemySpawnInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
		TSubclassOf<class AEnemyPawn> EnemyClass = APawn::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
		FTransform SpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
		int NumOfEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
		float SpawnDelay;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_ARCADA_01_API UEnemySpawnController : public UActorComponent
{
	GENERATED_BODY()


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void StartSpawnEnemy();
	void SpawnEnemy();

	FEnemySpawnInfo SpawnStage;
	int EnemisSpawned;

	FTimerHandle ChangeStageTimer;
	FTimerHandle EnemySpawnTimer;

	FRandomStream Random;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		TArray<FEnemySpawnInfo> SpawnStages;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		float StageSpawnMinDelay;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		float StageSpawnMaxDelay;
};
