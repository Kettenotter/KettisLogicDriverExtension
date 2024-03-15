// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KettisLogicDriverGAS/Public/TransitionGameplayAbilitySpecific.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTransitionGameplayAbilitySpecific() {}
// Cross Module References
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionExtensionDelegateBinding();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnCanPayMana();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnCanPayMana_NoRegister();
	UPackage* Z_Construct_UPackage__Script_KettisLogicDriverGAS();
// End Cross Module References
	void UTransitionOnCanPayMana::StaticRegisterNativesUTransitionOnCanPayMana()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionOnCanPayMana);
	UClass* Z_Construct_UClass_UTransitionOnCanPayMana_NoRegister()
	{
		return UTransitionOnCanPayMana::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionOnCanPayMana_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionOnCanPayMana_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnCanPayMana_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnCanPayMana_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionGameplayAbilitySpecific.h" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilitySpecific.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionOnCanPayMana_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionOnCanPayMana>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionOnCanPayMana_Statics::ClassParams = {
		&UTransitionOnCanPayMana::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnCanPayMana_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionOnCanPayMana_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UTransitionOnCanPayMana()
	{
		if (!Z_Registration_Info_UClass_UTransitionOnCanPayMana.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionOnCanPayMana.OuterSingleton, Z_Construct_UClass_UTransitionOnCanPayMana_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionOnCanPayMana.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionOnCanPayMana>()
	{
		return UTransitionOnCanPayMana::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionOnCanPayMana);
	UTransitionOnCanPayMana::~UTransitionOnCanPayMana() {}
	struct Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilitySpecific_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilitySpecific_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTransitionOnCanPayMana, UTransitionOnCanPayMana::StaticClass, TEXT("UTransitionOnCanPayMana"), &Z_Registration_Info_UClass_UTransitionOnCanPayMana, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionOnCanPayMana), 711738805U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilitySpecific_h_381364931(TEXT("/Script/KettisLogicDriverGAS"),
		Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilitySpecific_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilitySpecific_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
