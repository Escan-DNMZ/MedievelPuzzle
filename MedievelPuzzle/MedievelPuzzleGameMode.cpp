// Copyright Epic Games, Inc. All Rights Reserved.

#include "MedievelPuzzleGameMode.h"
#include "MedievelPuzzleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMedievelPuzzleGameMode::AMedievelPuzzleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
