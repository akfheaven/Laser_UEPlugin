// Fill out your copyright notice in the Description page of Project Settings.

#include "TrackCompoent.h"
#include "UE_LaserSDK.h"

// Sets default values for this component's properties
UTrackCompoent::UTrackCompoent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	roty180.X = 0;
	roty180.Y = 1;
	roty180.Z = 0;
	roty180.W = 0;
}


// Called when the game starts
void UTrackCompoent::BeginPlay()
{
	Super::BeginPlay();
	pose = FTransform::Identity;
	FUE_LaserSDKModule::InitSdk();
}


// Called every frame
void UTrackCompoent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Tracker* var = FUE_LaserSDKModule::GetTracker(id);
	if (var != NULL) {
		poseTempQuat.W = var->Qw;
		poseTempQuat.X = var->Qx;
		poseTempQuat.Y = var->Qy;
		poseTempQuat.Z = var->Qz;
		pose.SetRotation(roty180 * poseTempQuat * roty180);

		poseTempVec.X = var->Px;
		poseTempVec.Y = var->Py;
		poseTempVec.Z = var->Pz;
		pose.SetLocation(poseTempVec);

	}
	
}

