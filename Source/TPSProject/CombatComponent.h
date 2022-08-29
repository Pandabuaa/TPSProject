// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"
#define TRACE_LENGTH 80000.F

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPSPROJECT_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();
	friend class ATPSProjectCharacter;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual  void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void EquipWeapon(class AWeapon* WeaponToEquip);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OnRep_EquippedWeapon();

	void FileButtonPressed(bool bPressed);
	UFUNCTION(Server,Reliable)
	void ServerFire();
	UFUNCTION(NetMulticast,Reliable)
	void MulticastFire();

	void TraceUnderCrosshairs(FHitResult& TraceHitResult);
private:
	class ATPSProjectCharacter* Character;
	class ATPSPlayerController* Controller;

	UPROPERTY(Replicated)
	class AWeapon* EquippedWeapon;

	bool bFireButtonPressed;

	FVector HitTarget;

public:	
	
		
};
