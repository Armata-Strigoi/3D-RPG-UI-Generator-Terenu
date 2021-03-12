// Fill out your copyright notice in the Description page of Project Settings.


#include "Animacje.h"

#include "MyCharacterMovement.h"
#include "GameFramework/CharacterMovementComponent.h"

UAnimacje::UAnimacje()
{
	speed = 0;
	isInAir = false;
	zaladowano = false;
}

UAnimacje::~UAnimacje()
{
}

void UAnimacje::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(!zaladowano)
	{
		Laduj();
	}

	if (owningActor)
	{
		speed = owningActor->GetVelocity().Size();
		if(owningCharacter)
		{
			isInAir = owningCharacter->GetCharacterMovement()->IsFalling();
		}else UE_LOG(LogTemp, Fatal, TEXT("Zmienna owningCharacter zostala wyczyszczona!"));
	}else UE_LOG(LogTemp, Fatal, TEXT("Zmienna owningActor zostala wyczyszczona!"));
}

void UAnimacje::Laduj()
{
	owningActor = GetOwningActor();
	if(owningActor)
	{
		owningCharacter = Cast<AMyCharacterMovement>(owningActor);
	}else
	{
		UE_LOG(LogTemp, Error, TEXT("Blad w przypisywaniu aktora do animacji (Animacje.cpp :: Laduj())"))
	}
	zaladowano = true;
}
