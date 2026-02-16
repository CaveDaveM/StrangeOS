// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EnemyAILOG,Display, All);

class AEnemyAI;
/**
 * 
 */
UCLASS()
class STRANGEOS_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController();
	virtual void BeginDestroy() override;

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	AEnemyAI* OwningPawn;
	
	UPROPERTY()
	APawn* PlayerPawn;
	
	UPROPERTY()
	FTimerHandle UpdateVelocity_TimerHandle;
	
	UFUNCTION()
	void BeginMovement();
	
	UFUNCTION()
	FVector GetPlayerLocation();
	
	UFUNCTION()
	void MoveEnemyToPlayer();
};
