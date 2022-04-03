// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FortressTownTypes.h"
#include "FTGameInstance.generated.h"

UCLASS()
class FORTRESSTOWN_API UFTGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void SetResourceValue(EResourceType ResourceType, int Value);
	void AddResourceValue(EResourceType ResourceType, int Value);
	int GetResourceValue(EResourceType ResourceType);

private:
	TMap<EResourceType, int> Resources;
};
