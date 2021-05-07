// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "Obiekt_Core.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJEKT3D_API UObiekt_Core : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObiekt_Core();
	APlayerCameraManager *cameraManager;

	UPROPERTY(EditAnywhere,Category="Options")
	float FOVHide;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
