// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CppShootCompnent.h"
#include "Components/CppHealthComp.h"

#include "EnemyPawn.generated.h"

UCLASS()
class CPP_ARCADA_01_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void DestroyPawn();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		UBoxComponent* PawnCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		UStaticMeshComponent* PawnMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		UCppShootCompnent* ShootComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		UCppHealthComp* HealthComp;

};
