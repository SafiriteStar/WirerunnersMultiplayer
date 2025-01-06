// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "WirerunnersPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class FPS_MATCHMADE_API AWirerunnersPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
protected:
	AWirerunnersPlayerController();
	virtual void BeginPlay() override;

	// End Actor interface
};
