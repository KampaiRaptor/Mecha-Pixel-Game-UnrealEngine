// Fill out your copyright notice in the Description page of Project Settings.


#include "ME_Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AME_Projectile::AME_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh=CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
	SetRootComponent(ProjectileMesh);
	
	ProjectileMovementComp=CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	
}

// Called when the game starts or when spawned
void AME_Projectile::BeginPlay()
{
	Super::BeginPlay();
	DestroyAfterDelay(5.0f);
	
}

void AME_Projectile::DestroyAfterDelay(float Delaytime)
{
	GetWorldTimerManager().SetTimer(TimerHandle_Destroy,this, &AME_Projectile::DestroySelf, Delaytime, false);
}

void AME_Projectile::DestroySelf()
{
	Destroy();
}

// Called every frame
void AME_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

