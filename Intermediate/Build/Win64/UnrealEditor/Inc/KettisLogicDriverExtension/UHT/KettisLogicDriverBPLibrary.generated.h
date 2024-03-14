// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "KettisLogicDriverBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ACharacter;
class ISMInstanceInterface;
class UObject;
class USMStateInstance;
struct FLatentActionInfo;
#ifdef KETTISLOGICDRIVEREXTENSION_KettisLogicDriverBPLibrary_generated_h
#error "KettisLogicDriverBPLibrary.generated.h already included, missing '#pragma once' in KettisLogicDriverBPLibrary.h"
#endif
#define KETTISLOGICDRIVEREXTENSION_KettisLogicDriverBPLibrary_generated_h

#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_SPARSE_DATA
#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDelayStateMachine); \
	DECLARE_FUNCTION(execGetContextAsCastToChecked); \
	DECLARE_FUNCTION(execGetContextAsCastTo); \
	DECLARE_FUNCTION(execGetContextAsCharacterChecked); \
	DECLARE_FUNCTION(execGetContextAsCharacter); \
	DECLARE_FUNCTION(execGetContextAsActorChecked); \
	DECLARE_FUNCTION(execGetContextAsActor);


#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_ACCESSORS
#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUKettisLogicDriverBPLibrary(); \
	friend struct Z_Construct_UClass_UKettisLogicDriverBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UKettisLogicDriverBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/KettisLogicDriverExtension"), NO_API) \
	DECLARE_SERIALIZER(UKettisLogicDriverBPLibrary)


#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UKettisLogicDriverBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UKettisLogicDriverBPLibrary(UKettisLogicDriverBPLibrary&&); \
	NO_API UKettisLogicDriverBPLibrary(const UKettisLogicDriverBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKettisLogicDriverBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKettisLogicDriverBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UKettisLogicDriverBPLibrary) \
	NO_API virtual ~UKettisLogicDriverBPLibrary();


#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_12_PROLOG
#define FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_SPARSE_DATA \
	FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_ACCESSORS \
	FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_INCLASS_NO_PURE_DECLS \
	FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> KETTISLOGICDRIVEREXTENSION_API UClass* StaticClass<class UKettisLogicDriverBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Perforce_Splinterra_5_3_Plugins_KettisLogicDriverExtension_Source_KettisLogicDriverExtension_Public_KettisLogicDriverBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
