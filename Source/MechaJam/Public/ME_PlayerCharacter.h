// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ME_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UStaticMeshComponent;
UCLASS()
class MECHAJAM_API AME_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AME_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BodyMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ArmsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LegsMesh;

	UPROPERTY(VisibleAnywhere)
	UArrowComponent* ArrowLeft;
	
	UPROPERTY(VisibleAnywhere)
	UArrowComponent* ArrowRight;

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere);
	TSubclassOf<AActor> ProjectileClass;

	void MovementSide(float Value);
	void LookUp(float Value);
	void LookSide (float Value);
	void TriggerShooting();

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
