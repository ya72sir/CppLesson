// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "CppHealthComp.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthEndedEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_ARCADA_01_API UCppHealthComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCppHealthComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float fHealth;
	UFUNCTION()
		void OnOwnerDamaged(AActor* ADamageActor, float fDamage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);

public:	
	UFUNCTION(BlueprintCallable, Category = "Health")
		void fChangeHealth(float Value);
	UFUNCTION(BlueprintPure, Category = "Health")
		float fGetHealth();

	UPROPERTY(BlueprintAssignable, Category = "Health")
		FHealthEndedEvent OnHealthEnded;

};
