// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJEKT3D_MyCharacterMovement_generated_h
#error "MyCharacterMovement.generated.h already included, missing '#pragma once' in MyCharacterMovement.h"
#endif
#define PROJEKT3D_MyCharacterMovement_generated_h

#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_SPARSE_DATA
#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_RPC_WRAPPERS
#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacterMovement(); \
	friend struct Z_Construct_UClass_AMyCharacterMovement_Statics; \
public: \
	DECLARE_CLASS(AMyCharacterMovement, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Projekt3D"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacterMovement)


#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacterMovement(); \
	friend struct Z_Construct_UClass_AMyCharacterMovement_Statics; \
public: \
	DECLARE_CLASS(AMyCharacterMovement, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Projekt3D"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacterMovement)


#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyCharacterMovement(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacterMovement) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacterMovement); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacterMovement); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacterMovement(AMyCharacterMovement&&); \
	NO_API AMyCharacterMovement(const AMyCharacterMovement&); \
public:


#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacterMovement(AMyCharacterMovement&&); \
	NO_API AMyCharacterMovement(const AMyCharacterMovement&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacterMovement); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacterMovement); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacterMovement)


#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__jumping() { return STRUCT_OFFSET(AMyCharacterMovement, jumping); } \
	FORCEINLINE static uint32 __PPO__cam() { return STRUCT_OFFSET(AMyCharacterMovement, cam); } \
	FORCEINLINE static uint32 __PPO__spring_arm() { return STRUCT_OFFSET(AMyCharacterMovement, spring_arm); } \
	FORCEINLINE static uint32 __PPO__speed() { return STRUCT_OFFSET(AMyCharacterMovement, speed); } \
	FORCEINLINE static uint32 __PPO__sprinting() { return STRUCT_OFFSET(AMyCharacterMovement, sprinting); } \
	FORCEINLINE static uint32 __PPO__crouching() { return STRUCT_OFFSET(AMyCharacterMovement, crouching); } \
	FORCEINLINE static uint32 __PPO__firstPerson() { return STRUCT_OFFSET(AMyCharacterMovement, firstPerson); } \
	FORCEINLINE static uint32 __PPO__kolizja() { return STRUCT_OFFSET(AMyCharacterMovement, kolizja); }


#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_14_PROLOG
#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_PRIVATE_PROPERTY_OFFSET \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_SPARSE_DATA \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_RPC_WRAPPERS \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_INCLASS \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_PRIVATE_PROPERTY_OFFSET \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_SPARSE_DATA \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_INCLASS_NO_PURE_DECLS \
	Projekt3D_Source_Projekt3D_MyCharacterMovement_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJEKT3D_API UClass* StaticClass<class AMyCharacterMovement>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Projekt3D_Source_Projekt3D_MyCharacterMovement_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
