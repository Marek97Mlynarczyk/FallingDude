// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move platform forward
		//Get current location
	FVector CurrentLocation = GetActorLocation();
		//Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVel * DeltaTime);	
		//Set the location
	SetActorLocation(CurrentLocation);

	//Move platform backward if moved too far
		//Check how far it moved
	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);	
		//Reverse direction
	if (DistanceMoved > MoveDistance)
	{
		FVector MoveDirection = PlatformVel.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVel =- PlatformVel;
	}
}
