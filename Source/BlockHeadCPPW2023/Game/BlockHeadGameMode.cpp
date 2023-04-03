// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockHeadGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "BlockHeadGameInstance.h"
#include "Components/TextBlock.h"
#include "../GluttonTools.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

void ABlockHeadGameMode::BeginPlay() {
	Super::BeginPlay();

	GameInstance = CastChecked<UBlockHeadGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	GameInstance->SetInputMode(true);
	
}

void ABlockHeadGameMode::TestMethod() {
	GLUTTON_LOG("In Game Mode.");
}

void ABlockHeadGameMode::LevelCompleted()
{
	if(DefaultLevelCompleteWidget != nullptr)
	{
		LevelCompleteWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultLevelCompleteWidget);

		if(LevelCompleteWidget)
		{
			LevelCompleteWidget->AddToViewport();
		}
	}
	else
	{
		GLUTTON_LOG("Level COmplete is Null");
	}
	GetWorldTimerManager().SetTimer(LevelSwapTimer, this, &ABlockHeadGameMode::NextLevel, 2.0f);
}

void ABlockHeadGameMode::NextLevel()
{
	if(GameInstance->IsPlayerOnFinalLevel())
	{
		LevelCompleteWidget->RemoveFromParent();
		GameCompleted(true);
	}else
	{
		GameInstance->LoadNextLevel();
	}
}

void ABlockHeadGameMode::GameCompleted(bool PlayerWon)
{
	GameInstance->SetInputMode(false);
			
	if(DefaultGameCompleteWidget != nullptr)
	{
		GameCompleteWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultGameCompleteWidget);

		if(GameCompleteWidget)
		{
			GameCompleteWidget->AddToViewport();
			UTextBlock* LostOrComplete = Cast<UTextBlock>(
				GameCompleteWidget->GetWidgetFromName(FName{"LostOrComplete"}));
			const FText WinLossMessage = PlayerWon ? FText::FromString("You Won!") : FText::FromString("You Lost!");
			LostOrComplete->SetText(WinLossMessage);
		}
	}
	else
	{
		GLUTTON_LOG("Game Complete is Null");
	}
}
