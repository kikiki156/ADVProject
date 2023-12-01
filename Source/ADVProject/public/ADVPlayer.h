// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ADVPlayer.generated.h"


UCLASS()
class ADVPROJECT_API AADVPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AADVPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, Category=Camera)
	class USpringArmComponent* springArmComp;
	UPROPERTY(VisibleAnywhere, Category=Camera)
	class UCameraComponent* tpsCamComp;

	void LookVertical(float value);
	void LookHorizontal(float value);

	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float walkSpeed = 200;
	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float runSpeed = 600;

	FVector direction;

	void MoveVertical(float value);
	void MoveHorizontal(float value);

	void InputJump();

	void InputRun();

	void InputEquip();

	bool bArmed = false;

	UPROPERTY(VisibleAnywhere, Category=BowMesh)
	class USkeletalMeshComponent* unarmedBowMeshComp;

	UPROPERTY(VisibleAnywhere, Category = BowMesh)
	class USkeletalMeshComponent* armedBowMeshComp;

	UPROPERTY(EditDefaultsOnly, Category=ArrowFactory)
	TSubclassOf<class AArrow> arrowFactory;

	void InputShoot();
	void InputAim();

	bool bBowAim = false;
};
