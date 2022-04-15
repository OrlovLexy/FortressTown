// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"
#include "Blueprint/WidgetTree.h"
#include "ResourcesWidget.h"

UResourcesWidget* UPlayerHUDWidget::GetResourcesWidget()
{
	return WidgetTree->FindWidget<UResourcesWidget>(ResourcesWidgetName);
}
