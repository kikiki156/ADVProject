// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"
#include <Components/CapsuleComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
// Sets default values
AArrow::AArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	colliComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComp"));
	colliComp->SetCollisionProfileName(TEXT("BlockAll"));
	RootComponent = colliComp;

	bodyComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMeshComp"));
	bodyComp->SetupAttachment(colliComp);
	bodyComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	bodyComp->SetRelativeScale3D(FVector(0.25f));

	movementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComp"));
	movementComp->SetUpdatedComponent(colliComp);

	movementComp->InitialSpeed = 0;
	movementComp->MaxSpeed = 5000;
	movementComp->bShouldBounce = false;
	

}

// Called when the game starts or when spawned
void AArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

