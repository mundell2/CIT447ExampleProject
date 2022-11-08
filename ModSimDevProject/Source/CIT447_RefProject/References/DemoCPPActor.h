// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "../CustomBlueprintFunctionLibrary.h"

//generated.h must be last (unreal problem, not C++)
#include "DemoCPPActor.generated.h"

UCLASS()
class CIT447_REFPROJECT_API ADemoCPPActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADemoCPPActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	float TakeDamage(float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser)
	{
		return 34;
	}

	UFUNCTION(BlueprintCallable)
	void Test();

	UPROPERTY(BlueprintReadWrite)
	int hp;

	UPROPERTY(BlueprintReadWrite)
	AActor* actorToModify;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float speed;
	
	//EditAnywhere = like the public 'eyeball' button in BP land
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="OurC++Code | Meshes")
	UStaticMeshComponent* mesh;

	UFUNCTION()
	void MyOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
	{
		Helpers::Print("In hit event");
	}

private:
	UPROPERTY(EditAnywhere)
	TArray<FVector> waypoints;
};
