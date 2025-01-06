// Fill out your copyright notice in the Description page of Project Settings.


#include "MainEnemy.h"

// Sets default values
AMainEnemy::AMainEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMainEnemy::SpawnActor()
{
}

// Called when the game starts or when spawned
void AMainEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AMainEnemy::PerformLineTrace();

}

// Called to bind functionality to input
void AMainEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainEnemy::PerformLineTrace()
{
	FVector StartLocation = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector();
	FVector EndLocation = StartLocation + (ForwardVector * 300);

	
	FHitResult Hit;
	FCollisionQueryParams Parameters;
	Parameters.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECC_Visibility, Parameters);

	if (bHit)
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor && HitActor->ActorHasTag("Door"))
		{
			UE_LOG(LogTemp, Warning, TEXT("Door"));
		}
	}

	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1, 0, 1.0f);
}

