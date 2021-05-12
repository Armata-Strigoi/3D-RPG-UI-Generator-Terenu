// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachTo(RootComponent);
	position = this->GetActorLocation();
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	position = this->GetActorLocation();
	UNiagaraComponent* effect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
    		GetWorld(), 
    		NS,
    		position, // Get your position here
    		FRotator(1),
    		FVector(1),
    		true, 
    		true, 
    		ENCPoolMethod::AutoRelease, 
    		true);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

