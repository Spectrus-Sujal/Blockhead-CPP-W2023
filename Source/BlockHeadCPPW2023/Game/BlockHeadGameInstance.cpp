// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockHeadGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../GluttonTools.h"

void UBlockHeadGameInstance::LoadNextLevel()
{
	if (CurrentLevel > Levels.Num())
	{
		GLUTTON_LOG(PRINTF("No more levels to load. Current Level: %d", CurrentLevel));
		return;
	}
	// GameplayStatics Header (Include at top)
	// UGameplayStatics::OpenLevelBYSoftObjectPtr()

	UGameplayStatics::OpenLevelBySoftObjectPtr(this, Levels[CurrentLevel - 1]);
	CurrentLevel++;
}

bool UBlockHeadGameInstance::IsPlayerOnFinalLevel() const
{
	return CurrentLevel == Levels.Num() + 1;
}

void UBlockHeadGameInstance::SetInputMode(bool GameOnly) const
{
	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	if (GameOnly)
	{
		const FInputModeGameOnly InputMode;
		Controller->SetInputMode(InputMode);
	}
	else
	{
		const FInputModeUIOnly InputMode;
		Controller->SetInputMode(InputMode);
	}

	Controller->bShowMouseCursor = !GameOnly;
	
}

void UBlockHeadGameInstance::LoadFirstLevel()
{
	CurrentLevel = 1;
	LoadNextLevel();
}
