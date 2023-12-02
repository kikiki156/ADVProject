// Fill out your copyright notice in the Description page of Project Settings.


#include "RayTrace.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
URayTrace::URayTrace()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void URayTrace::BeginPlay()
{
	Super::BeginPlay();

	
	
}



// Called every frame
void URayTrace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

