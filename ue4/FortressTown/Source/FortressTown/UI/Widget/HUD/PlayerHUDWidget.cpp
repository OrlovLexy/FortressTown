// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"
#include "Blueprint/WidgetTree.h"
#include "ResourcesWidget.h"
#include "BuildingHUDWidget.h"

UResourcesWidget* UPlayerHUDWidget::GetResourcesWidget()
{
	return WidgetTree->FindWidget<UResourcesWidget>(ResourcesWidgetName);
}

void UPlayerHUDWidget::SetBuildingHUDHelpVisibility(bool bIsVisible)
{
	if (IsValid(BuildingHUDWidget))
	{
		BuildingHUDWidget->SetActionTextVisibility(bIsVisible);
	}
}

void UPlayerHUDWidget::SetBuildingHUDActionText(FName ActionTextName)
{
	if (IsValid(BuildingHUDWidget))
	{
		BuildingHUDWidget->SetActionText(ActionTextName);
	}
}
