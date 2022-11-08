// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/* 
*/

UENUM(BlueprintType)
enum class EBuildingType : uint8
{
	Uninitialized,
	Economic, 
	Military,
	Housing,
	Enemy,
	Other
};