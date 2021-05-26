#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ProceduralMeshComponent.h"
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
        void Test();

    UPROPERTY()
        UProceduralMeshComponent* proceduralMesh;

    UPROPERTY(EditAnywhere)
        int SizeOfMap;

    UPROPERTY(EditAnywhere)
        float SizeOfPlate;

	UPROPERTY(EditAnywhere)
		FVector MapOffset;

	UPROPERTY(EditAnywhere)
		float Frequency;

	UPROPERTY(EditAnywhere)
		float Multiplier;

    UPROPERTY(EditAnywhere)
        float Increment;

    UPROPERTY(EditAnywhere)
        float Min;
    
    UPROPERTY(EditAnywhere)
        float Max;

    UPROPERTY(EditAnywhere)
        int Octaves;

    UPROPERTY(EditAnywhere)
        float Persistence;

    UPROPERTY(EditAnywhere)
        float Redistribution;
    
	TArray<FVector> vertices;
    TArray<FVector> normals;
    TArray<int32> Triangles;
    TArray<FVector2D> UV;
    TArray<FLinearColor> vertexColors;
    TArray<FProcMeshTangent> tangents;
};