// Fill out your copyright notice in the Description page of Project Settings.

#include "GridActor.h"

// Sets default values
AGridActor::AGridActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

// Called when the game starts or when spawned
void AGridActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGridActor::OnConstruction(const FTransform& Transform)
{
	if (gridMesh == nullptr)
		return;

	if (rows < 1)
		rows = 1;

	if (columns < 1)
		columns = 1;

	for (int i = 0; i < grid.Num(); ++i)
		for (int j = 0; j < grid[i].innerArray.Num(); ++j)
			grid[i].innerArray[j]->DestroyComponent();
	grid.Empty();
	
	FAttachmentTransformRules attachRules(EAttachmentRule::KeepRelative, 
		EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, false);
	
	for (int r = 0; r < rows; ++r)
	{
		grid.Add(FInnerArray());
		for (int c = 0; c < columns; ++c)
		{
			UStaticMeshComponent* gridTile = NewObject<UStaticMeshComponent>(this);
			gridTile->RegisterComponent();
			gridTile->AttachToComponent(RootComponent, attachRules);
			gridTile->SetStaticMesh(gridMesh);
			gridTile->SetRelativeLocation(FVector(r * gridSpacingX, c * gridSpacingY, 0));
			gridTile->SetMobility(EComponentMobility::Static);
			grid[r].innerArray.Add(gridTile);
		}
	}
}

