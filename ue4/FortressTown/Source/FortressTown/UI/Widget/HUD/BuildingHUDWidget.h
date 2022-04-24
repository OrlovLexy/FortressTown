// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildingHUDWidget.generated.h"

class UTextBlock;
UCLASS()
class FORTRESSTOWN_API UBuildingHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetActionText(FName ActionTextName);
	void SetActionTextVisibility(bool bIsVisible);

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ActionText;
};
