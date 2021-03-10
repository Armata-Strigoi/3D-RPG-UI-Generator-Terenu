// Fill out your copyright notice in the Description page of Project Settings.


#include "Animacje.h"

#include "MyCharacterMovement.h"
#include "GameFramework/CharacterMovementComponent.h"

UAnimacje::UAnimacje()
{
	speed = 0;
	isInAir = false;
}

UAnimacje::~UAnimacje()
{
}

void UAnimacje::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	AActor* owningActor = GetOwningActor(); // To chyba mozna wrzucic do konstrutora i przypisac do zmiennej zamiast w kazdym ticku to robic
	if (owningActor)
	{
		speed = owningActor->GetVelocity().Size();
		AMyCharacterMovement* owningCharacter = Cast<AMyCharacterMovement>(owningActor); // To chyba też
		if(owningCharacter)
		{
			isInAir = owningCharacter->GetCharacterMovement()->IsFalling();
		}
	}
}
