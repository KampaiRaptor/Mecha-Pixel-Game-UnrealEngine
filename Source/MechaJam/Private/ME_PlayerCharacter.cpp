// Fill out your copyright notice in the Description page of Project Settings.

#include "ME_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"
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
	SpringArmComp -> bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComp -> SetupAttachment(SpringArmComp);

	GetCharacterMovement()->GravityScale = 0.0f;
	Speed = 10.0f;


	ArrowLeft = CreateDefaultSubobject<UArrowComponent>("ArrowLeft");
	ArrowLeft->SetupAttachment(ArmsMesh);

	ArrowRight = CreateDefaultSubobject<UArrowComponent>("ArrowRight");
	ArrowRight->SetupAttachment(ArmsMesh);

}

// Called when the game starts or when spawned
void AME_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AME_PlayerCharacter::TriggerShooting()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	const FVector ArrowLeftLocation = ArrowLeft->GetComponentLocation();
	const FRotator ArrowLeftRotation = ArrowLeft->GetComponentRotation();
	const FTransform ArrowLeftTransform = FTransform(ArrowLeftRotation,ArrowLeftLocation);

	const FVector ArrowRightLocation = ArrowRight->GetComponentLocation();
	const FRotator ArrowRightRotation = ArrowRight->GetComponentRotation();
	const FTransform ArrowRightTransform = FTransform(ArrowRightRotation,ArrowRightLocation);

	
	GetWorld()->SpawnActor<AActor>(ProjectileClass, ArrowLeftTransform, SpawnParams);
	GetWorld()->SpawnActor<AActor>(ProjectileClass, ArrowRightTransform, SpawnParams);
}

void AME_PlayerCharacter::MovementSide(float Value)
{
	const float CurrentRoll = LegsMesh->GetRelativeRotation().Roll;
	const float NewRoll = CurrentRoll + Value * 0.2f;
	const float ClampedRoll = FMath::Clamp(NewRoll, -20.0f,20.0f);
	FRotator NewRotation (0.0f,0.0f, ClampedRoll);
	
	//LegsMesh->SetRelativeRotation(NewRotation); Not using
	
}

void AME_PlayerCharacter::LookUp(float Value)
{
	const float CameraInput = Value * 0.1f * -1;
	AddControllerPitchInput(CameraInput);
	
	const FRotator CurrentRotation = ArmsMesh->GetRelativeRotation();
	const float NewPitch = CurrentRotation.Pitch + Value * 0.5;
	const float ClampedRotation = FMath::Clamp(NewPitch, 0.0f, 90.0f);
	const FRotator NewRotation (ClampedRotation, 0.0f,0.0f);
		
	ArmsMesh->SetRelativeRotation(NewRotation);

}

void AME_PlayerCharacter::LookSide(float Value)
{
	const float CameraInput = Value * 0.1f;
	AddControllerYawInput(CameraInput);
	
	const FRotator CurrentRotation = BodyMesh->GetRelativeRotation();
	const float NewPitch = CurrentRotation.Yaw + Value * 0.25;
	const float ClampedRotation = FMath::Clamp(NewPitch, -90.0f, 90.0f);
	const FRotator NewRotation (0.0f, ClampedRotation,0.0f);
		
	BodyMesh->SetRelativeRotation(NewRotation);
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

	PlayerInputComponent->BindAxis("MouseY", this, &AME_PlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("MouseX", this, &AME_PlayerCharacter::LookSide);
	PlayerInputComponent->BindAxis("MovementSide", this, &AME_PlayerCharacter::MovementSide);
	PlayerInputComponent->BindAction("Shooting",IE_Pressed,this, &AME_PlayerCharacter::TriggerShooting);



}

