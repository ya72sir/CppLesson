// Fill out your copyright notice in the Description page of Project Settings.

#include "MultipleerC.h"
#include "Net/UnrealNetwork.h"
#include "PickUp.h"

APickUp::APickUp()
{
	// Tell ue4 to replicate this Actor

	bReplicates = true;
	
	// Pickups do not need to tick every frame
	PrimaryActorTick.bCanEverTick = false;

	if (Role == ROLE_Authority)
	{
		bIsActive = true; 
	}
}

void APickUp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APickUp, bIsActive);
}


bool APickUp::IsActive()
{
	return bIsActive;
}

void APickUp::SetActive(bool NewPickupState)
{
	if (Role == ROLE_Authority)
	{
		bIsActive = NewPickupState;
	}
}


void APickUp::OnRep_IsActive()
{
	
}

void APickUp::WasCollected_Implementation()
{
	//log gebbug message
	UE_LOG(LogClass, Log, TEXT("APickUp::WasCollected_Implementation, %s"), *GetName());
}