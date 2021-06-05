#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ProceduralMeshComponent.h"
#include "Niagara/Public/NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include <random>
#include "AASDSDADSA.generated.h"

UCLASS()
class PROJEKT3D_API AASDSDADSA : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AASDSDADSA();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
        UShapeComponent* Root;

    UFUNCTION()
        void BuildMap();

    UFUNCTION()
        void CreateWater(float level);

    UFUNCTION()
        double PerlinNoise(FVector2D pozycja);

    UFUNCTION()
        double InterpolatedNoise(FVector2D pozycja);

    UFUNCTION()
        double Noise2D(FVector2D pozycja);

    UFUNCTION()
        double CubicInterpolation(double v0, double v1,double v2, double v3,double x);\
    
    UPROPERTY()
        UProceduralMeshComponent* proceduralMesh;

    UPROPERTY()
        UProceduralMeshComponent* waterMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
        class UNiagaraSystem* NS;
    
    UPROPERTY(EditAnywhere)
        int SizeOfMap;

    UPROPERTY(EditAnywhere)
        float SizeOfPlate;

    UPROPERTY(EditAnywhere)
        float Multiplier;
    
	UPROPERTY(EditAnywhere)
		float Frequency;

    UPROPERTY(EditAnywhere)
        float Persistence;

    UPROPERTY(EditAnywhere)
        int Octaves;
    
    UPROPERTY(EditAnywhere)
        bool Scale;

    UPROPERTY(EditAnywhere)
        float Min;
    
    UPROPERTY(EditAnywhere)
        float Max;

    UPROPERTY(EditAnywhere)
        bool Flat;
    

    UPROPERTY(EditAnywhere)
        float Increment;

    UPROPERTY(EditAnywhere)
        bool Water;
    
    UPROPERTY(EditAnywhere)
        float WaterLevel;
        
    UMaterial* water;
    UMaterial* land;
	TArray<FVector> vertices;
    TArray<FVector> normals;
    TArray<int32> Triangles;
    TArray<FVector2D> UV;
    TArray<FLinearColor> vertexColors;
    TArray<FProcMeshTangent> tangents;

};