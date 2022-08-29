// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "ProjectileBullet.generated.h"

/**
 * 
 */
UCLASS()
class TPSPROJECT_API AProjectileBullet : public AProjectile
{
	GENERATED_BODY()
		virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActer, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
};
