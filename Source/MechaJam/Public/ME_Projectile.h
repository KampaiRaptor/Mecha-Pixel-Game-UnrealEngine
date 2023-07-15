// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ME_DamageInterface.h"
#include "GameFramework/Actor.h"
#include "ME_Projectile.generated.h"

class UProjectileMovementComponent;
UCLASS()
class MECHAJAM_API AME_Projectile : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AME_Projectile();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMovementComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ProjectileMesh;

	UFUNCTION()
	void DestroyAfterDelay(float Delaytime);
	
	UFUNCTION()
	void DestroySelf();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle TimerHandle_Destroy;


};
