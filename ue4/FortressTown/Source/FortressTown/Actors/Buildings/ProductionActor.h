// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Buildings/BuildingActor.h"
#include "ProductionActor.generated.h"

UCLASS(Blueprintable)
class FORTRESSTOWN_API AProductionActor : public ABuildingActor
{
	GENERATED_BODY()
	
public:
	AProductionActor();

	virtual void Tick(float DeltaTime) override;

	void CollectResources();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Production Settings")
	EResourceType ResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Production Settings", meta = (ClampMin = 1, UIMin = 1))
	int Income = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Production Settings")
	int IncomeStorage = 0;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Production Settings", meta = (ClampMin = 1, UIMin = 1))
	int IncomeStorageMax = 3600;
};
