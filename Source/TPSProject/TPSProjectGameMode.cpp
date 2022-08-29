// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPSProjectGameMode.h"
#include "TPSProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPSProjectGameMode::ATPSProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
