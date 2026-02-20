// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAI.h"
#include "Public/Enemy/EnemyAIController.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "OSCollisionChannels.h"
#include "Math/UnrealMathUtility.h"
#include "Components/Coins.h"
#include "Components/HealingOrb.h"

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

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
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
	
	CheckHealth();
	
#if 1 
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
		FString::Printf(TEXT("current health %f"), Health));
#endif
	return this;
}
void AEnemyAI::CheckHealth()
{
	if (Health <= 0.f)
	{
		for (int i = 0; i < AmountOfCoins; ++i)
		{
			FVector Location = GetActorLocation();
			FRotator Rotation = FRotator::ZeroRotator;
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			ACoins* SpawnedCoin = GetWorld()->SpawnActor<ACoins>(ClassCoin, Location, Rotation, SpawnInfo);
		}
		Destroy();
		
		const int32 Min = 1;
		const int32 Max = 10;
		const int32 RandomInt = FMath::RandRange(Min, Max);
		
		if (RandomInt == 5)
		{
			FVector Location = GetActorLocation();
			FRotator Rotation = FRotator::ZeroRotator;
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			AHealingOrb* SpawnedCoin = GetWorld()->SpawnActor<AHealingOrb>(HealingOrbClass, Location, Rotation, SpawnInfo);
		}
	}
}

// Called to bind functionality to input
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAI::BeginDestroy()
{
	Super::BeginDestroy();
	UNiagaraComponent* NiagaraHealing = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),
		DestroyEffect, 
		GetActorLocation(),
		FRotator(0.f));
}



