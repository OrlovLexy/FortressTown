// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BuildingDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FBuildingLevelMesh
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMesh* StaticMesh;
};

enum class EBuildingLevel;

UCLASS()
class FORTRESSTOWN_API UBuildingDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EBuildingLevel, FBuildingLevelMesh> LevelMesh;
};
