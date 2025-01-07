// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move()
{
	for (int i = 0; i < 10; i++)
	{
		start += { static_cast<double>(step()), static_cast<double>(step()) };
		UE_LOG(LogTemp, Warning, TEXT("Current Position : ( %f, %f )"), start.X, start.Y);
	}
} 

int32_t AMyActor::step()
{
	return FMath::RandRange(0, 1);
}