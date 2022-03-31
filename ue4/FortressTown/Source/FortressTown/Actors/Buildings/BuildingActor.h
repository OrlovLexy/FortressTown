// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "BuildingActor.generated.h"

UENUM(BlueprintType)
enum class EBuildingLevel : uint8
{
	None = 0,
	Basic,
	Advanced,
	Pro,
	MAX UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FBuildingSettingsRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BuildingCost = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BuildingTime = 1.0f;
};

UCLASS(Abstract, NotBlueprintable)
class FORTRESSTOWN_API ABuildingActor : public AActor
{
	GENERATED_BODY()
	
public:	

protected:
	virtual void BeginPlay() override;

	void UpdateNextLevelData();

	const FString EnumToString(const TCHAR* Enum, int32 EnumValue);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building Settings")
	EBuildingLevel BuildingLevel = EBuildingLevel::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building Settings", meta = (RequiredAssetDataTags = "RowStructure=BuildingSettingsRow"))
	UDataTable* BuildingSettings;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building Settings")
	class UBuildingDataAsset* MeshSettings;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BuildingCost = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BuildingTime = 1.0f;
};
