// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FTBaseCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnResourceCountChanged);

UCLASS()
class FORTRESSTOWN_API AFTBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFTBaseCharacter();

	FOnResourceCountChanged OnResourceCountChanged;

	virtual void Tick(float DeltaSeconds) override;

	class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }
	void SetCursorHitResult (FHitResult HitResult);
	

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	FHitResult CursorHitResult;
};
