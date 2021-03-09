// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Projekt3D/MyCharacterMovement.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacterMovement() {}
// Cross Module References
	PROJEKT3D_API UClass* Z_Construct_UClass_AMyCharacterMovement_NoRegister();
	PROJEKT3D_API UClass* Z_Construct_UClass_AMyCharacterMovement();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Projekt3D();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	PROJEKT3D_API UClass* Z_Construct_UClass_ASunSword_NoRegister();
	PROJEKT3D_API UClass* Z_Construct_UClass_UKolizjaGowy_NoRegister();
// End Cross Module References
	void AMyCharacterMovement::StaticRegisterNativesAMyCharacterMovement()
	{
	}
	UClass* Z_Construct_UClass_AMyCharacterMovement_NoRegister()
	{
		return AMyCharacterMovement::StaticClass();
	}
	struct Z_Construct_UClass_AMyCharacterMovement_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_jumping_MetaData[];
#endif
		static void NewProp_jumping_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_jumping;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cam_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_cam;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_spring_arm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_spring_arm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_sprinting_MetaData[];
#endif
		static void NewProp_sprinting_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_sprinting;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_crouching_MetaData[];
#endif
		static void NewProp_crouching_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_crouching;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_firstPerson_MetaData[];
#endif
		static void NewProp_firstPerson_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_firstPerson;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_sunsword_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_sunsword;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_kolizja_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_kolizja;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyCharacterMovement_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Projekt3D,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyCharacterMovement.h" },
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_jumping_MetaData[] = {
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_jumping_SetBit(void* Obj)
	{
		((AMyCharacterMovement*)Obj)->jumping = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_jumping = { "jumping", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacterMovement), &Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_jumping_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_jumping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_jumping_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_cam_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_cam = { "cam", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacterMovement, cam), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_cam_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_cam_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_spring_arm_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_spring_arm = { "spring_arm", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacterMovement, spring_arm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_spring_arm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_spring_arm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_speed_MetaData[] = {
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacterMovement, speed), METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sprinting_MetaData[] = {
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sprinting_SetBit(void* Obj)
	{
		((AMyCharacterMovement*)Obj)->sprinting = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sprinting = { "sprinting", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacterMovement), &Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sprinting_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sprinting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sprinting_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_crouching_MetaData[] = {
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_crouching_SetBit(void* Obj)
	{
		((AMyCharacterMovement*)Obj)->crouching = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_crouching = { "crouching", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacterMovement), &Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_crouching_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_crouching_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_crouching_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_firstPerson_MetaData[] = {
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_firstPerson_SetBit(void* Obj)
	{
		((AMyCharacterMovement*)Obj)->firstPerson = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_firstPerson = { "firstPerson", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacterMovement), &Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_firstPerson_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_firstPerson_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_firstPerson_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sunsword_MetaData[] = {
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sunsword = { "sunsword", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacterMovement, sunsword), Z_Construct_UClass_ASunSword_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sunsword_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sunsword_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_kolizja_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyCharacterMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_kolizja = { "kolizja", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacterMovement, kolizja), Z_Construct_UClass_UKolizjaGowy_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_kolizja_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_kolizja_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyCharacterMovement_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_jumping,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_cam,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_spring_arm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sprinting,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_crouching,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_firstPerson,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_sunsword,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterMovement_Statics::NewProp_kolizja,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyCharacterMovement_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyCharacterMovement>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyCharacterMovement_Statics::ClassParams = {
		&AMyCharacterMovement::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyCharacterMovement_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyCharacterMovement_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterMovement_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyCharacterMovement()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyCharacterMovement_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyCharacterMovement, 2548743288);
	template<> PROJEKT3D_API UClass* StaticClass<AMyCharacterMovement>()
	{
		return AMyCharacterMovement::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyCharacterMovement(Z_Construct_UClass_AMyCharacterMovement, &AMyCharacterMovement::StaticClass, TEXT("/Script/Projekt3D"), TEXT("AMyCharacterMovement"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyCharacterMovement);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
