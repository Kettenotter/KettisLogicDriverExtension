// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KettisLogicDriverExtension/Public/KettisLogicDriverBPLibrary.h"
#include "../../Source/Runtime/Engine/Classes/Engine/LatentActionManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKettisLogicDriverBPLibrary() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
	KETTISLOGICDRIVEREXTENSION_API UClass* Z_Construct_UClass_UKettisLogicDriverBPLibrary();
	KETTISLOGICDRIVEREXTENSION_API UClass* Z_Construct_UClass_UKettisLogicDriverBPLibrary_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstanceInterface_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_KettisLogicDriverExtension();
// End Cross Module References
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execDelayStateMachine)
	{
		P_GET_OBJECT(USMStateInstance,Z_Param_NodeInstance);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		UKettisLogicDriverBPLibrary::DelayStateMachine(Z_Param_NodeInstance,Z_Param_Duration,Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetAbilitySystemComponentFromContextChecked)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT_REF(UAbilitySystemComponent,Z_Param_Out_Component);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UKettisLogicDriverBPLibrary::GetAbilitySystemComponentFromContextChecked(Z_Param_NodeInstance,Z_Param_Out_Component);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetAbilitySystemComponentFromContext)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAbilitySystemComponent**)Z_Param__Result=UKettisLogicDriverBPLibrary::GetAbilitySystemComponentFromContext(Z_Param_NodeInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetComponentsFromContext)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT(UClass,Z_Param_ComponentClass);
		P_GET_TARRAY_REF(UActorComponent*,Z_Param_Out_Components);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UKettisLogicDriverBPLibrary::GetComponentsFromContext(Z_Param_NodeInstance,Z_Param_ComponentClass,Z_Param_Out_Components);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetComponentFromContext)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT(UClass,Z_Param_ComponentClass);
		P_GET_OBJECT_REF(UActorComponent,Z_Param_Out_Component);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UKettisLogicDriverBPLibrary::GetComponentFromContext(Z_Param_NodeInstance,Z_Param_ComponentClass,Z_Param_Out_Component);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsCastToChecked)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT(UClass,Z_Param_ReturnClass);
		P_GET_OBJECT_REF(UObject,Z_Param_Out_CastContext);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsCastToChecked(Z_Param_NodeInstance,Z_Param_ReturnClass,Z_Param_Out_CastContext);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsCastTo)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT(UClass,Z_Param_ReturnClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsCastTo(Z_Param_NodeInstance,Z_Param_ReturnClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsCharacterChecked)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT_REF(ACharacter,Z_Param_Out_Character);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsCharacterChecked(Z_Param_NodeInstance,Z_Param_Out_Character);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsCharacter)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ACharacter**)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsCharacter(Z_Param_NodeInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsPawnChecked)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT_REF(APawn,Z_Param_Out_Character);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsPawnChecked(Z_Param_NodeInstance,Z_Param_Out_Character);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsPawn)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(APawn**)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsPawn(Z_Param_NodeInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsActorChecked)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_GET_OBJECT_REF(AActor,Z_Param_Out_Actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsActorChecked(Z_Param_NodeInstance,Z_Param_Out_Actor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKettisLogicDriverBPLibrary::execGetContextAsActor)
	{
		P_GET_TINTERFACE(ISMInstanceInterface,Z_Param_NodeInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=UKettisLogicDriverBPLibrary::GetContextAsActor(Z_Param_NodeInstance);
		P_NATIVE_END;
	}
	void UKettisLogicDriverBPLibrary::StaticRegisterNativesUKettisLogicDriverBPLibrary()
	{
		UClass* Class = UKettisLogicDriverBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DelayStateMachine", &UKettisLogicDriverBPLibrary::execDelayStateMachine },
			{ "GetAbilitySystemComponentFromContext", &UKettisLogicDriverBPLibrary::execGetAbilitySystemComponentFromContext },
			{ "GetAbilitySystemComponentFromContextChecked", &UKettisLogicDriverBPLibrary::execGetAbilitySystemComponentFromContextChecked },
			{ "GetComponentFromContext", &UKettisLogicDriverBPLibrary::execGetComponentFromContext },
			{ "GetComponentsFromContext", &UKettisLogicDriverBPLibrary::execGetComponentsFromContext },
			{ "GetContextAsActor", &UKettisLogicDriverBPLibrary::execGetContextAsActor },
			{ "GetContextAsActorChecked", &UKettisLogicDriverBPLibrary::execGetContextAsActorChecked },
			{ "GetContextAsCastTo", &UKettisLogicDriverBPLibrary::execGetContextAsCastTo },
			{ "GetContextAsCastToChecked", &UKettisLogicDriverBPLibrary::execGetContextAsCastToChecked },
			{ "GetContextAsCharacter", &UKettisLogicDriverBPLibrary::execGetContextAsCharacter },
			{ "GetContextAsCharacterChecked", &UKettisLogicDriverBPLibrary::execGetContextAsCharacterChecked },
			{ "GetContextAsPawn", &UKettisLogicDriverBPLibrary::execGetContextAsPawn },
			{ "GetContextAsPawnChecked", &UKettisLogicDriverBPLibrary::execGetContextAsPawnChecked },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics
	{
		struct KettisLogicDriverBPLibrary_eventDelayStateMachine_Parms
		{
			USMStateInstance* NodeInstance;
			float Duration;
			FLatentActionInfo LatentInfo;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventDelayStateMachine_Parms, NodeInstance), Z_Construct_UClass_USMStateInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventDelayStateMachine_Parms, Duration), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventDelayStateMachine_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(0, nullptr) }; // 2674470931
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::NewProp_Duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Utility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* A delay which will stop itself it the state is not active.\n\x09* \n\x09* Only scenario where it might fail is: when a state is exited and entered in the same frame.\n\x09* Because it will abort it on the next update which happens at the end of the frame.\n\x09* This should never happen in State Machines which use non event based logic. And even than it should be very unlikely, still something to keep in mind.\n\x09*/" },
#endif
		{ "DefaultToSelf", "NodeInstance" },
		{ "Duration", "0.2" },
		{ "Keywords", "sleep" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A delay which will stop itself it the state is not active.\n\nOnly scenario where it might fail is: when a state is exited and entered in the same frame.\nBecause it will abort it on the next update which happens at the end of the frame.\nThis should never happen in State Machines which use non event based logic. And even than it should be very unlikely, still something to keep in mind." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "DelayStateMachine", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::KettisLogicDriverBPLibrary_eventDelayStateMachine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::KettisLogicDriverBPLibrary_eventDelayStateMachine_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContext_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			UAbilitySystemComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContext_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_NodeInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContext_Parms, ReturnValue), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Utility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ability System Component from CONTEXT.\n\x09 * Uses the interface.\n\x09 */" },
#endif
		{ "CompactNodeTitle", "ASC" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "HidePin", "NodeInstance" },
		{ "Keywords", "Find, ASC" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ability System Component from CONTEXT.\nUses the interface." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetAbilitySystemComponentFromContext", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContext_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContextChecked_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			UAbilitySystemComponent* Component;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Component_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Component;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContextChecked_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_NodeInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_Component_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_Component = { "Component", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContextChecked_Parms, Component), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_Component_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_Component_MetaData) };
	void Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContextChecked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContextChecked_Parms), &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_Component,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Utility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ability System Component from CONTEXT.\n\x09 * Uses the interface.\n\x09 */" },
#endif
		{ "CompactNodeTitle", "ASC" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "ExpandBoolAsExecs", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "Keywords", "Find, ASC" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ability System Component from CONTEXT.\nUses the interface." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetAbilitySystemComponentFromContextChecked", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContextChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::KettisLogicDriverBPLibrary_eventGetAbilitySystemComponentFromContextChecked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			TSubclassOf<UActorComponent>  ComponentClass;
			UActorComponent* Component;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FClassPropertyParams NewProp_ComponentClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Component_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Component;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_ComponentClass = { "ComponentClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms, ComponentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_Component_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_Component = { "Component", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms, Component), Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_Component_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_Component_MetaData) };
	void Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms), &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_ComponentClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_Component,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Utility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Component from CONTEXT\n\x09 * Finds the first component on the context actor which has the matching class.\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Comp" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "DeterminesOutputType", "ComponentClass" },
		{ "DynamicOutputParam", "Component" },
		{ "ExpandBoolAsExecs", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "Keywords", "Find" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component from CONTEXT\nFinds the first component on the context actor which has the matching class." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetComponentFromContext", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::KettisLogicDriverBPLibrary_eventGetComponentFromContext_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			TSubclassOf<UActorComponent>  ComponentClass;
			TArray<UActorComponent*> Components;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FClassPropertyParams NewProp_ComponentClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Components_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Components_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Components;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_ComponentClass = { "ComponentClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms, ComponentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_Components_Inner = { "Components", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_Components_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_Components = { "Components", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms, Components), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_Components_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_Components_MetaData) };
	void Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms), &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_ComponentClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_Components_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_Components,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Utility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Components from CONTEXT\n\x09 * Finds all the components on the context actor which have the matching class.\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Comps" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "DeterminesOutputType", "ComponentClass" },
		{ "DynamicOutputParam", "Components" },
		{ "ExpandBoolAsExecs", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "Keywords", "Find" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Components from CONTEXT\nFinds all the components on the context actor which have the matching class." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetComponentsFromContext", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::KettisLogicDriverBPLibrary_eventGetComponentsFromContext_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsActor_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			AActor* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsActor_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Gets the State Machine Context and Casts it to the Actor class.\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Actor" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Gets the State Machine Context and Casts it to the Actor class." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsActor", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::KettisLogicDriverBPLibrary_eventGetContextAsActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::KettisLogicDriverBPLibrary_eventGetContextAsActor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsActorChecked_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			AActor* Actor;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsActorChecked_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsActorChecked_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((KettisLogicDriverBPLibrary_eventGetContextAsActorChecked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(KettisLogicDriverBPLibrary_eventGetContextAsActorChecked_Parms), &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
		{ "CompactNodeTitle", "Actor" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "ExpandBoolAsExecs", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsActorChecked", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsActorChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsActorChecked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsCastTo_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			TSubclassOf<UObject>  ReturnClass;
			UObject* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCastTo_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_ReturnClass = { "ReturnClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCastTo_Parms, ReturnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCastTo_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_ReturnClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
		{ "CompactNodeTitle", "Cast" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "DeterminesOutputType", "ReturnClass" },
		{ "DynamicOutputParam", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsCastTo", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCastTo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCastTo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			TSubclassOf<UObject>  ReturnClass;
			UObject* CastContext;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CastContext;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_ReturnClass = { "ReturnClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms, ReturnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_CastContext = { "CastContext", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms, CastContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms), &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_ReturnClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_CastContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
		{ "CompactNodeTitle", "Cast" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "DeterminesOutputType", "ReturnClass" },
		{ "DynamicOutputParam", "CastContext" },
		{ "ExpandBoolAsExecs", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsCastToChecked", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCastToChecked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsCharacter_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			ACharacter* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCharacter_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCharacter_Parms, ReturnValue), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
		{ "CompactNodeTitle", "Character" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsCharacter", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCharacter_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsCharacterChecked_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			ACharacter* Character;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCharacterChecked_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsCharacterChecked_Parms, Character), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((KettisLogicDriverBPLibrary_eventGetContextAsCharacterChecked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(KettisLogicDriverBPLibrary_eventGetContextAsCharacterChecked_Parms), &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_Character,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
		{ "CompactNodeTitle", "Character" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "ExpandEnumAsExecs", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsCharacterChecked", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCharacterChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsCharacterChecked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsPawn_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			APawn* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsPawn_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsPawn_Parms, ReturnValue), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
		{ "CompactNodeTitle", "Pawn" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsPawn", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::KettisLogicDriverBPLibrary_eventGetContextAsPawn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::KettisLogicDriverBPLibrary_eventGetContextAsPawn_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics
	{
		struct KettisLogicDriverBPLibrary_eventGetContextAsPawnChecked_Parms
		{
			TScriptInterface<ISMInstanceInterface> NodeInstance;
			APawn* Character;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_NodeInstance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsPawnChecked_Parms, NodeInstance), Z_Construct_UClass_USMInstanceInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_NodeInstance_MetaData), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_NodeInstance_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KettisLogicDriverBPLibrary_eventGetContextAsPawnChecked_Parms, Character), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((KettisLogicDriverBPLibrary_eventGetContextAsPawnChecked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(KettisLogicDriverBPLibrary_eventGetContextAsPawnChecked_Parms), &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_NodeInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_Character,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::Function_MetaDataParams[] = {
		{ "Category", "LogicDriver|Extension|Casting" },
		{ "CompactNodeTitle", "Pawn" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "ExpandEnumAsExecs", "ReturnValue" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKettisLogicDriverBPLibrary, nullptr, "GetContextAsPawnChecked", nullptr, nullptr, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsPawnChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::KettisLogicDriverBPLibrary_eventGetContextAsPawnChecked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UKettisLogicDriverBPLibrary);
	UClass* Z_Construct_UClass_UKettisLogicDriverBPLibrary_NoRegister()
	{
		return UKettisLogicDriverBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_KettisLogicDriverExtension,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine, "DelayStateMachine" }, // 1201434083
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContext, "GetAbilitySystemComponentFromContext" }, // 795578645
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetAbilitySystemComponentFromContextChecked, "GetAbilitySystemComponentFromContextChecked" }, // 3304614112
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentFromContext, "GetComponentFromContext" }, // 145953511
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetComponentsFromContext, "GetComponentsFromContext" }, // 2315398207
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor, "GetContextAsActor" }, // 1898847949
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked, "GetContextAsActorChecked" }, // 3592170622
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo, "GetContextAsCastTo" }, // 264023569
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked, "GetContextAsCastToChecked" }, // 3617094916
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter, "GetContextAsCharacter" }, // 2334636142
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked, "GetContextAsCharacterChecked" }, // 1339658721
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawn, "GetContextAsPawn" }, // 50640394
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsPawnChecked, "GetContextAsPawnChecked" }, // 615095849
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "KettisLogicDriverBPLibrary.h" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKettisLogicDriverBPLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::ClassParams = {
		&UKettisLogicDriverBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UKettisLogicDriverBPLibrary()
	{
		if (!Z_Registration_Info_UClass_UKettisLogicDriverBPLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UKettisLogicDriverBPLibrary.OuterSingleton, Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UKettisLogicDriverBPLibrary.OuterSingleton;
	}
	template<> KETTISLOGICDRIVEREXTENSION_API UClass* StaticClass<UKettisLogicDriverBPLibrary>()
	{
		return UKettisLogicDriverBPLibrary::StaticClass();
	}
	UKettisLogicDriverBPLibrary::UKettisLogicDriverBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKettisLogicDriverBPLibrary);
	UKettisLogicDriverBPLibrary::~UKettisLogicDriverBPLibrary() {}
	struct Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UKettisLogicDriverBPLibrary, UKettisLogicDriverBPLibrary::StaticClass, TEXT("UKettisLogicDriverBPLibrary"), &Z_Registration_Info_UClass_UKettisLogicDriverBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UKettisLogicDriverBPLibrary), 1960234793U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_3623849987(TEXT("/Script/KettisLogicDriverExtension"),
		Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
