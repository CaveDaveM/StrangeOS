// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StrangeOS : ModuleRules
{
	public StrangeOS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"StrangeOS",
			"StrangeOS/Variant_Platforming",
			"StrangeOS/Variant_Platforming/Animation",
			"StrangeOS/Variant_Combat",
			"StrangeOS/Variant_Combat/AI",
			"StrangeOS/Variant_Combat/Animation",
			"StrangeOS/Variant_Combat/Gameplay",
			"StrangeOS/Variant_Combat/Interfaces",
			"StrangeOS/Variant_Combat/UI",
			"StrangeOS/Variant_SideScrolling",
			"StrangeOS/Variant_SideScrolling/AI",
			"StrangeOS/Variant_SideScrolling/Gameplay",
			"StrangeOS/Variant_SideScrolling/Interfaces",
			"StrangeOS/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
