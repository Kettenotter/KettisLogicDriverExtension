// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KettisLogicDriverGAS/Public/TransitionGameplayAbilityGeneric.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTransitionGameplayAbilityGeneric() {}
// Cross Module References
	GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttribute();
	GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayEventData();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagQuery();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionExtensionBase();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionExtensionDelegateBinding();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnAttributeReachZero();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnAttributeReachZero_NoRegister();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayEvent();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayEvent_NoRegister();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayEventCachedData();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayEventCachedData_NoRegister();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayTag();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayTag_NoRegister();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayTagQuery();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionOnGameplayTagQuery_NoRegister();
	UPackage* Z_Construct_UPackage__Script_KettisLogicDriverGAS();
// End Cross Module References
	void UTransitionOnGameplayEvent::StaticRegisterNativesUTransitionOnGameplayEvent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionOnGameplayEvent);
	UClass* Z_Construct_UClass_UTransitionOnGameplayEvent_NoRegister()
	{
		return UTransitionOnGameplayEvent::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionOnGameplayEvent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnlyMatchExact_MetaData[];
#endif
		static void NewProp_OnlyMatchExact_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_OnlyMatchExact;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTransitionExtensionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Ability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionGameplayAbilityGeneric.h" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "PrioritizeCategories", "Ability" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_Tag_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTransitionOnGameplayEvent, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_Tag_MetaData), Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_Tag_MetaData) }; // 2083603574
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_OnlyMatchExact_MetaData[] = {
		{ "Category", "Ability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * If OnlyMatchExact = false it will trigger for nested tags\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If OnlyMatchExact = false it will trigger for nested tags" },
#endif
	};
#endif
	void Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_OnlyMatchExact_SetBit(void* Obj)
	{
		((UTransitionOnGameplayEvent*)Obj)->OnlyMatchExact = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_OnlyMatchExact = { "OnlyMatchExact", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UTransitionOnGameplayEvent), &Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_OnlyMatchExact_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_OnlyMatchExact_MetaData), Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_OnlyMatchExact_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_Tag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::NewProp_OnlyMatchExact,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionOnGameplayEvent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::ClassParams = {
		&UTransitionOnGameplayEvent::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTransitionOnGameplayEvent()
	{
		if (!Z_Registration_Info_UClass_UTransitionOnGameplayEvent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionOnGameplayEvent.OuterSingleton, Z_Construct_UClass_UTransitionOnGameplayEvent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionOnGameplayEvent.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionOnGameplayEvent>()
	{
		return UTransitionOnGameplayEvent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionOnGameplayEvent);
	UTransitionOnGameplayEvent::~UTransitionOnGameplayEvent() {}
	void UTransitionOnGameplayEventCachedData::StaticRegisterNativesUTransitionOnGameplayEventCachedData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionOnGameplayEventCachedData);
	UClass* Z_Construct_UClass_UTransitionOnGameplayEventCachedData_NoRegister()
	{
		return UTransitionOnGameplayEventCachedData::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EventData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTransitionOnGameplayEvent,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Ability" },
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionGameplayAbilityGeneric.h" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
		{ "PrioritizeCategories", "Ability" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::NewProp_EventData_MetaData[] = {
		{ "Category", "Ability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Stores the last Event Data Payload so it can be used by connected states.\n\x09 * Its quite big so its optional. Perhaps it can be improved?\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stores the last Event Data Payload so it can be used by connected states.\nIts quite big so its optional. Perhaps it can be improved?" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::NewProp_EventData = { "EventData", nullptr, (EPropertyFlags)0x0010000000022005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTransitionOnGameplayEventCachedData, EventData), Z_Construct_UScriptStruct_FGameplayEventData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::NewProp_EventData_MetaData), Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::NewProp_EventData_MetaData) }; // 3848146833
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::NewProp_EventData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionOnGameplayEventCachedData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::ClassParams = {
		&UTransitionOnGameplayEventCachedData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTransitionOnGameplayEventCachedData()
	{
		if (!Z_Registration_Info_UClass_UTransitionOnGameplayEventCachedData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionOnGameplayEventCachedData.OuterSingleton, Z_Construct_UClass_UTransitionOnGameplayEventCachedData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionOnGameplayEventCachedData.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionOnGameplayEventCachedData>()
	{
		return UTransitionOnGameplayEventCachedData::StaticClass();
	}
	UTransitionOnGameplayEventCachedData::UTransitionOnGameplayEventCachedData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionOnGameplayEventCachedData);
	UTransitionOnGameplayEventCachedData::~UTransitionOnGameplayEventCachedData() {}
	void UTransitionOnGameplayTag::StaticRegisterNativesUTransitionOnGameplayTag()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionOnGameplayTag);
	UClass* Z_Construct_UClass_UTransitionOnGameplayTag_NoRegister()
	{
		return UTransitionOnGameplayTag::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionOnGameplayTag_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionOnGameplayTag_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTag_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayTag_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Ability" },
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionGameplayAbilityGeneric.h" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "PrioritizeCategories", "Ability" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayTag_Statics::NewProp_Tag_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTransitionOnGameplayTag_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTransitionOnGameplayTag, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTag_Statics::NewProp_Tag_MetaData), Z_Construct_UClass_UTransitionOnGameplayTag_Statics::NewProp_Tag_MetaData) }; // 2083603574
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTransitionOnGameplayTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionOnGameplayTag_Statics::NewProp_Tag,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionOnGameplayTag_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionOnGameplayTag>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionOnGameplayTag_Statics::ClassParams = {
		&UTransitionOnGameplayTag::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTransitionOnGameplayTag_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTag_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTag_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionOnGameplayTag_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTag_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTransitionOnGameplayTag()
	{
		if (!Z_Registration_Info_UClass_UTransitionOnGameplayTag.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionOnGameplayTag.OuterSingleton, Z_Construct_UClass_UTransitionOnGameplayTag_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionOnGameplayTag.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionOnGameplayTag>()
	{
		return UTransitionOnGameplayTag::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionOnGameplayTag);
	UTransitionOnGameplayTag::~UTransitionOnGameplayTag() {}
	void UTransitionOnGameplayTagQuery::StaticRegisterNativesUTransitionOnGameplayTagQuery()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionOnGameplayTagQuery);
	UClass* Z_Construct_UClass_UTransitionOnGameplayTagQuery_NoRegister()
	{
		return UTransitionOnGameplayTagQuery::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TagQuery_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TagQuery;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Ability" },
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionGameplayAbilityGeneric.h" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "PrioritizeCategories", "Ability" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::NewProp_TagQuery_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::NewProp_TagQuery = { "TagQuery", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTransitionOnGameplayTagQuery, TagQuery), Z_Construct_UScriptStruct_FGameplayTagQuery, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::NewProp_TagQuery_MetaData), Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::NewProp_TagQuery_MetaData) }; // 1191468383
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::NewProp_TagQuery,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionOnGameplayTagQuery>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::ClassParams = {
		&UTransitionOnGameplayTagQuery::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTransitionOnGameplayTagQuery()
	{
		if (!Z_Registration_Info_UClass_UTransitionOnGameplayTagQuery.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionOnGameplayTagQuery.OuterSingleton, Z_Construct_UClass_UTransitionOnGameplayTagQuery_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionOnGameplayTagQuery.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionOnGameplayTagQuery>()
	{
		return UTransitionOnGameplayTagQuery::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionOnGameplayTagQuery);
	UTransitionOnGameplayTagQuery::~UTransitionOnGameplayTagQuery() {}
	void UTransitionOnAttributeReachZero::StaticRegisterNativesUTransitionOnAttributeReachZero()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionOnAttributeReachZero);
	UClass* Z_Construct_UClass_UTransitionOnAttributeReachZero_NoRegister()
	{
		return UTransitionOnAttributeReachZero::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Attribute_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Ability" },
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionGameplayAbilityGeneric.h" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "PrioritizeCategories", "Ability" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::NewProp_Attribute_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/TransitionGameplayAbilityGeneric.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTransitionOnAttributeReachZero, Attribute), Z_Construct_UScriptStruct_FGameplayAttribute, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::NewProp_Attribute_MetaData), Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::NewProp_Attribute_MetaData) }; // 359123813
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::NewProp_Attribute,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionOnAttributeReachZero>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::ClassParams = {
		&UTransitionOnAttributeReachZero::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTransitionOnAttributeReachZero()
	{
		if (!Z_Registration_Info_UClass_UTransitionOnAttributeReachZero.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionOnAttributeReachZero.OuterSingleton, Z_Construct_UClass_UTransitionOnAttributeReachZero_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionOnAttributeReachZero.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionOnAttributeReachZero>()
	{
		return UTransitionOnAttributeReachZero::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionOnAttributeReachZero);
	UTransitionOnAttributeReachZero::~UTransitionOnAttributeReachZero() {}
	struct Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilityGeneric_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilityGeneric_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTransitionOnGameplayEvent, UTransitionOnGameplayEvent::StaticClass, TEXT("UTransitionOnGameplayEvent"), &Z_Registration_Info_UClass_UTransitionOnGameplayEvent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionOnGameplayEvent), 2954270479U) },
		{ Z_Construct_UClass_UTransitionOnGameplayEventCachedData, UTransitionOnGameplayEventCachedData::StaticClass, TEXT("UTransitionOnGameplayEventCachedData"), &Z_Registration_Info_UClass_UTransitionOnGameplayEventCachedData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionOnGameplayEventCachedData), 2817773881U) },
		{ Z_Construct_UClass_UTransitionOnGameplayTag, UTransitionOnGameplayTag::StaticClass, TEXT("UTransitionOnGameplayTag"), &Z_Registration_Info_UClass_UTransitionOnGameplayTag, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionOnGameplayTag), 2544055686U) },
		{ Z_Construct_UClass_UTransitionOnGameplayTagQuery, UTransitionOnGameplayTagQuery::StaticClass, TEXT("UTransitionOnGameplayTagQuery"), &Z_Registration_Info_UClass_UTransitionOnGameplayTagQuery, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionOnGameplayTagQuery), 2865591517U) },
		{ Z_Construct_UClass_UTransitionOnAttributeReachZero, UTransitionOnAttributeReachZero::StaticClass, TEXT("UTransitionOnAttributeReachZero"), &Z_Registration_Info_UClass_UTransitionOnAttributeReachZero, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionOnAttributeReachZero), 1721954524U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilityGeneric_h_2020368941(TEXT("/Script/KettisLogicDriverGAS"),
		Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilityGeneric_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionGameplayAbilityGeneric_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
