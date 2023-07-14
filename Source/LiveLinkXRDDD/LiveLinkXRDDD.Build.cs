// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LiveLinkXRDDD : ModuleRules
{
	public LiveLinkXRDDD(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Networking",
				"Sockets",
				"LiveLinkInterface",
				"Messaging",
				"UdpMessaging",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"HeadMountedDisplay",
				"Slate",
				"SlateCore",
			}
			);
	}
}
