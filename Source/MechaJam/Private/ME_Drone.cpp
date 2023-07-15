// Fill out your copyright notice in the Description page of Project Settings.


#include "ME_Drone.h"
#include "Components/StaticMeshComponent.h"


void AME_Drone::DealDamage_Implementation(APawn* InstigatorPawn)
{
	Destroy();
}

// Sets default values
AME_Drone::AME_Drone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DroneMesh=CreateDefaultSubobject<UStaticMeshComponent>("DroneMesh");
	RootComponent=DroneMesh;
	
	
}

// Called when the game starts or when spawned
void AME_Drone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AME_Drone::MoveTowardsTarget()
{
	const FVector Direction = GetActorForwardVector()*Speed;
	AddActorWorldOffset(Direction);
}

// Called every frame
void AME_Drone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTowardsTarget();

}

