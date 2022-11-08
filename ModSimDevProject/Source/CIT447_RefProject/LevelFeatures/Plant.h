// Fill out your copyright notice in the Description page of Project Settings.

//*****************************
//Remember if building fails, always read the Output window, not the error log.
//*****************************

#pragma once

//UE4's
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

//Ours
#include "../CustomBlueprintFunctionLibrary.h"

//This one MUST be last.
#include "Plant.generated.h"

UCLASS()
class CIT447_REFPROJECT_API APlant : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlant();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform)
	{
		//Helpers::LogWarning("In C++ Version of a Ctor Script!");
	}

	//private/protected/public only affect how other C++ code will see these members;
		//they do not effect how the editor/blueprints see your C++ code.
		//Only the property/function specifiers affect how blueprints see your C++ code.
		//However, some specifiers will be restricted by the access specifier 
			//BlueprintReadWrite variables can't be private
			//BlueprintNativeEvent, BlueprintImplementableEvent functions can't be private
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//to show up in the editor, variables must be 'UPROPERTY()'s'
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		//amount size changes each second
		float growthRate = .5f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		float maxSize = 4;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		float currentSize = .3f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		float minSizeToSpread = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		float secondsBetweenSpread = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		float spreadRadius = 300;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		float minDistanceBetweenPlants = 250;

	UFUNCTION(BlueprintCallable, Category = "Plant C++")
		void Grow();

	UFUNCTION(BlueprintCallable, Category = "Plant C++")
		void Spread();

	//BlueprintNativeEvent = It has a C++ implementation but can be overriden with a blueprint implementation
	UFUNCTION(BlueprintNativeEvent, Category = "Plant C++")
		void Test1();

	//BlueprintImplementableEvent = It must be implemented in blueprints. 
	UFUNCTION(BlueprintImplementableEvent, Category = "Plant C++")
		void MakeBabyPlant();

	//This is equivalent to doing 'public GameObject prefabToSpawn;' in Unity.
	//Or having a 'public' (EditAnywhere) Actor CLASS reference (the purple ones) in Blueprint-land
	//Except that it specifically must be a Plant or child of Plant (only those show in the drop-down box)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant C++")
		TSubclassOf<APlant> babyActorClass;
};
