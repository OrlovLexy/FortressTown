// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingHUDWidget.h"
#include "Components/TextBlock.h"

void UBuildingHUDWidget::SetActionText(FName ActionTextName)
{
	if (IsValid(ActionText))
	{
		ActionText->SetText(FText::FromName(ActionTextName));
	}
}

void UBuildingHUDWidget::SetActionTextVisibility(bool bIsVisible)
{
	if (bIsVisible)
	{
		ActionText->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		ActionText->SetVisibility(ESlateVisibility::Hidden);
	}
}
