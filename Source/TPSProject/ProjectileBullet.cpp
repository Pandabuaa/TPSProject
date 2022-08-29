// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBullet.h"
#include "GameFramework/Character.h"
void AProjectileBullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActer, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	ACharacter* OwnerCharacer = Cast<ACharacter>(GetOwner());
	if (OwnerCharacer)
	{
		AController* OwnerController = OwnerCharacer->Controller;
		
	}
	Super::OnHit(HitComp, OtherActer, OtherComp, NormalImpulse, Hit);

}
