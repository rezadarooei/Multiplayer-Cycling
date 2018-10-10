// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"




AMovingPlatform::AMovingPlatform()
{

	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location =GetActorLocation();
	float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
	float JourneyTravlled = (Location- GlobalStartLocation).Size();
	if (JourneyTravlled>=JourneyLength)
	{
		FVector Swap = GlobalStartLocation;
		GlobalStartLocation = GlobalTargetLocation;
		GlobalTargetLocation = Swap;
	}
	FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
	Location += 50*DeltaTime*Direction;
	SetActorLocation(Location);

}