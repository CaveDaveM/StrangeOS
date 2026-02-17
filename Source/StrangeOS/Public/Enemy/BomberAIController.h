// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BomberAIController.generated.h"

class AEnemyAI;
/**
 * 
 */
UCLASS()
class STRANGEOS_API ABomberAIController : public AAIController
{
	GENERATED_BODY()
public:
	ABomberAIController();
	virtual void BeginDestroy() override;

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	
	UFUNCTION()
	void CheckTravelingLocation();
	
	UPROPERTY()
	AEnemyAI* OwningPawn;
	
	UPROPERTY()
	APawn* PlayerPawn;
	
	UPROPERTY()
	FVector LocationLeft;
	
	UPROPERTY()
	FVector LocationRight;
	
	UPROPERTY()
	FVector CurrentTravelingLocation;
	
	FTimerHandle CheckLocation_TimerHandle;
	

};