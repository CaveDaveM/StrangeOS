// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoneyDropComponent.generated.h"


class ACoins;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STRANGEOS_API UMoneyDropComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoneyDropComponent();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACoins> ClassCoin;
	
	UPROPERTY(EditAnywhere)
	int32 AmountOfCoins = 10;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
};
