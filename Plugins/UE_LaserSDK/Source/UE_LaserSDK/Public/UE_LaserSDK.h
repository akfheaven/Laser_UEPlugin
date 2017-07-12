// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "AllowWindowsPlatformTypes.h"
#include "LayserSDK.h"
#include "HideWindowsPlatformTypes.h"
#include "ModuleManager.h"


class FUE_LaserSDKModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
private:
	/** Handle to the test dll we will load */
	void*	LibraryHandle;
	static LayserSDK *sdk;
	static Tracker *curTracker;
	static bool isIinit;
public :
	static Tracker* GetTracker(int id);
	static void InitSdk();
};