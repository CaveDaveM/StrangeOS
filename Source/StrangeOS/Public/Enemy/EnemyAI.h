// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interface/DamageInterface.h"
#include "EnemyAI.generated.h"

class ACoins;
class UNiagaraSystem;

UCLASS()
class STRANGEOS_API AEnemyAI : public APawn, public IDamageInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyAI();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EnemyMeshComponent;
	
	UPROPERTY(EditAnywhere)
	float Health = 100.0f;
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
	
	virtual AEnemyAI* DamageEnemy_Implementation(float Damage) override;
	
	UFUNCTION()
	void CheckHealth();
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACoins> ClassCoin;
	
	UPROPERTY(EditAnywhere)
	int32 AmountOfCoins = 10;

};
