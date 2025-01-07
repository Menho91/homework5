// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"


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
		FVector2D newpos = FVector2D(0.0, 0.0);
		newpos = newPosition + FVector2D(static_cast<double>(step()), static_cast<double>(step()));
		UE_LOG(LogTemp, Warning, TEXT("Current Position : ( %f, %f )"), newpos.X, newpos.Y);
		UE_LOG(LogTemp, Warning, TEXT("Moved Distance : %f"), distance(newPosition, newpos));
		newPosition = newpos;
		createEvent();
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %f"), distance(start, newPosition));
	UE_LOG(LogTemp, Warning, TEXT("Total Event Count : %d"), evCnt);
}

int32_t AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::distance(const FVector2D& first, const FVector2D& second)
{
	float dist = FMath::Sqrt(FMath::Pow((first.X - second.X), 2) + FMath::Pow((first.Y - second.Y), 2));
	return dist;
}

bool AMyActor::createEvent()
{
	if (step() % 2 == 1)
	{
		evCnt++;
		UE_LOG(LogTemp, Warning, TEXT("Event Occured!"));
		return true;
	}
	return false;
}