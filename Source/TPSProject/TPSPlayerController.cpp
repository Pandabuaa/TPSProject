// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayerController.h"
#include "TPSHUD.h"
#include "CharacterOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


void ATPSPlayerController::SetHUDHealth(float Health, float MaxHealth)
{
	TPSHUD = (TPSHUD == nullptr) ? Cast<ATPSHUD>(GetHUD()) : TPSHUD;
	if(TPSHUD && TPSHUD->CharacterOverlay && TPSHUD->CharacterOverlay->HealthBar && TPSHUD->CharacterOverlay->HealthText)
	{
		const float HealthPercent = Health / MaxHealth;
		TPSHUD->CharacterOverlay->HealthBar->SetPercent(HealthPercent);
		FString HealthText = FString::Printf(TEXT("%d/%d"), FMath::CeilToInt(Health), FMath::CeilToInt(MaxHealth));
		TPSHUD->CharacterOverlay->HealthText->SetText(FText::FromString(HealthText));
	}
}

void ATPSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	TPSHUD = Cast<ATPSHUD>(GetHUD());
}
