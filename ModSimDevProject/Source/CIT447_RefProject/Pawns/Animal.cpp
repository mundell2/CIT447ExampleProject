// Fill out your copyright notice in the Description page of Project Settings.


#include "Animal.h"

//Ours
#include "../CustomBlueprintFunctionLibrary.h"

// Sets default values
//Constructor != Construction Script
AAnimal::AAnimal()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(capsuleComp);

	skeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	skeletalMeshComp->AttachToComponent(RootComponent, 
		FAttachmentTransformRules::KeepRelativeTransform);
	//:: = scope resolution operator = look up something inside a data type

	movementComp = 
		CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
}

// Called when the game starts or when spawned
void AAnimal::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle timer;
	
	//World = Level
	//GetWorld()->SpawnActor(...)

	GetWorldTimerManager().SetTimer(timer, this, &AAnimal::AITick, 1, true);
}

// Called every frame
void AAnimal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//we can do visual updates in Tick, and AI things that can be done less often in its own repeating function.
void AAnimal::AITick_Implementation()//_Implementation is because this is a 'BlueprintNativeEvent' 
{
	if (hunger >= seekFoodThreshold)
		ChangeState(EAnimalBehaviorEnum::LookForFood);

}