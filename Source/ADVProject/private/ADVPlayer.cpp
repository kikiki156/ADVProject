// Fill out your copyright notice in the Description page of Project Settings.


#include "ADVPlayer.h"

// Sets default values
AADVPlayer::AADVPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("SkeletalMesh'/Game/Characters/Erika_Archer.Erika_Archer'"));
	if (TempMesh.Succeeded()) {
		GetMesh()->SetSkeletalMesh(TempMesh.Object);
	}
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

}

// Called to bind functionality to input
void AADVPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

