// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPLayserSDK.generated.h"

/**
 * 
 */
UCLASS()
class UE_LASERSDK_API UBPLayserSDK : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
		/** called when something enters the sphere component */
		UFUNCTION(BlueprintCallable, Category = "LaserSDK")
		static int32 GetTracker(int id);
	
};
