// Fill out your copyright notice in the Description page of Project Settings.


#include "ME_Base.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AME_Base::AME_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnLocation=CreateDefaultSubobject<UArrowComponent>("SpawnLocation");
	SpawnLocation->SetupAttachment(RootComponent);

	BoxCollison=CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollison->SetupAttachment(RootComponent);
	BoxCollison->SetCollisionResponseToAllChannels(ECR_Overlap);

	SpawnDelay = 5.0f;
}

// Called when the game starts or when spawned
void AME_Base::BeginPlay()
{
	Super::BeginPlay();
	DelayBeforeSpawn(SpawnDelay);
	GetWorldTimerManager().SetTimer(TimerHandle_SpeedUp,this, &AME_Base::SpeedUpSpawning, 20.0f, true); // Setup Timer that calls function to speed up Spawning
}

void AME_Base::SpawnNewDrone() //Spawn new drone, randomize X and Z
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	FVector Location = SpawnLocation->GetComponentLocation();
	const FRotator Rotation = SpawnLocation->GetComponentRotation();
	
	const float RandomizedX = FMath::FRandRange(-3000.0f,3000.0f);
	const float RandomizedY = FMath::FRandRange(-2000.0f,2000.0f);
	
	Location.X = Location.X + RandomizedX;
	Location.Y = Location.Y + RandomizedY;

	
	const FTransform ArrowLeftTransform = FTransform(Rotation,Location);

	
	GetWorld()->SpawnActor<AActor>(DroneClass, ArrowLeftTransform, SpawnParams);
	DelayBeforeSpawn(SpawnDelay);
}

void AME_Base::SpeedUpSpawning()
{
	SpawnDelay = SpawnDelay - 0.5f;
	SpawnDelay = FMath::Clamp(SpawnDelay,0.5f,5.0f);
	
}

void AME_Base::DelayBeforeSpawn(float Delay)
{
	GetWorldTimerManager().SetTimer(TimerHandle_Spawner,this, &AME_Base::SpawnNewDrone, Delay, false);

}

// Called every frame
void AME_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

