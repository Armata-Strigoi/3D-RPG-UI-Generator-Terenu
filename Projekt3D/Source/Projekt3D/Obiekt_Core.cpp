// Fill out your copyright notice in the Description page of Project Settings.


#include "Obiekt_Core.h"

// Sets default values for this component's properties
UObiekt_Core::UObiekt_Core()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	FOVHide = 60;
	// ...
}


// Called when the game starts
void UObiekt_Core::BeginPlay()
{
	Super::BeginPlay();
	cameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(),0);
	// ...
	
}


// Called every frame
void UObiekt_Core::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(cameraManager)
	{
		float cameraYaw = cameraManager->GetCameraRotation().Yaw;
		UE_LOG(LogTemp,Warning,TEXT("%f"),cameraYaw);
		float actorYaw = GetOwner()->GetActorRotation().Yaw;
		TArray<UStaticMeshComponent*> components;
		GetOwner()->GetComponents<UStaticMeshComponent>(components);
		if(abs(cameraYaw - actorYaw) < FOVHide) // Do ogarniecia warunek
		{		
			for(int32 i=0; i<components.Num();i++)
			{
				components[i]->SetVisibility(false);
			}
		}else
		{
			for(int32 i=0; i<components.Num();i++)
			{
				components[i]->SetVisibility(true);
			}
		}
		
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("Nie mam kamery!"));
	}
	
	// ...
}

