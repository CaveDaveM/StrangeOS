// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Enemy/EnemyAI.h"

#include <string>

#include "Public/Enemy/EnemyAIController.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "OSCollisionChannels.h"

DEFINE_LOG_CATEGORY(EnemyAILOG);

// Sets default values
AEnemyAI::AEnemyAI()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	AIControllerClass = AEnemyAIController::StaticClass();
	
	EnemyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(EnemyMeshComponent);
	
	EnemyMeshComponent->SetSimulatePhysics(true);
	EnemyMeshComponent->SetEnableGravity(false);
	EnemyMeshComponent->SetCollisionObjectType(EOSCollisionChannel::ECC_Enemy);

}


// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AEnemyAI* AEnemyAI::DamageEnemy_Implementation(float Damage)
{
	IDamageInterface::DamageEnemy_Implementation(Damage);
	Health -= Damage;
	
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
		FString::Printf(TEXT("current health %f"), Health));
	return this;
}

// Called to bind functionality to input
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAI::BeginDestroy()
{
	UNiagaraComponent* NiagaraHealing = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),
		DestroyEffect, 
		GetActorLocation(),
		FRotator(0.f));
	Super::BeginDestroy();
}



