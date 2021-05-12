// Fill out your copyright notice in the Description page of Project Settings.


#include "chucjucu.h"



// Called when the game starts
void Achucjucu::BeginPlay()
{
	Super::BeginPlay();
	
		
		
		if (!IsValidLowLevel())
		{
			UE_LOG(LogTemp,Warning,TEXT("Chuj1"));
			return;
		}
		if (!GetStaticMeshComponent()){
			UE_LOG(LogTemp,Warning,TEXT("Chuj2"));
			return;
		}
		if (!GetStaticMeshComponent()->GetStaticMesh()){
			UE_LOG(LogTemp,Warning,TEXT("Chuj3"));
			return;
		}
		if (!GetStaticMeshComponent()->GetStaticMesh()->RenderData){
			UE_LOG(LogTemp,Warning,TEXT("Chuj4"));
			return;
		}
		if (GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources.Num() > 0)
		{
			
			TArray<FVector> vertices = TArray<FVector>();
			FPositionVertexBuffer* chuj = &GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
			//FStaticMeshVertexBuffer* chujj = &GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.StaticMeshVertexBuffer;
			
			const int32 VertexCount = chuj->GetNumVertices();
			for (int32 Index = 0; Index < VertexCount; Index++)
			{
				const FVector WorldSpaceVertexLocation = GetActorLocation() + GetTransform().TransformVector(chuj->VertexPosition(Index));
				vertices.Add(WorldSpaceVertexLocation);
			}
			

			
			vertices.Add(FVector(0,0,0));
			vertices.Add(FVector(100,100,100));
			vertices.Add(FVector(-10,-10,-10));
			FPositionVertexBuffer chuj2;
			chuj2.Init(vertices);
			GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer = chuj2;
			
			//GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.StaticMeshVertexBuffer 
			
			UE_LOG(LogTemp,Warning,TEXT("%d"),chuj2.GetNumVertices());
			UE_LOG(LogTemp,Warning,TEXT("%d"),GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer.GetNumVertices());

			UE_LOG(LogTemp,Warning,TEXT("CHUCHUCJAUCSHDASUHDA"));
		}
	// ...
	
}