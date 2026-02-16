// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyAI.generated.h"

class UNiagaraSystem;

UCLASS()
class STRANGEOS_API AEnemyAI : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyAI();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EnemyMeshComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, Category = "Niagara Effects")
	UNiagaraSystem* DestroyEffect;
	
	UFUNCTION()
	virtual void BeginDestroy() override;
};
