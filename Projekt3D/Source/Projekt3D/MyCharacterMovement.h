// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "KolizjaGowy.h"
#include "SunSword.h"
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
	// @@ Movement @@ //
	// Horizontal movement
	void HorizontalMove(float value);
	// Vertical movement
	void VerticalMove(float value);
	
	// Checks if player is jumping and change 'jumping' variable to opposite value
	void IsJumping();

	// Make character sprint
	void StartSprint();
	void StopSprint();
	
	// Crouching
	void ToggleCrouch();
	
	// @@ Camera  @@ //
	// Horizontal rotation
	void HorizontalRotation(float value);
	// Vertical rotation
	void VerticalRotation(float value);

	// Camera scrolling
	void CameraZoom(float value);
	// Camera swap (first person to third)
	void CameraSwap();


	// @@ Items @@ //
	void InsertItemInHand();
	void Laduj();

	UPROPERTY()
		bool jumping;

	UPROPERTY()
		UCameraComponent* cam;

	UPROPERTY()
		USpringArmComponent* spring_arm;

	UPROPERTY()
		float speed;
		
	UPROPERTY()
		bool sprinting;

	UPROPERTY()
		bool crouching;

	UPROPERTY()
		bool firstPerson;

	UPROPERTY()
		ASunSword* sunsword;
	
	bool toCrouch, toStand, canStand, wantsToStand, crouchingTogg, zaladowano;
	float wysokosc, promien;

	UPROPERTY()
		UKolizjaGowy* kolizja;
		
};