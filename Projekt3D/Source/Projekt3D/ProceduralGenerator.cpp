// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralGenerator.h"

// Sets default values for this component's properties
UProceduralGenerator::UProceduralGenerator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProceduralGenerator::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->GetComponents<UStaticMeshComponent>(components);
	if(components.Num() > 0)
	{
		FPositionVertexBuffer* chuj = &components[0]->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
		
		const int32 VertexCount = chuj->GetNumVertices();
		for (int32 Index = 0; Index < VertexCount; Index++)
		{
			//const FVector WorldSpaceVertexLocation = GetActorLocation() + GetTransform().TransformVector(chuj->VertexPosition(Index));
			//vertices.Add(WorldSpaceVertexLocation);
		}
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("Nie ma static mesha!"));
	}
	// ...
	
}


// Called every frame
void UProceduralGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

