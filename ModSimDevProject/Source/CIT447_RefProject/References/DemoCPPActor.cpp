// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoCPPActor.h"

// Sets default values
ADemoCPPActor::ADemoCPPActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	//mesh->AttachTo(RootComponent);
	RootComponent = mesh;
	//mesh->RegisterComponent();//Not needed when adding default components in the constructor.
}

// Called when the game starts or when spawned
void ADemoCPPActor::BeginPlay()
{
	Super::BeginPlay();
	mesh->OnComponentHit.AddDynamic(this, &ADemoCPPActor::MyOnHit);
}

// Called every frame
void ADemoCPPActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (waypoints.Num() > 0)
	{
		FVector direction = waypoints[0] - GetActorLocation();
		direction.Normalize();
		FVector normalizedDirection = direction.GetSafeNormal();
		AddActorWorldOffset(normalizedDirection * speed * DeltaTime);
	}
}

void ADemoCPPActor::Test()
{
	Helpers::Print(GetActorLocation().ToString());
}
