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

int UFTGameInstance::GetResourceValue(EResourceType ResourceType)
{
	return Resources[ResourceType];
}
