// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "MyCharacterMovement.generated.h"


UCLASS()
class PROJEKT3D_API AMyCharacterMovement : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterMovement();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void HorizontalMove(float value);
	void VerticalMove(float value);
	void HorizontalRotation(float value);
	void VerticalRotation(float value);
	void IsJumping();

	UPROPERTY()
		bool jumping;

	UPROPERTY();
		UCameraComponent* cam;
};
