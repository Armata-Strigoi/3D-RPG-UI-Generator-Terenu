// Fill out your copyright notice in the Description page of Project Settings.


#include "Obiekt_Core.h"


// Sets default values for this component's properties
UObiekt_Core::UObiekt_Core()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	hideAngle = 60;
	hideRotation = -999;
	hideSpeed = 0.05;
	// ...
	
}


// Called when the game starts
void UObiekt_Core::BeginPlay()
{
	Super::BeginPlay();
	cameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(),0);
	if(hideRotation == -999)
	{
		hideRotation = GetOwner()->GetActorRotation().Yaw;
	}
	hideAngle = hideAngle/2;
	problematic = (abs(hideRotation) > 180-hideAngle);
	GetOwner()->GetComponents<UStaticMeshComponent>(components);
	// ...
	
	//baseMaterial = UMaterialInstanceDynamic::Create(components[0]->GetMaterial(0), this);;
	//dynamicTranslucentMaterial = UMaterialInstanceDynamic::Create(translucentMaterial, this);//
	materialsNumber = components[0]->GetNumMaterials();
	UE_LOG(LogTemp,Warning,TEXT("Materialy: %d"),materialsNumber);
	if(materialsNumber != translucentMaterials.Num())
	{
		UE_LOG(LogTemp,Error,TEXT("Niezgodna liczba materiałow oraz materiałów przezroczystych dla obiektu!"));
	}

	for(int32 i = 0; i < materialsNumber; i++)
	{
		dynamicBaseMaterials.Add(UMaterialInstanceDynamic::Create(components[0]->GetMaterial(i), this));
		dynamicTranslucentMaterials.Add(UMaterialInstanceDynamic::Create(translucentMaterials[i], this));
		opacities.Add(1.f);
		translucencies.Add(false);
		acctuallyFullShown.Add(true);
	}
	//dynamicMaterial = UMaterialInstanceDynamic::Create(components[0]->GetMaterial(0), this);//
	//components[0]->SetMaterial(0,dynamicMaterial);
}


// Called every frame
void UObiekt_Core::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(cameraManager)
	{
		float cameraYaw = cameraManager->GetCameraRotation().Yaw;
		UE_LOG(LogTemp,Warning,TEXT("%f"),cameraYaw);
		for(int32 i = 0; i < materialsNumber; i++)
		{
			opacities[i] = dynamicTranslucentMaterials[i]->K2_GetScalarParameterValue("Opacity");
		}
		if(abs(cameraYaw - hideRotation) < hideAngle)
		{		
			for(int32 i=0; i<materialsNumber;i++)
			{
				//components[i]->SetVisibility(false);
				if(opacities[i] > 0)
				{
					if(!translucencies[i])
					{
						components[0]->SetMaterial(i,dynamicTranslucentMaterials[i]);
						translucencies[i] = true;
					}
					dynamicTranslucentMaterials[i]->SetScalarParameterValue("Opacity",opacities[i]-hideSpeed);
					//components[0]->SetMaterial(0,dynamicTranslucentMaterial);
					acctuallyFullShown[i] = false;
				}
			}
		}
		else if(problematic && abs(cameraYaw - hideRotation) > 360-hideAngle)
		{
			for(int32 i=0; i<materialsNumber;i++)
			{
				//components[i]->SetVisibility(false);
					if(opacities[i] > 0)
					{
						if(!translucencies[i])
						{
							components[0]->SetMaterial(i,dynamicTranslucentMaterials[i]);
							translucencies[i] = true;
						}
						dynamicTranslucentMaterials[i]->SetScalarParameterValue("Opacity",opacities[i]-hideSpeed);
						//components[0]->SetMaterial(0,dynamicTranslucentMaterial);
						acctuallyFullShown[i] = false;
					}
				/*
				if(components[i]->GetNumMaterials() > 0)
				{	
					if(dynamicMaterial != nullptr)
						dynamicMaterial->SetScalarParameterValue("Test", 0.5);
					dynamicMaterial->SetVectorParameterValue("Color",FColor(0,0,0,0));
					components[0]->SetMaterial(0, dynamicMaterial);
				}
				*/
			}
		}
		else
		{
			for(int32 i=0; i<materialsNumber;i++)
			{
				if(!acctuallyFullShown[i])
				{
					if(opacities[i] >= 1)
					{
						components[0]->SetMaterial(i,dynamicBaseMaterials[i]);
						acctuallyFullShown[i] = true;
						translucencies[i] = false;
					}
					dynamicTranslucentMaterials[i]->SetScalarParameterValue("Opacity",opacities[i]+(hideSpeed*2));
					//components[0]->SetMaterial(0,dynamicTranslucentMaterial);
				}
				//components[i]->SetVisibility(true);
			}
		}
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("Nie mam kamery!"));
	}
	
	// ...
}

