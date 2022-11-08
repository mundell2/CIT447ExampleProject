// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//UE4's
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h" 
#include "Engine/SkeletalMesh.h" 
#include "Components/CapsuleComponent.h" 
#include "Components/SphereComponent.h"

//Ours
#include "AnimalBehaviorEnum.h"

//This one MUST be last
#include "Animal.generated.h"

UCLASS()
class CIT447_REFPROJECT_API AAnimal : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAnimal();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//BlueprintImplementableEvent = Only has a blueprint implemenation
	//This is how you enable C++ code to call a Blueprint function
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Animal C++")
	void ChangeState(EAnimalBehaviorEnum newState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//BlueprintNativeEvent = Has a C++ implementation and can also be overridden in Blueprints
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animal C++")
	void AITick();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Animal C++ || Components")
	UFloatingPawnMovement* movementComp = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Animal C++ || Components")
	UCapsuleComponent* capsuleComp = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Animal C++ || Components")
	USkeletalMeshComponent* skeletalMeshComp = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int speed = 1200; 

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	EAnimalBehaviorEnum currentBehavior = EAnimalBehaviorEnum::Null;

	UPROPERTY(BlueprintReadWrite)
		int hunger;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int maxHunger = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int seekFoodThreshold = 30;
};
