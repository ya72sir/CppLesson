// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SphereComponent.h"

#include "CppItemsOnSpline.generated.h"

UCLASS()
class DIM2D_03_API ACppItemsOnSpline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppItemsOnSpline();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "SplineComponent")
		USplineComponent* SplineComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "SplineComponent")
		USphereComponent* SphereComp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SplineComponent")
		TArray<FVector> Points;

};
