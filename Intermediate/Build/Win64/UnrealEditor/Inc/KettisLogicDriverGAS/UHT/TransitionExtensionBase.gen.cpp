// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KettisLogicDriverGAS/Public/TransitionExtensionBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTransitionExtensionBase() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionExtensionBase();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionExtensionBase_NoRegister();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionExtensionDelegateBinding();
	KETTISLOGICDRIVERGAS_API UClass* Z_Construct_UClass_UTransitionExtensionDelegateBinding_NoRegister();
	KETTISLOGICDRIVERGAS_API UScriptStruct* Z_Construct_UScriptStruct_FNodeIconDataTableRow();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_Base_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMTransitionInstance();
	UPackage* Z_Construct_UPackage__Script_KettisLogicDriverGAS();
// End Cross Module References

static_assert(std::is_polymorphic<FNodeIconDataTableRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FNodeIconDataTableRow cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_NodeIconDataTableRow;
class UScriptStruct* FNodeIconDataTableRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_NodeIconDataTableRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_NodeIconDataTableRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNodeIconDataTableRow, (UObject*)Z_Construct_UPackage__Script_KettisLogicDriverGAS(), TEXT("NodeIconDataTableRow"));
	}
	return Z_Registration_Info_UScriptStruct_NodeIconDataTableRow.OuterSingleton;
}
template<> KETTISLOGICDRIVERGAS_API UScriptStruct* StaticStruct<FNodeIconDataTableRow>()
{
	return FNodeIconDataTableRow::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeIcon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NodeIcon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IconSize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_IconSize;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNodeIconDataTableRow>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_NodeIcon_MetaData[] = {
		{ "Category", "NodeIconDataTableRow" },
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_NodeIcon = { "NodeIcon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNodeIconDataTableRow, NodeIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_NodeIcon_MetaData), Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_NodeIcon_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_IconSize_MetaData[] = {
		{ "Category", "NodeIconDataTableRow" },
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_IconSize = { "IconSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNodeIconDataTableRow, IconSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_IconSize_MetaData), Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_IconSize_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_NodeIcon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewProp_IconSize,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"NodeIconDataTableRow",
		Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::PropPointers),
		sizeof(FNodeIconDataTableRow),
		alignof(FNodeIconDataTableRow),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FNodeIconDataTableRow()
	{
		if (!Z_Registration_Info_UScriptStruct_NodeIconDataTableRow.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_NodeIconDataTableRow.InnerSingleton, Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_NodeIconDataTableRow.InnerSingleton;
	}
	void UTransitionExtensionBase::StaticRegisterNativesUTransitionExtensionBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionExtensionBase);
	UClass* Z_Construct_UClass_UTransitionExtensionBase_NoRegister()
	{
		return UTransitionExtensionBase::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionExtensionBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeIconDataTable_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NodeIconDataTable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionExtensionBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMTransitionInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionExtensionBase_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Ability" },
		{ "Category", "GameplayAbility" },
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionExtensionBase.h" },
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "PrioritizeCategories", "Ability" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionExtensionBase_Statics::NewProp_NodeIconDataTable_MetaData[] = {
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTransitionExtensionBase_Statics::NewProp_NodeIconDataTable = { "NodeIconDataTable", nullptr, (EPropertyFlags)0x0010000800000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTransitionExtensionBase, NodeIconDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionBase_Statics::NewProp_NodeIconDataTable_MetaData), Z_Construct_UClass_UTransitionExtensionBase_Statics::NewProp_NodeIconDataTable_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTransitionExtensionBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionExtensionBase_Statics::NewProp_NodeIconDataTable,
	};
#endif // WITH_EDITORONLY_DATA
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionExtensionBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionExtensionBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionExtensionBase_Statics::ClassParams = {
		&UTransitionExtensionBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		IF_WITH_EDITORONLY_DATA(Z_Construct_UClass_UTransitionExtensionBase_Statics::PropPointers, nullptr),
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		IF_WITH_EDITORONLY_DATA(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionBase_Statics::PropPointers), 0),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionExtensionBase_Statics::Class_MetaDataParams)
	};
#if WITH_EDITORONLY_DATA
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionBase_Statics::PropPointers) < 2048);
#endif
	UClass* Z_Construct_UClass_UTransitionExtensionBase()
	{
		if (!Z_Registration_Info_UClass_UTransitionExtensionBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionExtensionBase.OuterSingleton, Z_Construct_UClass_UTransitionExtensionBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionExtensionBase.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionExtensionBase>()
	{
		return UTransitionExtensionBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionExtensionBase);
	UTransitionExtensionBase::~UTransitionExtensionBase() {}
	DEFINE_FUNCTION(UTransitionExtensionDelegateBinding::execTestCondition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->TestCondition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTransitionExtensionDelegateBinding::execTriggerUpdate)
	{
		P_GET_UBOOL(Z_Param_bAllowManualTaking);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TriggerUpdate(Z_Param_bAllowManualTaking);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTransitionExtensionDelegateBinding::execBindDelegates)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BindDelegates();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTransitionExtensionDelegateBinding::execPostBeginInitialize)
	{
		P_GET_OBJECT(USMStateInstance_Base,Z_Param_StateInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PostBeginInitialize(Z_Param_StateInstance);
		P_NATIVE_END;
	}
	void UTransitionExtensionDelegateBinding::StaticRegisterNativesUTransitionExtensionDelegateBinding()
	{
		UClass* Class = UTransitionExtensionDelegateBinding::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BindDelegates", &UTransitionExtensionDelegateBinding::execBindDelegates },
			{ "PostBeginInitialize", &UTransitionExtensionDelegateBinding::execPostBeginInitialize },
			{ "TestCondition", &UTransitionExtensionDelegateBinding::execTestCondition },
			{ "TriggerUpdate", &UTransitionExtensionDelegateBinding::execTriggerUpdate },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Binds the delegates. Is separate from post initialize because they only need to be bound if the transition was not already taken.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Binds the delegates. Is separate from post initialize because they only need to be bound if the transition was not already taken." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding, nullptr, "BindDelegates", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics
	{
		struct TransitionExtensionDelegateBinding_eventPostBeginInitialize_Parms
		{
			USMStateInstance_Base* StateInstance;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StateInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::NewProp_StateInstance = { "StateInstance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TransitionExtensionDelegateBinding_eventPostBeginInitialize_Parms, StateInstance), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::NewProp_StateInstance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Called after the Begin play of the previous State.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Called after the Begin play of the previous State." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding, nullptr, "PostBeginInitialize", nullptr, nullptr, Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::TransitionExtensionDelegateBinding_eventPostBeginInitialize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::TransitionExtensionDelegateBinding_eventPostBeginInitialize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics
	{
		struct TransitionExtensionDelegateBinding_eventTestCondition_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TransitionExtensionDelegateBinding_eventTestCondition_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TransitionExtensionDelegateBinding_eventTestCondition_Parms), &Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Test the condition. For example if the gameplay tag is present.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Test the condition. For example if the gameplay tag is present." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding, nullptr, "TestCondition", nullptr, nullptr, Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::TransitionExtensionDelegateBinding_eventTestCondition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::TransitionExtensionDelegateBinding_eventTestCondition_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics
	{
		struct TransitionExtensionDelegateBinding_eventTriggerUpdate_Parms
		{
			bool bAllowManualTaking;
		};
		static void NewProp_bAllowManualTaking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowManualTaking;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::NewProp_bAllowManualTaking_SetBit(void* Obj)
	{
		((TransitionExtensionDelegateBinding_eventTriggerUpdate_Parms*)Obj)->bAllowManualTaking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::NewProp_bAllowManualTaking = { "bAllowManualTaking", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TransitionExtensionDelegateBinding_eventTriggerUpdate_Parms), &Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::NewProp_bAllowManualTaking_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::NewProp_bAllowManualTaking,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Updates the bStatus and will take the transition if possible.\n\x09 * Calls TestCondition() and will use bInvertCondition.\n\x09 * \n\x09 * 1. Called on PostBeginInitialize\n\x09 * 2. Every time the delegate is triggered\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Updates the bStatus and will take the transition if possible.\n* Calls TestCondition() and will use bInvertCondition.\n*\n* 1. Called on PostBeginInitialize\n* 2. Every time the delegate is triggered" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTransitionExtensionDelegateBinding, nullptr, "TriggerUpdate", nullptr, nullptr, Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::TransitionExtensionDelegateBinding_eventTriggerUpdate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::TransitionExtensionDelegateBinding_eventTriggerUpdate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTransitionExtensionDelegateBinding);
	UClass* Z_Construct_UClass_UTransitionExtensionDelegateBinding_NoRegister()
	{
		return UTransitionExtensionDelegateBinding::StaticClass();
	}
	struct Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInvertCondition_MetaData[];
#endif
		static void NewProp_bInvertCondition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInvertCondition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsEventBased_MetaData[];
#endif
		static void NewProp_bIsEventBased_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEventBased;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTransitionExtensionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverGAS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UTransitionExtensionDelegateBinding_BindDelegates, "BindDelegates" }, // 2468440611
		{ &Z_Construct_UFunction_UTransitionExtensionDelegateBinding_PostBeginInitialize, "PostBeginInitialize" }, // 3115009576
		{ &Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TestCondition, "TestCondition" }, // 4071017945
		{ &Z_Construct_UFunction_UTransitionExtensionDelegateBinding_TriggerUpdate, "TriggerUpdate" }, // 1313601360
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Ability" },
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "TransitionExtensionBase.h" },
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "PrioritizeCategories", "Ability" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bInvertCondition_MetaData[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
	};
#endif
	void Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bInvertCondition_SetBit(void* Obj)
	{
		((UTransitionExtensionDelegateBinding*)Obj)->bInvertCondition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bInvertCondition = { "bInvertCondition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UTransitionExtensionDelegateBinding), &Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bInvertCondition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bInvertCondition_MetaData), Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bInvertCondition_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bIsEventBased_MetaData[] = {
		{ "Category", "Ability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * If enabled will use event based system. Will run initialize logic after the begin play of the previous node.\n\x09 * If disabled will run the logic in the initialize phase and never call \"take manually bound transition\".\n\x09 * (This is mostly for easy debugging to make sure everything works)\n\x09 * \n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/TransitionExtensionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If enabled will use event based system. Will run initialize logic after the begin play of the previous node.\n* If disabled will run the logic in the initialize phase and never call \"take manually bound transition\".\n* (This is mostly for easy debugging to make sure everything works)" },
#endif
	};
#endif
	void Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bIsEventBased_SetBit(void* Obj)
	{
		((UTransitionExtensionDelegateBinding*)Obj)->bIsEventBased = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bIsEventBased = { "bIsEventBased", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UTransitionExtensionDelegateBinding), &Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bIsEventBased_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bIsEventBased_MetaData), Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bIsEventBased_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bInvertCondition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::NewProp_bIsEventBased,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTransitionExtensionDelegateBinding>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::ClassParams = {
		&UTransitionExtensionDelegateBinding::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::Class_MetaDataParams), Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTransitionExtensionDelegateBinding()
	{
		if (!Z_Registration_Info_UClass_UTransitionExtensionDelegateBinding.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTransitionExtensionDelegateBinding.OuterSingleton, Z_Construct_UClass_UTransitionExtensionDelegateBinding_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTransitionExtensionDelegateBinding.OuterSingleton;
	}
	template<> KETTISLOGICDRIVERGAS_API UClass* StaticClass<UTransitionExtensionDelegateBinding>()
	{
		return UTransitionExtensionDelegateBinding::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTransitionExtensionDelegateBinding);
	UTransitionExtensionDelegateBinding::~UTransitionExtensionDelegateBinding() {}
	struct Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_Statics::ScriptStructInfo[] = {
		{ FNodeIconDataTableRow::StaticStruct, Z_Construct_UScriptStruct_FNodeIconDataTableRow_Statics::NewStructOps, TEXT("NodeIconDataTableRow"), &Z_Registration_Info_UScriptStruct_NodeIconDataTableRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNodeIconDataTableRow), 907146664U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTransitionExtensionBase, UTransitionExtensionBase::StaticClass, TEXT("UTransitionExtensionBase"), &Z_Registration_Info_UClass_UTransitionExtensionBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionExtensionBase), 2168996821U) },
		{ Z_Construct_UClass_UTransitionExtensionDelegateBinding, UTransitionExtensionDelegateBinding::StaticClass, TEXT("UTransitionExtensionDelegateBinding"), &Z_Registration_Info_UClass_UTransitionExtensionDelegateBinding, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTransitionExtensionDelegateBinding), 2877673902U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_238589599(TEXT("/Script/KettisLogicDriverGAS"),
		Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverGAS_Public_TransitionExtensionBase_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
