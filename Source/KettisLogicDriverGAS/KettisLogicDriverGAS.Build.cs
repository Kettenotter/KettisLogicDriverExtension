﻿using System.IO;
using UnrealBuildTool;

public class KettisLogicDriverGAS : ModuleRules
{
    public KettisLogicDriverGAS(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "SMSystem",
                "GameplayAbilities",
                "GameplayTags",
                "AbilitySMEntity",
            }
        );

        //__ Here I exclude my Project Specific Modules so that it still compiles __//
        
        bool bIncludeKettenotterSpecific = false;
        
        if (bIncludeKettenotterSpecific)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "AbilitySMEntity"
                    // ... add other public dependencies that you statically link with here ...
                }
            );
        }

        PublicDefinitions.Add("WITH_KETTENOTTER_SPECIFIC=" + (bIncludeKettenotterSpecific ? "1" : "0"));



    }
    
}