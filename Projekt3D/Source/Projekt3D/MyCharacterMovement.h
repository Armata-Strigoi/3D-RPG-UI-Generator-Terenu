// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "KolizjaGowy.h"
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
	// Horizontal movement
	void HorizontalMove(float value);

	// Vertical movement
	void VerticalMove(float value);

	// Horizontal rotation
	void HorizontalRotation(float value);

	// Vertical rotation
	void VerticalRotation(float value);

	// Checks if player is jumping and change 'jumping' variable to opposite value
	void IsJumping();

	// Make character sprint
	void StartSprint();
	void StopSprint();
	
	// Crouching
	void ToggleCrouch();

	UPROPERTY()
		bool jumping;

	UPROPERTY()
		UCameraComponent* cam;

	UPROPERTY()
		float speed;
	UPROPERTY()
		bool sprinting;

	UPROPERTY()
		bool crouching;

	bool toCrouch, toStand, canStand, wantsToStand, crouchingTogg;
	float wysokosc, promien;

	UPROPERTY()
		UKolizjaGowy* kolizja;
};
