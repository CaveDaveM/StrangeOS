// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Enemy/EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Enemy/EnemyAI.h"

AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
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
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector PlayerLocation =  PlayerPawn->GetActorLocation();
	FVector EnemyLocation = OwningPawn->GetActorLocation();
	
	FVector PlayerDirectionFromEnemy = (PlayerLocation - EnemyLocation);
	PlayerDirectionFromEnemy.Normalize();
	FVector AppliedDirection = PlayerDirectionFromEnemy * DeltaTime * 7000;

	OwningPawn->EnemyMeshComponent->AddImpulse(AppliedDirection,NAME_None, true);
	
}


void AEnemyAIController::BeginDestroy()
{
	Super::BeginDestroy();
}


