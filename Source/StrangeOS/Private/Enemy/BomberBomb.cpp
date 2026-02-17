// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BomberBomb.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "OSCollisionChannels.h"
#include "Components/SphereComponent.h"
#include "Interface/DamageInterface.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ABomberBomb::ABomberBomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>("BombMesh");
	SetRootComponent(BombMesh);
	BombMesh->SetSimulatePhysics(true);
	BombMesh->SetEnableGravity(false);
	
	BombSphereComponent = CreateDefaultSubobject<USphereComponent>("BombSphereComponent");
	BombSphereComponent->SetupAttachment(BombMesh);
	BombSphereComponent->SetGenerateOverlapEvents(true);
	
}

// Called when the game starts or when spawned
void ABomberBomb::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(BombExplode_TimerHandle,
	this,
	&ABomberBomb::ExplodeBomb,
	4.0f);
	
}

void ABomberBomb::ExplodeBomb()
{
	TArray<AActor*> OverlappedActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> ActorsToIgnore;

	// Add the object types you want to detect
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));

	// Optionally ignore self
	ActorsToIgnore.Add(this);

	bool bResult = UKismetSystemLibrary::SphereOverlapActors(
		this,                     
		GetActorLocation(),       
		OverlapSphereSize,                     
		ObjectTypes,                
		AActor::StaticClass(),      
		ActorsToIgnore,              
		OverlappedActors             
	);
	ApplyDamageToActors(OverlappedActors);
	
	UNiagaraComponent* NiagaraEffect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),
		ExplosionEffect, 
		GetActorLocation(),
		FRotator(0.f));
	Destroy();
}

void ABomberBomb::ApplyDamageToActors(TArray<AActor*> FoundActors)
{
	for (AActor* Actor : FoundActors)
	{
		if (Actor->GetClass()->ImplementsInterface(UDamageInterface::StaticClass()))
		{
			IDamageInterface::Execute_DamageEnemy(Actor,0);
		}
	}
}

// Called every frame
void ABomberBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

