// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "MaterialCompiler.h"
#include "SceneTypes.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Obiekt_Core.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJEKT3D_API UObiekt_Core : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObiekt_Core();
	UPROPERTY()
	APlayerCameraManager *cameraManager;

	UPROPERTY(EditAnywhere,Category="Options")
	float hideAngle;
	
	UPROPERTY(EditAnywhere,Category="Options")
	float hideRotation;

	UPROPERTY(EditAnywhere,Category="Options")
	float hideSpeed;
	
	UPROPERTY()
	bool problematic;

	UPROPERTY()
	bool acctuallyFullShown;

	UPROPERTY()
	float opacity;

	UPROPERTY()
	bool translucent;

	UPROPERTY()
	UMaterialInstanceDynamic* baseMaterial;
	
	UPROPERTY()
	UMaterialInstanceDynamic* dynamicTranslucentMaterial;
	
	UPROPERTY(EditAnywhere,Category="Materials")
	UMaterial* translucentMaterial;

	UPROPERTY()
	TArray<UStaticMeshComponent*> components;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
