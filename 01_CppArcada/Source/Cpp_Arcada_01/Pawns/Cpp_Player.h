// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Components/CppShootCompnent.h"

#include "Cpp_Player.generated.h"

UCLASS()
class CPP_ARCADA_01_API ACpp_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACpp_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnTouchPressed(ETouchIndex::Type FingerIndex, FVector Location);
	//void OnTouchReleased(ETouchIndex::Type FingerIndex, FVector Location);
	void OnTouchMove(ETouchIndex::Type FingerIndex, FVector Location);

	virtual void PossessedBy(AController* NewController) override;

	APlayerController* PlayerController;

	FVector2D vMoveLimits;


private:
	FVector2D vTouchLocation;

	bool bTouch;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CppPawn")
		UBoxComponent* CppBoxCollision	;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CppPawn")
		UStaticMeshComponent* CppMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CppPawn")
		USpringArmComponent* CppSpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CppPawn")
		UCameraComponent* CppCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controls")
		float fTouchMoveSesivity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shoot")
		UCppShootCompnent* CppShootCompnent;


};
