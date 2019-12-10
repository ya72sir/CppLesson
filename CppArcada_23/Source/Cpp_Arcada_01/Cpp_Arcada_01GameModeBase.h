// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "Components/EnemySpawnController.h"
#include "Components/StaticMeshComponent.h"

#include "Cpp_Arcada_01GameModeBase.generated.h"

/**
 * 
 */

UCLASS()

class CPP_ARCADA_01_API ACpp_Arcada_01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ACpp_Arcada_01GameModeBase();
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
		UEnemySpawnController* EnemySpawnController;
};
