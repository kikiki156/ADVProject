// Fill out your copyright notice in the Description page of Project Settings.


#include "GuildNPC.h"
#include "GameFramework/PlayerController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGuildNPC::AGuildNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	
	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("SkeletalMesh'/Game/Characters/Medea/Medea.Medea'"));
	ConstructorHelpers::FObjectFinder<UAnimSequence> anim(TEXT("AnimSequence'/Game/Animations/NPC_Standing/Talking_Anim_mixamo_com.Talking_Anim_mixamo_com'"));

	Anim = anim.Object;

	if (TempMesh.Succeeded()) {
		Mesh->SetSkeletalMesh(TempMesh.Object);
	}

	AutoReceiveInput = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AGuildNPC::BeginPlay()
{
	Super::BeginPlay();
	Mesh->PlayAnimation(Anim, false);
	Mesh->SetPlayRate(0.0f);
	//Mesh->SetPosition(Anim, 0.0f, true);
	/*UE_LOG(LogTemp, Warning, TEXT("NPC Interacted!"));
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		PlayerController->InputComponent->BindAction("Interact", IE_Pressed, this, &AGuildNPC::Interact);
	}*/
	
}

// Called every frame
void AGuildNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGuildNPC::Interact()
{
	// Implement interaction logic here
	//UE_LOG(LogTemp, Warning, TEXT("NPC Interacted!"));
}