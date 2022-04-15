// Fill out your copyright notice in the Description page of Project Settings.


#include "FTTopDownController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/FTBaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "FTGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widget/HUD/PlayerHUDWidget.h"
#include "UI/Widget/HUD/ResourcesWidget.h"

AFTTopDownController::AFTTopDownController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AFTTopDownController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedBaseCharacter = Cast<AFTBaseCharacter>(InPawn);
	if (CachedBaseCharacter.IsValid() && IsLocalController())
	{
		CreateAndInitializeWidgets();
	}
}

void AFTTopDownController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}

	FHitResult TraceHitResult;
	GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
	CachedBaseCharacter->SetCursorHitResult(TraceHitResult);
}

void AFTTopDownController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AFTTopDownController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AFTTopDownController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AFTTopDownController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AFTTopDownController::MoveToTouchLocation);
}

void AFTTopDownController::MoveToMouseCursor()
{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
}

void AFTTopDownController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AFTTopDownController::SetNewMoveDestination(const FVector DestLocation)
{
	if (CachedBaseCharacter.IsValid() && IsLocalController())
	{
		float const Distance = FVector::Dist(DestLocation, CachedBaseCharacter->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}

}

void AFTTopDownController::OnSetDestinationPressed()
{
	bMoveToMouseCursor = true;
}

void AFTTopDownController::OnSetDestinationReleased()
{
	bMoveToMouseCursor = false;
}

void AFTTopDownController::CreateAndInitializeWidgets()
{
	if (!IsValid(PlayerHUDWidget))
	{
		PlayerHUDWidget = CreateWidget<UPlayerHUDWidget>(GetWorld(), PlayerHUDWidgetClass);

		if (IsValid(PlayerHUDWidget))
		{
			PlayerHUDWidget->AddToViewport();
		}
	}

	if (IsValid(PlayerHUDWidget))
	{
		UResourcesWidget* ResourcesWidget = PlayerHUDWidget->GetResourcesWidget();
		if (IsValid(ResourcesWidget))
		{
			CachedBaseCharacter->OnResourceCountChanged.AddUFunction(ResourcesWidget, FName("UpdateResourceCount"));
		}
	}
}
