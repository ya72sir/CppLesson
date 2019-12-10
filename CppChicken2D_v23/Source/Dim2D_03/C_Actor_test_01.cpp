// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Actor_test_01.h"

// Sets default values
AC_Actor_test_01::AC_Actor_test_01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MySceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MySceneComponent"));
	MyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMeshComponent"));

	RootComponent = MySceneComponent;
	MyMeshComponent->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AC_Actor_test_01::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_Actor_test_01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MyMeshComponent->AddLocalRotation(FRotator(0.f, 0.f, 1.f), false);

}

