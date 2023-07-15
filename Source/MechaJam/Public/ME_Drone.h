// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ME_Drone.generated.h"

class UStaticMeshComponent;
UCLASS()
class MECHAJAM_API AME_Drone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AME_Drone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DroneMesh;

	UFUNCTION()
	void MoveTowardsTarget();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Speed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
