// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Dim2D_03GameMode.h"
#include "Dim2D_03Character.h"

ADim2D_03GameMode::ADim2D_03GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ADim2D_03Character::StaticClass();	
}
