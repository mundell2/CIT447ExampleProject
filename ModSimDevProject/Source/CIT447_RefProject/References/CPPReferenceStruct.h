#pragma once

/* 
UStruct Ref: https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Structs/index.html

USTRUCTS are annoying to make, because they need to be added manually via visual studio and 
all the syntax has to be just right, rather than having a way to generate them via the editor.
For future structs just copy this one and change it. 
*/

//UE4
#include "CoreMinimal.h"

#include "CPPReferenceStruct.generated.h"

USTRUCT(BlueprintType, Category = "Helpers")
struct CIT447_REFPROJECT_API FCPPReferenceStruct
{
	GENERATED_USTRUCT_BODY()

	FCPPReferenceStruct()
	{

	}

	UPROPERTY(BlueprintReadWrite)
	int32 someNumber;
};
