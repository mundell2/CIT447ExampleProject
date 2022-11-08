// Fill out your copyright notice in the Description page of Project Settings.



#include "MyPlayerCharacter.h"

// Sets default values
AMyPlayerCharacter::AMyPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//This code is equivalent to right clicking in the blueprint's event graph
	//and searching for the Event nodes that you first wire the white execution wire from.
	PlayerInputComponent->BindAction("Activate", IE_Pressed, this, &ThisClass::AttemptActivate);
	PlayerInputComponent->BindAxis("MoveForward", this, &ThisClass::ForwardMovement);
	PlayerInputComponent->BindAxis("Strafe", this, &ThisClass::Strafe);
	PlayerInputComponent->BindAxis("LookUp", this, &ThisClass::LookUp);
	PlayerInputComponent->BindAxis("LookLeftRight", this, &ThisClass::LookLeftRight);
}

void AMyPlayerCharacter::ForwardMovement(float axisValue)
{
	//UCharacterMovementComponent* moveComp = GetCharacterMovement();
	AddMovementInput(GetActorForwardVector(), axisValue, false);
}

void AMyPlayerCharacter::Strafe(float axisValue)
{
	AddMovementInput(GetActorRightVector(), axisValue, false);
}

void AMyPlayerCharacter::LookLeftRight(float axisValue)
{
	AddControllerYawInput(axisValue);
}

void AMyPlayerCharacter::LookUp(float axisValue)
{
	AddControllerPitchInput(axisValue);
}

void AMyPlayerCharacter::AttemptActivate()
{
	Helpers::Print("Activated in C++ Land");

	//GetWorld() - Get the current level that this actor is in
	//GetWorld()->SpawnActor
	FHitResult hitData;
	FVector camDirection = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetActorForwardVector();
	FVector camLocation = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();

	bool hitSomething = GetWorld()->LineTraceSingleByChannel(hitData, camLocation, camLocation + camDirection * activateDistance, ECC_Visibility);
	
	if (hitSomething)
	{
		//GetWorld()->DestroyActor(hitData.Actor.Get());
		//ActivateBPOnly(hitData.Actor.Get());//Calls the function that a blueprint has overridden ActivateBPOnly with 
		Activate(hitData.Actor.Get());//Calls the C++ Activate_Implementation AND the blueprint function override, if it exists
	}
}