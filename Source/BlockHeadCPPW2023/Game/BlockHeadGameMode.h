// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BlockHeadGameMode.generated.h"

class UBlockHeadGameInstance;
/**
 * 
 */
UCLASS()
class BLOCKHEADCPPW2023_API ABlockHeadGameMode : public AGameModeBase {
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBlockHeadGameInstance* GameInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultLevelCompleteWidget;

	UPROPERTY()
	UUserWidget* LevelCompleteWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultGameCompleteWidget;

	UPROPERTY()
	UUserWidget* GameCompleteWidget;

	FTimerHandle LevelSwapTimer;

public:
	void TestMethod();

	void LevelCompleted();
	void NextLevel();
	void GameCompleted(bool PlayerWon);
};
