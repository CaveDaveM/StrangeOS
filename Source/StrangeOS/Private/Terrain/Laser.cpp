// Fill out your copyright notice in the Description page of Project Settings.


#include "Terrain/Laser.h"

#include "NiagaraFunctionLibrary.h"
#include "OSCollisionChannels.h"
#include "Components/BoxComponent.h"
#include "Interface/DamageInterface.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(FName("Root"));
	SetRootComponent(Root);
	
	Laser_BoxComponent = CreateDefaultSubobject<UBoxComponent>(FName("Laser_BoxComponent"));
	Laser_BoxComponent->SetBoxExtent(FVector(4000.0f,500.0f,100.0f));
	Laser_BoxComponent->SetRelativeLocation_Direct(FVector(-4000.0f, 0.0f, 0.0f));
	Laser_BoxComponent->SetupAttachment(Root);
	
	Laser_BoxComponent->SetGenerateOverlapEvents(true);
	Laser_BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Laser_BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Laser_BoxComponent->SetCollisionResponseToChannel(EOSCollisionChannel::ECC_Enemy,ECR_Overlap);
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();
	
	Laser_BoxComponent->OnComponentBeginOverlap.AddDynamic(this,&ALaser::OnOverlapBegin);
	
	Laser_BoxComponent->SetRelativeLocation(FVector(4000.0f, 0.0f, 0.0f),true);
	
	UNiagaraComponent* NiagaraLaser = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),
	Laser_NiagaraSystem, 
	GetActorLocation(),
	FRotator(-90.0f, 0.0f, 0.0f));
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALaser::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(UDamageInterface::StaticClass()))
	{
		IDamageInterface::Execute_DamageEnemy(OtherActor,Damage);
	}
}

