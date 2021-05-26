// Fill out your copyright notice in the Description page of Project Settings.
#include "AASDSDADSA.h"

// Sets default values
AASDSDADSA::AASDSDADSA()
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

void AASDSDADSA::Test()
{
	std::random_device random;
	std::mt19937 generator(random());
	std::uniform_real_distribution<> distance(-(this->Max + this->Min)/20.f, (this->Max + this->Min)/20.f);
	float uvSpace = 1.0f / FMath::Max(this->SizeOfMap, this->SizeOfMap);
	int v = 0;
	float vertexOffset = SizeOfPlate * 0.5f;
	float incrementOffset = 0.0f;
	for(int32 IndexX = 0; IndexX <= this->SizeOfMap; IndexX++)
	{
		for(int32 IndexY = 0; IndexY <= this->SizeOfMap; IndexY++)
		{
			float heightMap = 0;
			float frequency = this->Frequency;
			float amplitude = this->Multiplier;
			for(int32 IndexO = 0; IndexO < this->Octaves; IndexO++)
			{
				heightMap += FMath::PerlinNoise2D(FVector2D(IndexX * frequency, IndexY * frequency)) * amplitude;
				frequency *= 2.0f;
				amplitude *= this->Persistence;
			}
			float scaledHeightMap = (((this->Max - this->Min) * (heightMap + 1))/2) + this->Min;
			if(scaledHeightMap < (this->Max + this->Min)/2.0f) scaledHeightMap = ((this->Max + this->Min)/2.0f);
			//UE_LOG(LogTemp, Warning, TEXT("%lf"),scaledHeightMap );
			vertices.Add(FVector((IndexX * this->SizeOfPlate) - vertexOffset , (IndexY * this->SizeOfPlate) - vertexOffset, FMath::Pow(scaledHeightMap * 0.9f,this->Redistribution)));
			normals.Add(FVector(0, 0, 1));
			UV.Add(FVector2D(IndexX * uvSpace, IndexY * uvSpace));
			tangents.Add(FProcMeshTangent(1, 0, 0));
			vertexColors.Add(FLinearColor(0, 0, 0, 1.0));
			incrementOffset += this->Increment;
			v++;
		}
	}

	v=0;
	
	for(int32 IndexX = 0; IndexX < this->SizeOfMap; IndexX++)
	{
		for(int32 IndexY = 0; IndexY < this->SizeOfMap; IndexY++)
		{
			Triangles.Add(v);
			Triangles.Add(v + 1);
			Triangles.Add(v + (SizeOfMap + 1));

			Triangles.Add(v + (SizeOfMap + 1));
			Triangles.Add(v + 1);
			Triangles.Add(v + (SizeOfMap + 1) + 1);
			v++;
		}
		v++;
	}
	

	proceduralMesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV, vertexColors, tangents, true);

	// Enable collision data
	proceduralMesh->ContainsPhysicsTriMeshData(true);
}

// Called when the game starts or when spawned 
void AASDSDADSA::BeginPlay()
{
	Super::BeginPlay();
	Test();
}

// Called every frame
void AASDSDADSA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
