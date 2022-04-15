// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingActor.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/FTBaseCharacter.h"


void ABuildingActor::BeginPlay()
{
	Super::BeginPlay();

	FTGameInstance = Cast<UFTGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	CachedBaseCharacter = Cast<AFTBaseCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if ((uint8)BuildingLevel < (uint8)EBuildingLevel::MAX - 1)
	{
		BuildingCost = GetLevelData(1)->BuildingCost;
		BuildingTime = GetLevelData(1)->BuildingTime;
	}
}

FBuildingSettingsRow* ABuildingActor::GetLevelData(int PlusLevel /*= 0*/)
{
	FName RowName = (FName)EnumToString(TEXT("EBuildingLevel"), (uint8)BuildingLevel + PlusLevel);
	static const FString ContextString(TEXT("Find Level Data"));
	if (RowName == TEXT("MAX"))
	{
		return nullptr;
	}
	return BuildingSettings->FindRow<FBuildingSettingsRow>(RowName, ContextString);
}

const FString ABuildingActor::EnumToString(const TCHAR* Enum, int32 EnumValue)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, Enum, true);
	if (!EnumPtr)
		return NSLOCTEXT("Invalid", "Invalid", "Invalid").ToString();


	return EnumPtr->GetNameStringByValue(EnumValue);
}
