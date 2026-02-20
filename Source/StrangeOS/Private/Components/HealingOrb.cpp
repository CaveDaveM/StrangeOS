// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealingOrb.h"

// Sets default values
AHealingOrb::AHealingOrb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HealthMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	SetRootComponent(HealthMesh);
}

// Called when the game starts or when spawned
void AHealingOrb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealingOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

