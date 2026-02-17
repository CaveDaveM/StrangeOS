// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BomberAIController.h"

#include "Enemy/EnemyAI.h"
#include "Enemy/EnemyAIController.h"
#include "Kismet/GameplayStatics.h"

ABomberAIController::ABomberAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	LocationLeft = FVector(-830.0, 100.0, 1620.0);
	LocationRight = FVector(2810.0, 100.0, 1620.0);
}

void ABomberAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	Super::OnPossess(InPawn);
	SetActorTickEnabled(true);
	
	OwningPawn = Cast<AEnemyAI>(InPawn);
	if (!OwningPawn)
	{
		UE_LOG(EnemyAILOG,Warning,TEXT(" Not Found Owning Pawn"))
	}
}


void ABomberAIController::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentTravelingLocation = LocationLeft;

	GetWorld()->GetTimerManager().SetTimer(
		CheckLocation_TimerHandle,
		this,
		&ABomberAIController::CheckTravelingLocation,
		0.3f,
		true);
}

void ABomberAIController::CheckTravelingLocation()
{
	GEngine->AddOnScreenDebugMessage(-1,10.0f, FColor::Yellow, TEXT("CheckTravelingLocation"));
	FVector CurrentActorLocation = OwningPawn->GetActorLocation();
	if (CurrentActorLocation.X <= LocationLeft.X)
	{
		CurrentTravelingLocation = LocationRight;
	}
	if (CurrentActorLocation.X >= LocationRight.X)
	{
		CurrentTravelingLocation = LocationLeft;
	}
}

void ABomberAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector EnemyLocation = OwningPawn->GetActorLocation();
	
	FVector PlayerDirectionFromEnemy = (CurrentTravelingLocation - EnemyLocation);
	PlayerDirectionFromEnemy.Normalize();
	FVector AppliedDirection = PlayerDirectionFromEnemy * DeltaTime * 7000;

	OwningPawn->EnemyMeshComponent->AddImpulse(AppliedDirection,NAME_None, true);
}


void ABomberAIController::BeginDestroy()
{
	Super::BeginDestroy();
	
}
