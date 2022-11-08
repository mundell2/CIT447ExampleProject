// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../CustomBlueprintFunctionLibrary.h"
#include <string>

#include "GridActor.generated.h"

USTRUCT(BlueprintType)
struct FInnerArray
{
	GENERATED_BODY()

	TArray<UStaticMeshComponent*> innerArray;
};

UCLASS()
class CIT447_REFPROJECT_API AGridActor : public AActor
{
	GENERATED_BODY()

	virtual void OnConstruction(const FTransform& Transform);
	
public:	
	// Sets default values for this actor's properties
	AGridActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	TArray<FInnerArray> grid;

	UPROPERTY(EditAnywhere)
	int rows = 2;
	
	UPROPERTY(EditAnywhere)
	int columns = 2;

	UPROPERTY(EditAnywhere)
	float gridSpacingX = 100;
	
	UPROPERTY(EditAnywhere)
	float gridSpacingY = 100;

	UPROPERTY(EditAnywhere)
	UStaticMesh* gridMesh;
};
