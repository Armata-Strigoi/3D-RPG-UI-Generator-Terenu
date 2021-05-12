// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralGenerator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJEKT3D_API UProceduralGenerator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProceduralGenerator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY()
		TArray<UStaticMeshComponent*> components;

	UPROPERTY()
		UStaticMeshComponent* mesh;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
