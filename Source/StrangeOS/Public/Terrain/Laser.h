// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Laser.generated.h"

class UNiagaraSystem;
class UBoxComponent;

UCLASS()
class STRANGEOS_API ALaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY()
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* Laser_BoxComponent;
	
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* Laser_NiagaraSystem;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(BlueprintReadWrite)
	float Damage = 60;

};
