// Fill out your copyright notice in the Description page of Project Settings.

/*
	Unreal C++ 
	
	https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/GameplayArchitecture/Properties/
 
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReferenceActor.generated.h"

UCLASS()
class CIT447_REFPROJECT_API AReferenceActor : public AActor
{
	GENERATED_BODY()
	
public://Accessible by any external code
	//You can have more than one of each access specifier (public/protected/private) for the sake of organization
	
	//Sets default values for this actor's properties
	//ctor = constructor != Construction Script
	AReferenceActor();

	//UPROPERTY(BlueprintReadWrite)
	UStaticMesh* baseMesh;

	UFUNCTION(BlueprintCallable, Category = "Test Functions | In Class Examples")
		void TestFunction()
	{
		//'Inline' implementation
		//is when you write your function body in a .h file.
		//The rule of thumb is small (1-5 line) functions can be written this way
		//Large functions should be written in a .cpp file.

		AddActorLocalOffset(FVector(100, 0, 0));
	}

	UFUNCTION(BlueprintCallable)
		void TestFunction2();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		UStaticMesh* GetRootMesh()
	{
		return baseMesh;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		UStaticMesh* GetAnyActorsMesh(AActor* someActor)
	{
		if (someActor == nullptr) return nullptr;

		return (UStaticMesh*)someActor->GetComponentByClass(UStaticMesh::StaticClass());//C style cast
		//return reinterpret_cast<UStaticMesh*>(someActor->GetComponentByClass(UStaticMesh::StaticClass()));//C++ style cast
	}

	//In most languages, a function parameter like (FVector location) is passed by value, meaning
	//you pass in a COPY and changing it in the function doesn't change the original one.
	//If you pass by reference or address, like (FVector& location) you can change the original variable passed in.
	//Doing that intentionally to get additional 'return' values out of a function is a common practice.
		//(where normally functions can only 'output' or return 1 value)
	//In unreal, function parameters that are passed by reference with an & are turned into OUTPUT pins instead of input pins.
	UFUNCTION(BlueprintCallable)
		void GetUsefulInfo(FVector& actorLocation, FRotator& actorRotation, FString& actorName)
	{
		actorLocation = GetActorLocation();
		actorRotation = GetActorRotation();
		actorName = GetName();
	}


protected://Accessible by this class or any child class
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//* = Pointer = Memory Address of an object of type UStaticMesh
	//~= Reference in C#/Java/Etc.

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Test(AActor& actorReference)
	{
		//In C++ a reference is a specific type of pointer with additional restrictions
			//actorReference cannot be redirected to point at something else (a pointer could be)
			//actorReference cannot be null (a pointer could be)
			//And because of those restrictions in C++ we can treat 
			//	a 'reference' like a normal object instead of like a pointer.
	}

	void Test2(AActor* actorPointer)
	{

	}

private://Only accessible within the code (function implementations) of this class

};
