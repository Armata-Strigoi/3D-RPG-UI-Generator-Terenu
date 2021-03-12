// Fill out your copyright notice in the Description page of Project Settings.


#include "SunSword.h"

// Sets default values
ASunSword::ASunSword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH SUN SWORDA"));
	mesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BaseMeshAsset(TEXT("/Game/Meshes/TestSunSworda.TestSunSworda"));

	if(BaseMeshAsset.Object)
	{
		mesh->SetStaticMesh(BaseMeshAsset.Object);
	}else
	{
		UE_LOG(LogTemp, Error, TEXT("Blad wczytania sunsworda!"));
	}
}

// Called when the game starts or when spawned
void ASunSword::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASunSword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

