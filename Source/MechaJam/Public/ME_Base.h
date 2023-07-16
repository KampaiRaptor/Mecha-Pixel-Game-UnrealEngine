// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ME_Base.generated.h"

class UBoxComponent;
class UArrowComponent;
UCLASS()
class MECHAJAM_API AME_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AME_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollison;

	UPROPERTY(VisibleAnywhere)
	UArrowComponent* SpawnLocation;
	
	UPROPERTY(EditAnywhere);
	TSubclassOf<AActor> DroneClass;

	UFUNCTION()
	void SpawnNewDrone();

	UFUNCTION()
	void DelayBeforeSpawn(float Delay);

	UFUNCTION()
	void SpeedUpSpawning ();
	

	UPROPERTY(VisibleAnywhere);
	float SpawnDelay;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle TimerHandle_Spawner;
	FTimerHandle TimerHandle_SpeedUp;

};
