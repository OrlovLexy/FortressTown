// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingActor.h"


void ABuildingActor::BeginPlay()
{
	Super::BeginPlay();

	UpdateNextLevelData();	
}

void ABuildingActor::UpdateNextLevelData()
{
	FName RowName = (FName)EnumToString(TEXT("EBuildingLevel"), (uint8)BuildingLevel + 1);
	static const FString ContextString(TEXT("Find Level Data"));
	if (RowName == TEXT("MAX"))
	{
		return;
	}

	BuildingCost = BuildingSettings->FindRow<FBuildingSettingsRow>(RowName, ContextString)->BuildingCost;
	BuildingTime = BuildingSettings->FindRow<FBuildingSettingsRow>(RowName, ContextString)->BuildingTime;
}

const FString ABuildingActor::EnumToString(const TCHAR* Enum, int32 EnumValue)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, Enum, true);
	if (!EnumPtr)
		return NSLOCTEXT("Invalid", "Invalid", "Invalid").ToString();


	return EnumPtr->GetNameStringByValue(EnumValue);
}
