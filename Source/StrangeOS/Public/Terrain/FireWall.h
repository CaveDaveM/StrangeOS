// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/DamageInterface.h"
#include "FireWall.generated.h"

class UNiagaraSystem;
class USphereComponent;

UCLASS()
class STRANGEOS_API AFireWall : public AActor, public IDamageInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireWall();
	
	UPROPERTY(EditAnywhere)
	float DamageOfObstacle = 25.0f;
	
	UPROPERTY(EditAnywhere)
	float DamageOfObstacleOverTime = 10.0f;
	
	UPROPERTY(EditAnywhere)
	float DamageTimer = 0.5f;
	



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* OverlapComponent;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UFUNCTION()
	void DamageEnemyOverTime();
	
	UPROPERTY()
	TArray<AEnemyAI*> OverlappedEnemies;
	
	UPROPERTY()
	FTimerHandle ApplyDamageToEnemy_TimerHandle;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};
