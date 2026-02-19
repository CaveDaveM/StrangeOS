// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MoneyDropComponent.h"

#include "Components/Coins.h"

// Sets default values for this component's properties
UMoneyDropComponent::UMoneyDropComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMoneyDropComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMoneyDropComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMoneyDropComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);

	for (int i = 0; i < AmountOfCoins; ++i)
	{
		FVector Location = GetOwner()->GetActorLocation();
		FRotator Rotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnInfo.Owner = GetOwner();
		ACoins* SpawnedCoin = GetWorld()->SpawnActor<ACoins>(ClassCoin, Location, Rotation, SpawnInfo);
	}
	
}

