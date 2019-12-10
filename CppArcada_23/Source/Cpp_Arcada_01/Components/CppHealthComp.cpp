// Fill out your copyright notice in the Description page of Project Settings.


#include "CppHealthComp.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UCppHealthComp::UCppHealthComp():
	fHealth(100)
{

}


// Called when the game starts
void UCppHealthComp::BeginPlay()
{
	Super::BeginPlay();

	// ...

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UCppHealthComp::OnOwnerDamaged);
	
}

void UCppHealthComp::OnOwnerDamaged(AActor * ADamageActor, float fDamage, const UDamageType * DamageType, AController * Instigator, AActor * DamageCauser)
{

	fChangeHealth(-fDamage);

}




void UCppHealthComp::fChangeHealth(float Value)
{
	fHealth += Value;
	if (fHealth <= 0.f)
	{
		GetOwner()->OnTakeAnyDamage.RemoveDynamic(this, &UCppHealthComp::OnOwnerDamaged);

		OnHealthEnded.Broadcast();
	}
}

float UCppHealthComp::fGetHealth()
{
	return fHealth;
}

