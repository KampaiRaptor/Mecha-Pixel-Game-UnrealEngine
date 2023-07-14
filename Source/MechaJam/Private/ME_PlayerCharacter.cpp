// Fill out your copyright notice in the Description page of Project Settings.

#include "ME_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AME_PlayerCharacter::AME_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LegsMesh = CreateDefaultSubobject<UStaticMeshComponent>("LegsMesh");
	LegsMesh -> SetupAttachment(RootComponent);
	
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("BodyMesh");
	BodyMesh -> SetupAttachment(LegsMesh);
	
	ArmsMesh = CreateDefaultSubobject<UStaticMeshComponent>("ArmsMesh");
	ArmsMesh -> SetupAttachment(BodyMesh);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComp->SetupAttachment(LegsMesh);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComp -> SetupAttachment(SpringArmComp);

	GetCharacterMovement()->GravityScale = 0.0f;


}

// Called when the game starts or when spawned
void AME_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AME_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AME_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

