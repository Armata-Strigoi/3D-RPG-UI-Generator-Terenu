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
	waterMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("WaterMesh"));
	RootComponent = proceduralMesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	proceduralMesh->bUseAsyncCooking = true;
	

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialFinderWater(TEXT("/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean"));
	if(MaterialFinderWater.Object)
	{
		water = MaterialFinderWater.Object;
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialFinderGrass(TEXT("/Game/StarterContent/Materials/M_Ground_Grass"));
	if(MaterialFinderGrass.Object)
	{
		land = MaterialFinderGrass.Object;
	}else
	{
		UE_LOG(LogTemp, Error, TEXT("Blad wczytania materialu!"));
	}
}

// Called when the game starts or when spawned 
void AASDSDADSA::BeginPlay()
{
	Super::BeginPlay();
	BuildMap();
}

void AASDSDADSA::CreateWater(float level)
{
	TArray<FVector> waterVertices;
	TArray<FVector> waternNormals;
	TArray<int32> waterTriangles;
	TArray<FVector2D> waterUV;
	TArray<FLinearColor> waterVertexColors;
	TArray<FProcMeshTangent> waterTangents;

	waterVertices.Add(FVector(0, 0, level + WaterLevel * 10.0f));
	waterVertices.Add(FVector((SizeOfMap * SizeOfPlate), (SizeOfMap * SizeOfPlate), level + WaterLevel  * 10.0f));
	waterVertices.Add(FVector(0, (SizeOfMap * SizeOfPlate), level + WaterLevel  * 10.0f));
	waterVertices.Add(FVector((SizeOfMap * SizeOfPlate), 0, level + WaterLevel  * 10.0f));
	
	waternNormals.Add(FVector(0, 0, 1));
	waternNormals.Add(FVector(0, 0, 1));
	waternNormals.Add(FVector(0, 0, 1));
	waternNormals.Add(FVector(0, 0, 1));
	
	float uvSpace = 1.f / FMath::Max(this->SizeOfMap, this->SizeOfMap);
	waterUV.Add(FVector2D(0, 0));
	waterUV.Add(FVector2D((SizeOfMap * SizeOfPlate) * uvSpace, (SizeOfMap * SizeOfPlate) * uvSpace));
	waterUV.Add(FVector2D(0, (SizeOfMap * SizeOfPlate) * uvSpace));
	waterUV.Add(FVector2D((SizeOfMap * SizeOfPlate) * uvSpace, 0));
	
	waterTangents.Add(FProcMeshTangent(1, 0, 0));
	waterTangents.Add(FProcMeshTangent(1, 0, 0));
	waterTangents.Add(FProcMeshTangent(1, 0, 0));
	waterTangents.Add(FProcMeshTangent(1, 0, 0));
	
	waterVertexColors.Add(FLinearColor(0, 0, 0, 1.0));
	waterVertexColors.Add(FLinearColor(0, 0, 0, 1.0));
	waterVertexColors.Add(FLinearColor(0, 0, 0, 1.0));
	waterVertexColors.Add(FLinearColor(0, 0, 0, 1.0));
	
	waterTriangles.Add(0);
	waterTriangles.Add(1);
	waterTriangles.Add(3);

	waterTriangles.Add(1);
	waterTriangles.Add(0);
	waterTriangles.Add(2);
	
	waterMesh->CreateMeshSection_LinearColor(0, waterVertices, waterTriangles, waternNormals, waterUV, waterVertexColors, waterTangents, false);

	if(water)
	{
		waterMesh->SetMaterial(0,water);
	}
}

double AASDSDADSA::Noise2D(FVector2D pozycja)
{
	int n = pozycja.X + pozycja.Y * 57;
	n = (n<<13)^n;
	return 1.0 - ((n*(n*n*15731+789221)+1376312589) & 0x7fffffff)/1073741824.0;
}

double AASDSDADSA::CubicInterpolation(double v0, double v1,double v2, double v3,double x)
{
	double P = (v3 - v2) - (v0 - v1);
	double Q = (v0 - v1) - P;
	double R = v2 - v0;
	double S = v1;
	return P*pow(x,3)+Q*pow(x,2)+R*x+S;
}

double AASDSDADSA::InterpolatedNoise(FVector2D pozycja)
{
	int cx = (int)pozycja.X;
	int cy = (int)pozycja.Y;

	float fx = fmod(pozycja.X,1.0);
	float fy = fmod(pozycja.Y,1.0);

	double v[4][4] = {0};
	for(int IndexX = 0; IndexX < 4;IndexX++)
	{
		for(int IndexY = 0; IndexY < 4;IndexY++)
		{
			v[IndexX][IndexY] = Noise2D(FVector2D(cx - 1 + IndexX, cy - 1 + IndexY));
			//UE_LOG(LogTemp, Warning, TEXT("Noise2D %d %d: %lf"),IndexX,IndexY,v[IndexX][IndexY]);
		}
	}
	double vi[4] = {0};
	for(int IndexZ = 0; IndexZ < 4; IndexZ++)
	{
		vi[IndexZ] = CubicInterpolation(v[0][IndexZ],v[1][IndexZ],v[2][IndexZ],v[3][IndexZ],fx);
		//UE_LOG(LogTemp, Warning, TEXT("CubicInterpolation %d: %lf"),IndexZ,vi[IndexZ]);
	}
	return CubicInterpolation(vi[0],vi[1],vi[2],vi[3],fy);
}

double AASDSDADSA::PerlinNoise(FVector2D pozycja)
{
	double value = 0.0;
	for(int IndexO = 0; IndexO < this->Octaves; IndexO++)
	{
		double frequency = pow(this->Frequency, IndexO);
		double amplitude = pow(this->Persistence,IndexO);
		value += InterpolatedNoise(FVector2D(frequency * (double)pozycja.X/this->SizeOfMap,frequency * (double)pozycja.Y/this->SizeOfMap)) * amplitude;
		//UE_LOG(LogTemp, Warning, TEXT("InterpolatedNoise - Krokowe: %lf"),value);
	}
	//UE_LOG(LogTemp, Warning, TEXT("InterpolatedNoise - Koncowe: %lf"),value);
	return value;
}

void AASDSDADSA::BuildMap()
{
	FVector high = FVector(0,0,0);
	float uvSpace = 200.f / FMath::Max(this->SizeOfMap, this->SizeOfMap);
	int v = 0;
	float vertexOffset = SizeOfPlate * 0.5f;
	float incrementOffset = 0.0f;
	for(int32 IndexX = 0; IndexX <= this->SizeOfMap; IndexX++)
	{
		for(int32 IndexY = 0; IndexY <= this->SizeOfMap; IndexY++)
		{
			if(this->Scale){
				float heightMap = PerlinNoise(FVector2D(IndexX, IndexY)) * this->Multiplier;
				float scaledHeightMap = (((this->Max - this->Min) * (heightMap + 1))/2) + this->Min;
				if(scaledHeightMap < (this->Max + this->Min)/2.0f && this->Flat == true)
				{
					scaledHeightMap = ((this->Max + this->Min)/2.0f);
				}
				vertices.Add(FVector(IndexX * this->SizeOfPlate, IndexY * this->SizeOfPlate, scaledHeightMap + incrementOffset));
			}
			else
			{
				float heightMap = PerlinNoise(FVector2D(IndexX, IndexY)) * this->Multiplier * 100.0f;
				vertices.Add(FVector(IndexX * this->SizeOfPlate, IndexY * this->SizeOfPlate, heightMap + incrementOffset));
			}
			if(high.Z < vertices.Last().Z)
			{
				high = vertices.Last();
			}
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
	proceduralMesh->SetWorldLocation(FVector(0,0,proceduralMesh->GetComponentLocation().Z));
	if(this->Water)
	{
		CreateWater(proceduralMesh->GetComponentLocation().Z);
	}
	if(land)
	{
		proceduralMesh->SetMaterial(0,land);
	}
	high.Z += proceduralMesh->GetComponentLocation().Z;
	this->SetActorLocation(FVector(0,0,proceduralMesh->GetComponentLocation().Z));
	UNiagaraComponent* effect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			proceduralMesh, 
			NS,
			high, 
			FRotator(1),
			FVector(1),
			true, 
			true, 
			ENCPoolMethod::AutoRelease, 
			true);
	proceduralMesh->ContainsPhysicsTriMeshData(true);
}

// Called every frame
void AASDSDADSA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
