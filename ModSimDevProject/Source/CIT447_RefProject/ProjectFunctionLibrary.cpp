// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectFunctionLibrary.h"

#include "CustomBlueprintFunctionLibrary.h"

AMyPlayerController* UProjectFunctionLibrary::GetMyPlayerController(UObject* WorldContextObject)
{
	AMyPlayerController* pc = WorldContextObject->GetWorld()->GetFirstPlayerController<AMyPlayerController>();
	if (pc == nullptr)
		Helpers::Print("Failed to get 'MyPlayerController' object.");
	return pc;
}
