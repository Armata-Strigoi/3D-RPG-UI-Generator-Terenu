// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "KolizjaGowy.generated.h"

/**
* 
*/
UCLASS()
class PROJEKT3D_API UKolizjaGowy : public UStaticMeshComponent
{
	GENERATED_BODY()
	public:
	UKolizjaGowy();
	
	bool sprawdz();

	private:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,  AActor* OtherActor,  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UPROPERTY()
	bool kolizja;

	
	
};
