// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPPReferenceObject.generated.h"

/**
 * UObject is the most generic type of class possible in Unreal, 
 * and the base of all other classes (like 'object' in C# or Java)
 * 
 * Use it to make data types used in other systems but aren't 
 * visual or attached to specific actors, such as a Stats object
 * that an actor can have an instance of as a variable instead of 
 * several floats.
 */
UCLASS(BlueprintType) // BlueprintType = can make variables of this type in Blueprints. Many UEC++ classes inherit this from their parent, like 'Character'
class CIT447_REFPROJECT_API UCPPReferenceObject : public UObject
{
	GENERATED_BODY()

public:
};
