#pragma once

//UE4
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "CPPReferenceSceneComponent.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent), Category = "Helpers")
class CIT447_REFPROJECT_API UCPPReferenceSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPPReferenceSceneComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
