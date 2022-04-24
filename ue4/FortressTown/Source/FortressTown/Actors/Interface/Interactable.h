// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

class AFTTopDownController;
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class FORTRESSTOWN_API IInteractable
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE(FOnInteraction);

	virtual void Interact(AFTTopDownController* Controller) PURE_VIRTUAL(IInteractable::Interact, );
	virtual FName GetActionEventName() const PURE_VIRTUAL(IInteractable::GetActionEventName, return FName(NAME_None););
};
