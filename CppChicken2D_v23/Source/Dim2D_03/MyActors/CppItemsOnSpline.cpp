// Fill out your copyright notice in the Description page of Project Settings.


#include "CppItemsOnSpline.h"
#include "Components/SplineComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ACppItemsOnSpline::ACppItemsOnSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComp;



	SplineComp = CreateDefaultSubobject<USplineComponent>("SplineComponent");
	SplineComp->AttachTo(SphereComp);


	SplineComp->bDrawDebug = true;

	SplineComp -> ClearSplinePoints(true);
	SplineComp -> UpdateSpline();

	SplineComp->AddSplineLocalPoint(FVector(100.f, 150.f, 0.f));
	SplineComp->AddSplineLocalPoint(FVector(300.f, 250.f, 0.f));
	SplineComp->AddSplineLocalPoint(FVector(500.f, 550.f, 0.f));




}

// Called when the game starts or when spawned
void ACppItemsOnSpline::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppItemsOnSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

