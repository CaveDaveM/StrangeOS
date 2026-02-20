// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealingOrb.generated.h"

UCLASS()
class STRANGEOS_API AHealingOrb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealingOrb();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* HealthMesh;

	UPROPERTY(EditDefaultsOnly)
	int32 HealingValue = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
