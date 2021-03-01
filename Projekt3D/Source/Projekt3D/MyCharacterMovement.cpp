// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterMovement.h"

#include "Components/CapsuleComponent.h"

// Sets default values
AMyCharacterMovement::AMyCharacterMovement()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	cam->AttachTo(RootComponent);
	
	speed = 0.5f;
	sprinting = false;
	crouching = false;
	crouchingTogg = false;
	toCrouch = false;
	toStand = false;
	canStand = false;

	GetCapsuleComponent()->GetUnscaledCapsuleSize(promien,wysokosc);

	kolizja = CreateDefaultSubobject<UKolizjaGowy>(TEXT("KolizjaGowy"));
}

// Called when the game starts or when spawned
void AMyCharacterMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(jumping)
	{
		Jump();
	}

	if(wantsToStand)
	{
		canStand = !this->kolizja->sprawdz();
	}


	if(toCrouch)
		{
			float p,w;
			GetCapsuleComponent()->GetUnscaledCapsuleSize(p,w);
			if(w>wysokosc/2)
			{
				GetCapsuleComponent()->SetCapsuleSize(promien,w-4.f);
			}else{
				crouching = true;
				UE_LOG(LogTemp, Warning, TEXT("KUCAM"))
				toCrouch = false;
			}
	} else if(canStand && toStand)
	{
		float p,w;
		GetCapsuleComponent()->GetUnscaledCapsuleSize(p,w);
		if(w<wysokosc)
		{
			GetCapsuleComponent()->SetCapsuleSize(promien,w+4.f);
		}else
		{
			toStand = false;
			crouching = false;
			UE_LOG(LogTemp, Warning, TEXT("WSTALEM"))
			speed = 0.5f;
		}
	}
	
	
}

// Called to bind functionality to input
void AMyCharacterMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("HorizontalMovement",this,&AMyCharacterMovement::HorizontalMove);
	InputComponent->BindAxis("VerticalMovement",this,&AMyCharacterMovement::VerticalMove);
	InputComponent->BindAxis("HorizontalRotation",this,&AMyCharacterMovement::HorizontalRotation);
	InputComponent->BindAxis("VerticalRotation",this,&AMyCharacterMovement::VerticalRotation);

	InputComponent->BindAction("Jump",IE_Pressed,this,&AMyCharacterMovement::IsJumping);
	InputComponent->BindAction("Jump",IE_Released,this,&AMyCharacterMovement::IsJumping);

	InputComponent->BindAction("Sprint",IE_Pressed,this,&AMyCharacterMovement::StartSprint);
	InputComponent->BindAction("Sprint",IE_Released,this,&AMyCharacterMovement::StopSprint);

	InputComponent->BindAction("Crouch",IE_Pressed,this,&AMyCharacterMovement::ToggleCrouch);
	InputComponent->BindAction("Crouch",IE_Released,this,&AMyCharacterMovement::ToggleCrouch);
}

void AMyCharacterMovement::HorizontalMove(float value)
{
	if(value)
	{
		AddMovementInput(GetActorRightVector(),value*speed);
	}
}

void AMyCharacterMovement::VerticalMove(float value)
{
	if(value)
	{
		AddMovementInput(GetActorForwardVector(),value*speed);
	}
}

void AMyCharacterMovement::HorizontalRotation(float value)
{
	if(value)
	{
		AddActorLocalRotation(FRotator(0,value,0));
	}
}

void AMyCharacterMovement::VerticalRotation(float value)
{
	if(value)
	{
		float temp = cam->GetRelativeRotation().Pitch + value;
		if(temp > -80 && temp < 80){
			cam->AddLocalRotation(FRotator(value,0,0));
		}
	}
}


void AMyCharacterMovement::IsJumping()
{
	if(jumping)
	{
		jumping = false;
	} else
	{
		jumping = true;
	}
}

void AMyCharacterMovement::StartSprint()
{
	if(!crouching)
	{
		sprinting = true;
		speed = 1.0f;
	}
}

void AMyCharacterMovement::StopSprint()
{
	sprinting = false;;
	speed = 0.5f;
	
}
void AMyCharacterMovement::ToggleCrouch()
{
	crouchingTogg = !crouchingTogg;
	if(crouchingTogg)
	{
		speed = 0.1f;
		toStand = false;
		toCrouch = true;
		wantsToStand = false;
	}else
	{
		toCrouch = false;
		toStand = true;
		wantsToStand = true;
	}
}






