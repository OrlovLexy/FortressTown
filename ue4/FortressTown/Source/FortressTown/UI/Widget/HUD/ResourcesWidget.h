// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortressTownTypes.h"
#include "ResourcesWidget.generated.h"

UCLASS()
class FORTRESSTOWN_API UResourcesWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	int GoldValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	int OreValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	int IronValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	int HarvestValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	int FoodValue = 0;

private:
	UFUNCTION()
	void UpdateResourcesCount(TMap<EResourceType, int> NewResources);

	UFUNCTION()
	void UpdateResourceCount();
};
