// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MultipleerCGameMode.h"
#include "MultipleerCCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultipleerCGameMode::AMultipleerCGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
