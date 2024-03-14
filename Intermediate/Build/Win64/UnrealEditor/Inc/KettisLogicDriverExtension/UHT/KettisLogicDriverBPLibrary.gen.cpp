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
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
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
			{ "GetContextAsActor", &UKettisLogicDriverBPLibrary::execGetContextAsActor },
			{ "GetContextAsActorChecked", &UKettisLogicDriverBPLibrary::execGetContextAsActorChecked },
			{ "GetContextAsCastTo", &UKettisLogicDriverBPLibrary::execGetContextAsCastTo },
			{ "GetContextAsCastToChecked", &UKettisLogicDriverBPLibrary::execGetContextAsCastToChecked },
			{ "GetContextAsCharacter", &UKettisLogicDriverBPLibrary::execGetContextAsCharacter },
			{ "GetContextAsCharacterChecked", &UKettisLogicDriverBPLibrary::execGetContextAsCharacterChecked },
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
		{ "Category", "Utilities|FlowControl" },
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Gets the State Machine Context and Casts it to the Actor c\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Actor" },
		{ "DefaultToSelf", "NodeInstance" },
		{ "HidePin", "NodeInstance" },
		{ "ModuleRelativePath", "Public/KettisLogicDriverBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Gets the State Machine Context and Casts it to the Actor c" },
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
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_DelayStateMachine, "DelayStateMachine" }, // 2846188414
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActor, "GetContextAsActor" }, // 3306934412
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsActorChecked, "GetContextAsActorChecked" }, // 3120547178
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastTo, "GetContextAsCastTo" }, // 3772293397
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCastToChecked, "GetContextAsCastToChecked" }, // 279164738
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacter, "GetContextAsCharacter" }, // 4145321781
		{ &Z_Construct_UFunction_UKettisLogicDriverBPLibrary_GetContextAsCharacterChecked, "GetContextAsCharacterChecked" }, // 3467785941
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
		{ Z_Construct_UClass_UKettisLogicDriverBPLibrary, UKettisLogicDriverBPLibrary::StaticClass, TEXT("UKettisLogicDriverBPLibrary"), &Z_Registration_Info_UClass_UKettisLogicDriverBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UKettisLogicDriverBPLibrary), 1238747716U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_2263793978(TEXT("/Script/KettisLogicDriverExtension"),
		Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
