// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUDWidget.generated.h"

class UBuildingHUDWidget;
UCLASS()
class FORTRESSTOWN_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	class UResourcesWidget* GetResourcesWidget();

	void SetBuildingHUDHelpVisibility(bool bIsVisible);
	void SetBuildingHUDActionText(FName ActionTextName);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WidgetNames")
	FName ResourcesWidgetName;

	UPROPERTY(meta = (BindWidget))
	UBuildingHUDWidget* BuildingHUDWidget;
};
