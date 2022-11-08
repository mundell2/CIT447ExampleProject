// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//My Includes
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

//Unreal Engine Stuff Includes
//

//Generated.h must be last
#include "CustomBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CIT447_REFPROJECT_API UCustomBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static void Print(FString text);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static UActorComponent* SpawnActorComponent(TSubclassOf<UActorComponent> componentClass, AActor* owner);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static USceneComponent* SpawnSceneComponent(TSubclassOf<USceneComponent> componentClass, AActor* owner, USceneComponent* attachTo = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static void SortByBoundsSize(UPARAM(ref) TArray<AActor*>& arr);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Helper Functions")//BlueprintPure means no white execution pin; it -shouldn't- change any member variables.
		static bool HasComponent(const AActor* actor, const FName tag, const TSubclassOf<UActorComponent> componentClass);
};

typedef UCustomBlueprintFunctionLibrary Helpers; 