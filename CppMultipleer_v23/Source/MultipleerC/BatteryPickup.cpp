// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "Components/StaticMeshComponent.h"


ABatteryPickup::ABatteryPickup()
{
	// Keep movement synced from server to clients
	bReplicateMovement = true;
	// This pickup is physics enabled end shold move
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetSimulatePhysics(true);

}