// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "C_Actor_test_01.generated.h"

UCLASS()
class DIM2D_03_API AC_Actor_test_01 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_Actor_test_01();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="MyComponents")
	UStaticMeshComponent* MyMeshComponent;

	UPROPERTY()
	USceneComponent* MySceneComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// описание переменной векторного типа
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVariables")
	FVector MyVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVariables")
	FString MyString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVariables")
	FTransform MyTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MyVarialbes")
	FText MyText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariables")
	AActor* MyActor;






};
