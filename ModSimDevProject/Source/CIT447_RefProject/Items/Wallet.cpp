// Fill out your copyright notice in the Description page of Project Settings.


#include "Wallet.h"

// Sets default values for this component's properties
UWallet::UWallet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWallet::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWallet::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UWallet::MakeTransaction(const TMap<FName, float>& deltaWallet, bool negatePrices)
{
	//deltaWallet Must be a const reference parameter so it 
		//1) (as a reference) it doesn't COPY the wallet and 
		//2) (because its const) appears as an input pin, not an output pin.
		//Also we don't have to check if a reference in C++ is null as it isn't allowed to be null anyway
		//int& num; = reference, int* num; = pointer, reference = specialized kind of pointer. This is C++, not Unreal specific.

	//Can't use indices like map[i] on a map. 
	//It isn't a 'Random Access' Data structure like an array, C++ vector, Java List, etc.
	//for (int i = 0; i < deltaWallet->currencies.Num(); ++i)

	bool atLeast1Subtraction = false;//just to prevent the 2nd loop from running unnecessarily.

	for (auto it = deltaWallet.CreateConstIterator(); it; ++it)
	{
		float val = negatePrices ? -it->Value : it->Value;

		Helpers::Print(FString::SanitizeFloat(val));
		
		if (val > 0)
		{
			if (currencies.Contains(it->Key))
				currencies[it->Key] += val;
			else
				currencies.Add(it->Key, val);
		}
		else
		{
			if (currencies.Contains(it->Key))
			{
				//Do we have enough to buy this?
				if (currencies[it->Key] >= -val)//or if(currencies[it->Key] + val >= 0)
					atLeast1Subtraction = true;
				else
				{
					Helpers::Print("We don't have enough for that!");
					onTransactionFailed.Broadcast();
					return false;
				}
			}
			else
			{
				Helpers::Print("deltaWallet asked for something we don't have");
				onTransactionFailed.Broadcast();
				return false;
			}
		}
	}

	if (atLeast1Subtraction)//If we got here then we can afford everything; otherwise a return false was hit above.
		for (auto it = deltaWallet.CreateConstIterator(); it; ++it)
			currencies[it->Key] += negatePrices ? -it->Value : it->Value;

	Helpers::Print("Transaction Successful");
	onTransactionSucceeded.Broadcast();
	return true;
}