// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "FortressTownTypes.h"
#include "FTGameInstance.h"
#include "Actors/Interface/Interactable.h"
#include "BuildingActor.generated.h"

USTRUCT(BlueprintType)
struct FBuildingSettingsRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BuildingCost = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BuildingTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Income = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int IncomeStorageMax = 3600;
};

UCLASS(Abstract, NotBlueprintable)
class FORTRESSTOWN_API ABuildingActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	virtual void Interact(AFTTopDownController* Controller) override;
	virtual FName GetActionEventName() const override;
	
protected:
	virtual void BeginPlay() override;

	virtual void InteractWithBuilding();

	FBuildingSettingsRow* GetLevelData(int PlusLevel = 0);

	const FString EnumToString(const TCHAR* Enum, int32 EnumValue);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building Settings")
	EBuildingLevel BuildingLevel = EBuildingLevel::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building Settings", meta = (RequiredAssetDataTags = "RowStructure=BuildingSettingsRow"))
	UDataTable* BuildingSettings;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building Settings")
	class UBuildingDataAsset* MeshSettings;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building Settings")
	FName ActionInteract = FName("Interact");

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int BuildingCost = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BuildingTime = 1.0f;

	UFTGameInstance* FTGameInstance;

	TSoftObjectPtr<class AFTBaseCharacter> CachedBaseCharacter;
};
