// Fill out your copyright notice in the Description page of Project Settings.


#include "AASDSDADSA.h"

// Sets default values
AAASDSDADSA::AAASDSDADSA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;
	
	proceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = proceduralMesh;
        // New in UE 4.17, multi-threaded PhysX cooking.
        proceduralMesh->bUseAsyncCooking = true;
}


void AAASDSDADSA::Test()
{
	TArray<FVector> vertices;
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, 10, 0));
	vertices.Add(FVector(0, 0, 10));
	
	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	
	TArray<FVector> normals;
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	
	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(1, 0));
	UV0.Add(FVector2D(0, 1));

	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	
	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	
	proceduralMesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);
	
	TArray<FVector2D> UV1;
	UV1.Add(FVector2D(0, 1));
	UV1.Add(FVector2D(1, 0));
	UV1.Add(FVector2D(1, 1));
	
	TArray<FVector> vertices2;
	vertices2.Add(FVector(0, 0, 10));
	vertices2.Add(FVector(0, 10, 0));
	vertices2.Add(FVector(0, 10, 10));
	
	
    proceduralMesh->CreateMeshSection_LinearColor(1, vertices2, Triangles, normals, UV1, vertexColors, tangents, true);
    
	// Enable collision data	
	proceduralMesh->ContainsPhysicsTriMeshData(true);
}


// Called when the game starts or when spawned 
void AAASDSDADSA::BeginPlay()
{
	Super::BeginPlay();
	Test();	
	
}

// Called every frame
void AAASDSDADSA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}