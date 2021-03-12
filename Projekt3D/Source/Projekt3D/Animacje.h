// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MyCharacterMovement.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Animacje.generated.h"
 
/**
 * 
 */
UCLASS(Transient,Blueprintable,HideCategories=AnimInstance, BlueprintType)
class UAnimacje: public UAnimInstance
{
	GENERATED_BODY()
public:
	UAnimacje();
	~UAnimacje();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Generic")
		float speed;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Generic")
		bool isInAir;

	UPROPERTY()
		AActor* owningActor;

	UPROPERTY()
		AMyCharacterMovement* owningCharacter;

	UPROPERTY()
		bool zaladowano;
	
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


	// Funkcja sluzaca do zaladowanaia zmiennych ktorych nie mozna zaladowac w konstruktorze
	void Laduj();
};
