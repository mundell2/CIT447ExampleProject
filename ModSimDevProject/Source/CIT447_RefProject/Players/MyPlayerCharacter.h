// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../CustomBlueprintFunctionLibrary.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "MyPlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMannysFunctionSignature2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMannysFunctionSignature);

UCLASS()
class CIT447_REFPROJECT_API AMyPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayerCharacter();

	FMannysFunctionSignature2 mannysFunc2;

	FMannysFunctionSignature mannysFunc;

	UPROPERTY(BlueprintReadWrite)
	float activateDistance = 300;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Event handling from C++
	//These get bound to input events in SetupPlayerInputComponent
	void ForwardMovement(float axisValue);
	void Strafe(float axisValue);
	void LookUp(float axisValue);
	void LookLeftRight(float axisValue);
	void AttemptActivate();

	//These two UFUNCTION techniques can effectively call a Blueprint function from C++
	//BlueprintNativeEvent = Can be overridden in either C++ or Blueprints
	UFUNCTION(BlueprintNativeEvent)//If you need to call code that is only in C++ AND something only in blueprints, use BlueprintNativeEvent
		void Activate(AActor* objectToActivate);
	void Activate_Implementation(AActor* objectToActivate)
	{
		Helpers::Print("From Activate_Implemenation()");
	}

	//Blueprintimplementableevent can only be overridden in blueprints
	UFUNCTION(BlueprintImplementableEvent)
		void ActivateBPOnly(AActor* objectToActivate);

	UFUNCTION(BlueprintCallable)
		void Test()
	{
		Helpers::Print("From Test() in C++");
	}
};
