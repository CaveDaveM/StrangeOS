// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAI.h"
#include "GameFramework/Pawn.h"
#include "BomberAI.generated.h"

class ABomberBomb;

UCLASS()
class STRANGEOS_API ABomberAI : public AEnemyAI
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABomberAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void SpawnBomb();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	FTimerHandle SpawnBomber_TimerHandle;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABomberBomb> ABomb;

};
