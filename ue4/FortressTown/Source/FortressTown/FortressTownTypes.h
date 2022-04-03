#pragma once

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	Gold,
	Ore,
	Iron,
	Harvest,
	Food
};

UENUM(BlueprintType)
enum class EBuildingLevel : uint8
{
	None = 0,
	Basic,
	Advanced,
	Pro,
	MAX UMETA(Hidden)
};