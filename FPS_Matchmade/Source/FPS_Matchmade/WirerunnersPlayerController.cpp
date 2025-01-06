// Copyright Epic Games, Inc. All Rights Reserved.


#include "WirerunnersPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

AWirerunnersPlayerController::AWirerunnersPlayerController()
{
	IGenericTeamAgentInterface::SetGenericTeamId(FGenericTeamId(1));
}

void AWirerunnersPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}
