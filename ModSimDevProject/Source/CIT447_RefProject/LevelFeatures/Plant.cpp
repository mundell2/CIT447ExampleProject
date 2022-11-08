// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"

#include "NavigationSystem.h" 
#include "Kismet/KismetSystemLibrary.h" 

#include "../CustomChannels.h"

// Sets default values
//Constructor in C++ != Construction Script!
APlant::APlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	minSizeToSpread = maxSize / 2;
	SetActorScale3D(FVector(currentSize, currentSize, currentSize));
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	//Calls parent's BeginPlay
	Super::BeginPlay();
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlant::Grow()
{
	currentSize += growthRate;
	if (currentSize > maxSize)
		currentSize = maxSize;

	SetActorScale3D(FVector(currentSize, currentSize, currentSize));

	if (currentSize > minSizeToSpread)
	{
		if (!IsValid(babyActorClass))
			Helpers::Print("babyActorClass to spawn is null!");
		else
			Spread();
	}
}

void APlant::Spread()
{
	//--------------Attempt to spread and make a new baby plant----------
	FNavLocation babyNavLocation;
	//Note: To use this navigation function, you must add "NavigationSystem" to the Module list in EnviroGame.Build.cs
	UNavigationSystemV1* navSys = UNavigationSystemV1::GetCurrent(GetWorld());
	//bool foundPoint = UNavigationSystemV1::GetCurrent(GetWorld())->GetRandomPointInNavigableRadius(GetActorLocation(), spreadRadius, babyNavLocation);
	bool foundPoint = navSys->GetRandomPointInNavigableRadius(GetActorLocation(), spreadRadius, babyNavLocation);
	if (!foundPoint)
	{
		Helpers::Print("Can't find a NavMesh nearby!");
		return;
	}
	FVector babyLocation;
	babyLocation = babyNavLocation.Location;

	//Raycast to make sure we are over 'arable' land.
	FHitResult hit;//placeholder for results of our linetrace

	//bool arable = GetWorld()->LineTraceSingleByChannel(hit, babyLocation, babyLocation + FVector(0, 0, -50), ArableChannel);
	
	TArray<FHitResult> hits;
	bool arable = GetWorld()->LineTraceMultiByChannel(hits, babyLocation, babyLocation + FVector(0, 0, -50), ArableChannel);

	if (arable)
	{
		//if (hits.Num() == 1)
		if (hits[0].Actor->GetComponentsCollisionResponseToChannel(ArableChannel) == ECollisionResponse::ECR_Block)
		{
			//Check that there isn't already a plant there.
			TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes = { UEngineTypes::ConvertToObjectType(GetRootComponent()->GetCollisionObjectType()) };// ObjectTypeQuery1 == World Static
			TArray<AActor*> actorsToIgnore = { this };
			TArray<AActor*> hitActors;//c++ vector<>, or C# List<>
			bool anotherPlantNear = UKismetSystemLibrary::SphereOverlapActors(this, babyLocation, minDistanceBetweenPlants, objectTypes, babyActorClass, actorsToIgnore, hitActors);
			if (!anotherPlantNear)
			{ 
				//Finally, spawn the baby plant!	
				GetWorld()->SpawnActor/*FromClass*/(babyActorClass, &babyLocation);
			}
		}
	}

	//--------------------Or just do it via Blueprints:------------------
	//MakeBabyPlant();//this 'BlueprintImplementableEvent' lets C++ code call a Blueprint function

	//--------------------Timers in UE4 C++:----------------------------
	//Timer handles let you stop, pause, restart, etc. the timer as needed.
	//If you want to do that though, make the timer handle a class member variable.
	//If you don't need that functionality, just make a temp one here like this to use in SetTimer()
	FTimerHandle timer;

	//method 1: this one lets you add parameters to the function
	//FTimerDelegate timerDelegate;
	//timerDelegate.BindUFunction(this, FName("Spread"));
	//GetWorldTimerManager().SetTimer(timer, timerDelegate, secondsBetweenSpread, false);

	//method 2: least typing, no params allowed.
	GetWorldTimerManager().SetTimer(timer, this, &APlant::Spread, secondsBetweenSpread, false);

	//method 3: a lambda function, if you don't need that functionality anywhere else.
	//GetWorldTimerManager().SetTimer(timer, []() { Helpers::LogWarning("From Lambda Function"); }, secondsBetweenSpread, false);
}

//the _Implementation is required for BlueprintNativeEvents
void APlant::Test1_Implementation()
{
	Helpers::Print("In Test1_Implementation");
}