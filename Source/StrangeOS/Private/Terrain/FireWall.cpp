// Fill out your copyright notice in the Description page of Project Settings.


#include "Terrain/FireWall.h"

#include "Components/SphereComponent.h"
#include "Enemy/EnemyAI.h"

// Sets default values
AFireWall::AFireWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(StaticMeshComponent);
	
	OverlapComponent = CreateDefaultSubobject<USphereComponent>("OverlapSphere");
	OverlapComponent->SetupAttachment(StaticMeshComponent);
	
	OverlapComponent->SetGenerateOverlapEvents(true);
	OverlapComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	
}

// Called when the game starts or when spawned
void AFireWall::BeginPlay()
{
	Super::BeginPlay();
	
	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &AFireWall::OnOverlapBegin);
}

void AFireWall::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEnemyAI* OverlappedActor = Cast<AEnemyAI>(OtherActor))
	{
		IDamageInterface::Execute_DamageEnemy(OverlappedActor,DamageOfObstacle);
	}
}

// Called every frame
void AFireWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

