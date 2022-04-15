// Fill out your copyright notice in the Description page of Project Settings.


#include "FTGameInstance.h"

void UFTGameInstance::SetResourceValue(EResourceType ResourceType, int Value)
{
	Resources.Add(ResourceType, Value);
}

void UFTGameInstance::AddResourceValue(EResourceType ResourceType, int Value)
{
	Resources[ResourceType] += Value;
}
const int& UFTGameInstance::GetResourceValue(EResourceType ResourceType)
{
	return Resources[ResourceType];
}

const TMap<EResourceType, int>& UFTGameInstance::GetResorcesValue()
{
	return Resources;
}
