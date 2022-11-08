// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/Widget.h" 

#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS(HideDropdown)
class CIT447_REFPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void ToggleMouseControl(bool mouseInControl = true, UWidget* widgetToFocus = nullptr)
	{
		SetShowMouseCursor(mouseInControl);
		if (mouseInControl)
		{
			if (widgetToFocus != nullptr)
			{
				SetInputMode(FInputModeUIOnly::FInputModeUIOnly());
				widgetToFocus->SetFocus();
			}
			else
				SetInputMode(FInputModeGameAndUI::FInputModeGameAndUI());
		}
		else
			SetInputMode(FInputModeGameOnly::FInputModeGameOnly());
	}
};
