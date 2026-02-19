// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BomberBomb.generated.h"

class ASideScrollingCharacter;
class UNiagaraSystem;
class USphereComponent;

UCLASS()
class STRANGEOS_API ABomberBomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomberBomb();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BombMesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* BombSphereComponent;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* HitBoxMesh;
	
	UPROPERTY(EditAnywhere)
	float OverlapSphereSize = 300.0f;
	
	UPROPERTY(EditAnywhere)
	float HitBoxExposeTime = 1.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	FTimerHandle BombExplode_TimerHandle;
	
	FTimerHandle HitBoxExpose_TimerHandle;
	
	UPROPERTY(EditAnywhere, Category = "Niagara Effects")
	UNiagaraSystem* ExplosionEffect;
	
	UFUNCTION()
	void ExplodeBomb();
	
	UFUNCTION()
	void SetHitBoxVisibility();
	
	UFUNCTION()
	void ApplyDamageToActors(TArray<AActor*> FoundActors);
	
	UPROPERTY()
	ASideScrollingCharacter* PlayerCharacter;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
