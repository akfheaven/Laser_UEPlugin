// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class LaserSDK : ModuleRules
{
	public LaserSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{

            // Add the import library
            PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "lib/x64"));
			PublicAdditionalLibraries.Add("Laser_sdk_lib.lib");

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("Laser_sdk_lib.dll");
		}
        //else if (Target.Platform == UnrealTargetPlatform.Mac)
        //{
        //    PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libExampleLibrary.dylib"));
        //}
	}
}
