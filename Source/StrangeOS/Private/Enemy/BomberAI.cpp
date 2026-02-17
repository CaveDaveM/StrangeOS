// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BomberAI.h"

#include "Enemy/BomberAIController.h"
#include "Enemy/BomberBomb.h"

// Sets default values
ABomberAI::ABomberAI()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ABomberAIController::StaticClass();

}

// Called when the game starts or when spawned
void ABomberAI::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(
		SpawnBomber_TimerHandle,
		this,
		&ABomberAI::SpawnBomb,
		0.5f,
		true);
}

void ABomberAI::SpawnBomb()
{
	GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Green,"Spawning Bomber");
	FVector Location = GetActorLocation();
	FRotator Rotation = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnInfo;
	ABomberBomb* NewTile = GetWorld()->SpawnActor<ABomberBomb>(ABomb, Location, Rotation, SpawnInfo);
}

// Called every frame
void ABomberAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABomberAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

