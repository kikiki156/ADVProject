// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "ADVPlayer.h"
#include <GameFramework/CharacterMovementComponent.h>

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto ownerPawn = TryGetPawnOwner();
	auto player = Cast<AADVPlayer>(ownerPawn);

	if (player) {
		FVector velocity = player->GetVelocity();

		FVector forwardVector = player->GetActorForwardVector();
		verticalSpeed = FVector::DotProduct(forwardVector, velocity);

		FVector rightVector = player->GetActorRightVector();
		horizontalSpeed = FVector::DotProduct(rightVector, velocity);

		auto movement = player->GetCharacterMovement();
		isInAir = movement->IsFalling();

		if (player->bArmed) 
			isEquip = true;
		else
			isEquip = false;

		if (player->bBowAim)
			isAiming = true;
		else 
			isAiming = false;
		
	}
}
