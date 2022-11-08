// Fill out your copyright notice in the Description page of Project Settings.


#include "ReferenceActor.h"

// Sets default values
AReferenceActor::AReferenceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReferenceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReferenceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//:: = Scope Resolution Operator (other languages just use .)
//This links this function body to TestFunction2 inside of AReferenceActor 
void AReferenceActor::TestFunction2()
{

}

//This creates a completely new unrelated function
void TestFunction2()
{

}

