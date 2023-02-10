// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MedievelPuzzle : ModuleRules
{
	public MedievelPuzzle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
