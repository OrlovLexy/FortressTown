// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUDWidget.generated.h"

UCLASS()
class FORTRESSTOWN_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	class UResourcesWidget* GetResourcesWidget();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WidgetNames")
	FName ResourcesWidgetName;
};
