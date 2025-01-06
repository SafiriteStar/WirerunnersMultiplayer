// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "InputAction.h"

#include "CharacterInterface.h"

#include "WirerunnersCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

// TArray<UStaticMeshComponent> StaticComps;
// YourActor->GetComponents** <UStaticMeshComponent>** (StaticComps);

// AIPerceptionComponent<UAIPerceptionComponent> AIPerception;


UCLASS(config=Game)	
class AWirerunnersCharacter : public ACharacter, public IGenericTeamAgentInterface, public ICharacterInterface

{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,  meta=(AllowPrivateAccess = "true"))
    UInputAction* ToggleDamageCheat;
	
public:
	AWirerunnersCharacter();
    
    //UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
    //void EnableDamagedVFX();
    
    //UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
    //void DisableDamagedVFX();
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Damage")
        void TriggerAnyDamageEvent();


protected:
	virtual void BeginPlay();
    
    UPROPERTY(EditAnywhere)
    float Health = 100;
    
    bool bCanTakeDamage = true;
    
    void ToggleDamageCheatState(const FInputActionValue& Value);

public:
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;
    
    virtual float TakeDamage (float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface
		
public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
    
    bool IsEnemy_Implementation() override;

};

