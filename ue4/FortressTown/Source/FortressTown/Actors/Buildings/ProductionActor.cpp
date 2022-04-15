// Fill out your copyright notice in the Description page of Project Settings.


#include "ProductionActor.h"
#include "Characters/FTBaseCharacter.h"

AProductionActor::AProductionActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AProductionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IncomeStorage < IncomeStorageMax)
	{
		IncomeStorage += Income;
	}
}

void AProductionActor::CollectResources()
{
	if (IsValid(FTGameInstance) && IncomeStorage>0)
	{
		FTGameInstance->AddResourceValue(ResourceType, IncomeStorage);
		IncomeStorage = 0;
	}

	if (CachedBaseCharacter->OnResourceCountChanged.IsBound())
	{
		CachedBaseCharacter->OnResourceCountChanged.Broadcast();
	}
}

void AProductionActor::BeginPlay()
{
	Super::BeginPlay();

	Income = GetLevelData()->Income;
	IncomeStorageMax = GetLevelData()->IncomeStorageMax;
}
