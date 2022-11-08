// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UsableInterface.h"

#include "InventoryItem.generated.h"

/**
 * UObject is the most generic type of class possible in Unreal, 
 * and the base of all other classes (like 'object' in C# or Java)
 * 
 * Use it to make data types used in other systems but aren't 
 * visual or attached to specific actors, such as a Stats object
 * that an actor can have an instance of as a variable instead of 
 * several floats.
 */

 // BlueprintType = can make VARIABLES of this type in Blueprints. Many UEC++ classes inherit this from their parent, like 'Character'
 // Blueprintable = can make NEW CHILD BLUEPRINTS of this type. Many UEC++ classes inherit this from their parent, like 'Character'
UCLASS(BlueprintType, Blueprintable) 
class CIT447_REFPROJECT_API UInventoryItem: public UObject, public IUsableInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
		FName ItemName;
};
