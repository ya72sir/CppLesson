// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_Player.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"

// Sets default values
ACpp_Player::ACpp_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Определяем коллизию
	CppBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CppBoxCollision"));
	// Установили коллизию как главный элемент
	SetRootComponent(CppBoxCollision);
	// Определяем компонент StaticMesh
	CppMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CppMeshComponent"));
	// Прикрепляем StaticMesh к главному элементу
	CppMeshComponent->SetupAttachment(RootComponent);
	// SpringArm
	//CppSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CppSpringArmComponent"));
	//CppSpringArmComponent->SetupAttachment(RootComponent);
	//CppSpringArmComponent->TargetArmLength = 600.f;
	//CppSpringArmComponent->bDoCollisionTest = false;
	//CppSpringArmComponent->SetRelativeRotation((0.f, -90.f, 0.f), false, NULL, 0);
	// Камера
	CppCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CppCameraComponent"));
	//CppCameraComponent->SetupAttachment(CppSpringArmComponent);

	CppShootCompnent = CreateDefaultSubobject<UCppShootCompnent>(TEXT("CppShootCompnent"));

}

void ACpp_Player::PossessedBy(AController* NewController)
{

	PlayerController = Cast<APlayerController>(NewController);
	PlayerController->bShowMouseCursor = true;
}

// Called when the game starts or when spawned
void ACpp_Player::BeginPlay()
{
	Super::BeginPlay();


	fTouchMoveSesivity = 2.f;
	vMoveLimits = FVector2D(500, 500);

}

// Called every frame
void ACpp_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//bool bTouch;
	//float fTouchX;
	//float fTouchY;

	//PlayerController->GetInputTouchState(ETouchIndex::Touch1, fTouchX, fTouchY, bTouch);

	//if (bTouch)
	//{
	//	UE_LOG(LogTemp, Log, TEXT("Touching in %f - %f "), fTouchX, fTouchY);

	//	FVector2D TouchDeltaMove = FVector2D(vTouchLocation.X - fTouchX, vTouchLocation.Y - fTouchY);
	//	FVector vNewLocation = GetActorLocation();

	//	vNewLocation.X = FMath::Clamp(vNewLocation.X + TouchDeltaMove.Y, -600.f, 600.f);
	//	vNewLocation.Y = FMath::Clamp(vNewLocation.Y + TouchDeltaMove.X*-1, -600.f, 600.f);

	//	SetActorLocation(vNewLocation);
	//	//AddActorLocalOffset(FVector(TouchDeltaMove.Y, TouchDeltaMove.X*-1.f, 0.f));
	//	vTouchLocation = FVector2D(fTouchX, fTouchY);
	//}

}

// Called to bind functionality to input
void ACpp_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindTouch(IE_Pressed, this, &ACpp_Player::OnTouchPressed);
	//InputComponent->BindTouch(IE_Released, this, &ACpp_Player::OnTouchReleased);
	InputComponent->BindTouch(IE_Repeat, this, &ACpp_Player::OnTouchMove);

}

void ACpp_Player::OnTouchMove(ETouchIndex::Type FingerIndex, FVector Location)
{

	//UE_LOG(LogTemp, Log, TEXT("TouchMove: %s"), *Location.ToString());

	FVector2D vTouchDeltaMove = FVector2D(vTouchLocation.X - Location.X, vTouchLocation.Y - Location.Y);
	vTouchDeltaMove = vTouchDeltaMove * fTouchMoveSesivity;

	FVector vNewLocation = GetActorLocation();
	vNewLocation.X = FMath::Clamp(vNewLocation.X + vTouchDeltaMove.Y, -vMoveLimits.Y, vMoveLimits.Y);
	vNewLocation.Y = FMath::Clamp(vNewLocation.Y + vTouchDeltaMove.X*-1, -vMoveLimits.X, vMoveLimits.X);

	SetActorLocation(vNewLocation);
	//AddActorLocalOffset(FVector(TouchDeltaMove.Y, TouchDeltaMove.X*-1.f, 0.f));
	//vTouchLocation = FVector2D(Location.X, Location.Y);

	vTouchLocation = FVector2D(Location.X, Location.Y);

}

void ACpp_Player::OnTouchPressed(ETouchIndex::Type FingerIndex, FVector Location)
{
	vTouchLocation = FVector2D(Location.X, Location.Y);
}
//
//void ACpp_Player::OnTouchReleased(ETouchIndex::Type FingerIndex, FVector Location)
//{
//	UE_LOG(LogTemp, Log, TEXT("TouchReleased : %s"), *Location.ToString());
//	vTouchLocation = FVector2D(Location);
//	bTouch = false;
//}


