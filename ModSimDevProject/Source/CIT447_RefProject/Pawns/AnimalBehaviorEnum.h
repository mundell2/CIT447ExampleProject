// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EAnimalBehaviorEnum : uint8
{
	Null,//use this one to check if AnimalBehavior has been set for instance
	Wander,
	WanderInProgress,
	Flee,
	GoHome,
	LookForFood,
	Chase,
	Eat,
	Dying
};