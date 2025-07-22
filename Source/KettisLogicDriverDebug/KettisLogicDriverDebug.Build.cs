using UnrealBuildTool;

public class KettisLogicDriverDebug : ModuleRules
{
    public KettisLogicDriverDebug(ReadOnlyTargetRules Target) : base(Target)
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
                "SMExtendedRuntime", 
                "SMSystem",
                "GameplayAbilities",
                "KettisLogicDriverGAS",
                "GameplayTags"
            }
        );
    }
}