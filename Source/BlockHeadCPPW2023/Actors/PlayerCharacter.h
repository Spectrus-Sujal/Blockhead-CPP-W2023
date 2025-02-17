// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

// Forward Declarations:
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class ABlockHeadGameMode;
class UBlockHeadGameInstance;

UCLASS()
class BLOCKHEADCPPW2023_API APlayerCharacter : public APawn {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlayerDied();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// ENHANCED INPUT SYSTEM

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	void MoveRightLeft(const FInputActionValue& Value);

	// ASSET COMPONENTS

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Setup)
	UStaticMeshComponent* Cube;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Setup)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Setup)
	UCameraComponent* Camera;

	// MOVEMENT VARIABLES
	UPROPERTY(EditAnywhere, Category = "Movement")
	float ForwardForce = 1800.0f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float SideForce = 1800.0f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float KillZThreshold = -300.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bLevelEnded = false;

	UFUNCTION() // Required to bind to dynamic multi-cast delegate.
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	           FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION() // The names of these functions don't matter, but the signature does.
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ABlockHeadGameMode* GameMode;

	FTimerHandle GameEndTimer;
};
