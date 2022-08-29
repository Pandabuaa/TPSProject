// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "TPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class TPSPROJECT_API ATPSHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	void AddCharacterOverlay();

public:
	virtual void DrawHUD() override;

	// 将被绘制在屏幕中心。
	UPROPERTY(EditDefaultsOnly)
		UTexture2D* CrosshairTexture;

	UPROPERTY(EditAnywhere,Category="Player States")
	TSubclassOf<class UUserWidget> CharacterOverlayClass;

	class UCharacterOverlay* CharacterOverlay;
	
};
