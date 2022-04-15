// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourcesWidget.h"
#include "Kismet/GameplayStatics.h"
#include "FTGameInstance.h"

void UResourcesWidget::UpdateResourcesCount(TMap<EResourceType, int> NewResources)
{
	GoldValue = NewResources[EResourceType::Gold];
	OreValue = NewResources[EResourceType::Ore];
	IronValue = NewResources[EResourceType::Iron];
	HarvestValue = NewResources[EResourceType::Harvest];
	FoodValue = NewResources[EResourceType::Food];
}

void UResourcesWidget::UpdateResourceCount()
{
	UFTGameInstance* FTGameInstance = Cast<UFTGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	UpdateResourcesCount(FTGameInstance->GetResorcesValue());
}
