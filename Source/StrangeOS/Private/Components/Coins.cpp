// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Coins.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	SetRootComponent(CoinMesh);
}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

