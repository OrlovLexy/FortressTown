// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ScriptInterface.h"
#include "FTTopDownController.generated.h"

class IInteractable;
UCLASS()
class FORTRESSTOWN_API AFTTopDownController : public APlayerController
{
	GENERATED_BODY()

public:
	AFTTopDownController();
	virtual void SetPawn(APawn* InPawn) override;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UPlayerHUDWidget> PlayerHUDWidgetClass;

	UPROPERTY()
	TScriptInterface<IInteractable> DestinationObject;

	uint32 bMoveToMouseCursor : 1;

	virtual void PlayerTick(float DeltaTime) override;

	virtual void SetupInputComponent() override;

	void MoveToMouseCursor();

	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	void SetNewMoveDestination(const FVector DestLocation);

	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	void Interact();
	void InteractOnTouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location);

	void SetDestinationObject(FHitResult& HitResult);

private:
	void CreateAndInitializeWidgets();

	TSoftObjectPtr<class AFTBaseCharacter> CachedBaseCharacter;

	UPlayerHUDWidget* PlayerHUDWidget = nullptr;
};
