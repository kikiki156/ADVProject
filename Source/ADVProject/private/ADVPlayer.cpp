// Fill out your copyright notice in the Description page of Project Settings.


#include "ADVPlayer.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
AADVPlayer::AADVPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("SkeletalMesh'/Game/Characters/Erika_Archer.Erika_Archer'"));
	if (TempMesh.Succeeded()) {
		GetMesh()->SetSkeletalMesh(TempMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, 90), FRotator(0, -90, 0));
	}

	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	springArmComp->SetupAttachment(RootComponent);
	springArmComp->SetRelativeLocation(FVector(0, 70, 90));
	springArmComp->TargetArmLength = 400;
	springArmComp->bUsePawnControlRotation = true;

	tpsCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TpsCamComp"));
	tpsCamComp->SetupAttachment(springArmComp);
	tpsCamComp->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = true;
}

// Called when the game starts or when spawned
void AADVPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AADVPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	direction = FTransform(GetControlRotation()).TransformVector(direction);
	AddMovementInput(direction);
	direction = FVector::ZeroVector;
}

// Called to bind functionality to input
void AADVPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookVertical"), this, &AADVPlayer::LookVertical);
	PlayerInputComponent->BindAxis(TEXT("LookHorizontal"), this, &AADVPlayer::LookHorizontal);
	PlayerInputComponent->BindAxis(TEXT("MoveVertical"), this, &AADVPlayer::MoveVertical);
	PlayerInputComponent->BindAxis(TEXT("MoveHorizontal"), this, &AADVPlayer::MoveHorizontal);
}

void AADVPlayer::LookVertical(float value) {
	AddControllerPitchInput(value);
}
void AADVPlayer::LookHorizontal(float value) {
	AddControllerYawInput(value);
}
void AADVPlayer::MoveVertical(float value) {
	direction.X = value;
}
void AADVPlayer::MoveHorizontal(float value) {
	direction.Y = value;
}