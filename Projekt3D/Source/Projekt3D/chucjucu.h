// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "chucjucu.generated.h"

/**
 * 
 */
UCLASS()
class PROJEKT3D_API Achucjucu : public AStaticMeshActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY()
		TArray<UStaticMeshComponent*> components;

	UPROPERTY()
		UStaticMeshComponent* mesh;



};
