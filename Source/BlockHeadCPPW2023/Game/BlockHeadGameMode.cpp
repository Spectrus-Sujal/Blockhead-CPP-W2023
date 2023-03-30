// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockHeadGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "BlockHeadGameInstance.h"
#include "../GluttonTools.h"

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
	GetWorldTimerManager().SetTimer(LevelSwapTimer, this, &ABlockHeadGameMode::NextLevel, 2.0f);
}

void ABlockHeadGameMode::NextLevel()
{
	GameInstance->LoadNextLevel();
	GameCompleted(true);
}

void ABlockHeadGameMode::GameCompleted(bool PlayerWon)
{
	if(PlayerWon)
	{
		GLUTTON_LOG("Player Has Won");
	}
}
