// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "UE_LaserSDK.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"
#include "ExampleLibrary.h"



#define LOCTEXT_NAMESPACE "FUE_LaserSDKModule"

LayserSDK* FUE_LaserSDKModule::sdk = NULL;
Tracker* FUE_LaserSDKModule::curTracker = NULL;
bool FUE_LaserSDKModule::isIinit = false;
void FUE_LaserSDKModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("UE_LaserSDK")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath, LaserDLLPath;
#if PLATFORM_WINDOWS
	//LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UE_LaserSDKLibrary/Win64/ExampleLibrary.dll"));

#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/UE_LaserSDKLibrary/Mac/Release/libExampleLibrary.dylib"));
#endif // PLATFORM_WINDOWS

	//ExampleLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	InitSdk();
}

void FUE_LaserSDKModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(LibraryHandle);
	LibraryHandle = nullptr;
}

Tracker * FUE_LaserSDKModule::GetTracker(int id)
{
	if (sdk != NULL) {
		return sdk->GetChipData(id);
	}
	return NULL;
}

void FUE_LaserSDKModule::InitSdk()
{
	if (isIinit) return;
	FString LaserDLLPath;
	LaserDLLPath = FPaths::Combine(TEXT("Y:/Projects/UEProjs/UELaserSDK/Plugins/UE_LaserSDK/Source/ThirdParty/LaserSDK/lib/x64/Laser_sdk_lib.dll"));
	//LaserDLLPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/LaserSDK/lib/x64/Laser_sdk_lib.dll"));
	void* LibraryHandle = !LaserDLLPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LaserDLLPath) : nullptr;

	if (LibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
		//ExampleLibraryFunction();
		//FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibrary", "load example third party library"));

		if (sdk == NULL) {
			sdk = new LayserSDK();
			sdk->Start();
			isIinit = true;
		}
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load third party library dll"));
	}

	
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUE_LaserSDKModule, UE_LaserSDK)