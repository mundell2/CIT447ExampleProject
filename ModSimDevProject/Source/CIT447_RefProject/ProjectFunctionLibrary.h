// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//UE's
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

//Ours
#include "Players/MyPlayerController.h"
#include "ProjectFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CIT447_REFPROJECT_API UProjectFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//Func for getting our C++ Player Controller without needing a cast node.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"), Category = "Foundation|C++")
	static AMyPlayerController* GetMyPlayerController(UObject* WorldContextObject);
};
