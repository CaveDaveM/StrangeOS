// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Enemy/EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Enemy/EnemyAI.h"

AEnemyAIController::AEnemyAIController()
{
	
}


void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if (!PlayerPawn)
	{
		UE_LOG(EnemyAILOG,Display,TEXT("Not Found Player Pawn"))
	}
	
	OwningPawn = Cast<AEnemyAI>(GetPawn());
	if (!OwningPawn)
	{
		UE_LOG(EnemyAILOG,Warning,TEXT(" Not Found Owning Pawn"))
	}
	if (OwningPawn && PlayerPawn)
	{
		GetWorld()->GetTimerManager().SetTimer(
			UpdateVelocity_TimerHandle,
			this,
			&AEnemyAIController::MoveEnemyToPlayer,
			0.5,
			true);
	}
}

void AEnemyAIController::BeginMovement()
{
}
void AEnemyAIController::MoveEnemyToPlayer()
{
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector PlayerLocation =  PlayerPawn->GetActorLocation();
	FVector EnemyLocation = OwningPawn->GetActorLocation();
	
	FVector PlayerDirectionFromEnemy = (PlayerLocation - EnemyLocation) * DeltaTime * 50;
	OwningPawn->EnemyMeshComponent->AddImpulse(PlayerDirectionFromEnemy);
	
}


FVector AEnemyAIController::GetPlayerLocation()
{
	return FVector(0.0f, 0.0f, 0.0f);
}

void AEnemyAIController::BeginDestroy()
{
	Super::BeginDestroy();
}


