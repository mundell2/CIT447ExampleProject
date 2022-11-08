// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "UsableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUsableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CIT447_REFPROJECT_API IUsableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Use();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void UseFromWidget(UUserWidget* widget, AGameModeBase* gameMode);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Drop();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Discard();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetItemID(FName id);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		FName GetItemID();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetItemClass(TSubclassOf<UInventoryItem> itemClass);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		TSubclassOf<UInventoryItem> GetItemClass();

};
