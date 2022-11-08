// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "../CustomBlueprintFunctionLibrary.h"
#include "InventoryItem.h"

#include "Wallet.generated.h"

/*
* 4 Types of delegates (event dispatchers/function pointers) in UEC++
* multicast = multiple objects can listen to it/be bound to it. Can't return values.
* static Single-cast
* static Multi-cast 
* 
* dynamic = can be used in blueprints
* dynamic Single-cast 
* dynamic Multi-cast 
*/
DECLARE_DELEGATE(FRealSimpleDelegateSignature);
DECLARE_DYNAMIC_DELEGATE(FSingleDynamicSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTransactionSucceededSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTransactionFailedSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CIT447_REFPROJECT_API UWallet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWallet();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
		TArray<UInventoryItem*> inventory;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<FName, float> currencies;
	
	UPROPERTY(BlueprintAssignable)
		FTransactionSucceededSignature onTransactionSucceeded;

	UPROPERTY(BlueprintAssignable)
		FTransactionFailedSignature onTransactionFailed;

	UFUNCTION(BlueprintCallable)
		bool MakeTransaction(const TMap<FName, float>& deltaWallet, bool negatePrices = false);
};
