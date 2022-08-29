// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSHUD.h"

#include "CanvasItem.h"
#include "CharacterOverlay.h"

void ATPSHUD::BeginPlay()
{
	Super::BeginPlay();
    AddCharacterOverlay();

}

void ATPSHUD::AddCharacterOverlay()
{
    APlayerController* PlayerController = GetOwningPlayerController();
    if(PlayerController && CharacterOverlayClass)
    {
        CharacterOverlay = CreateWidget<UCharacterOverlay>(PlayerController, CharacterOverlayClass);
        CharacterOverlay->AddToViewport();
    }
}

void ATPSHUD::DrawHUD()
{
	Super::DrawHUD();
    if (CrosshairTexture)
    {
        // �ҳ����ǵĻ��������ĵ㡣
        FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

        // ƫ�������С��һ�룬�Ա����������뻭�����Ķ��롣
        FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f));

        // �����ĵ����ʮ��׼�ǡ�
        FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
        TileItem.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TileItem);
    }
}
