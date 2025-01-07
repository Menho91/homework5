// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HOMEWORK_API AMyActor : public AActor
{
	GENERATED_BODY()
	FVector2D start;
	FVector2D newPosition;
	int32 evCnt;
	int totDist;

public:	
	// Sets default values for this actor's properties
	AMyActor() : start(FVector2D(0.0, 0.0)), newPosition(FVector2D(0.0, 0.0)), evCnt(0), totDist(0)
	{
		PrimaryActorTick.bCanEverTick = true;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void move();
	int32_t step();
	float distance(const FVector2D& first, const FVector2D& second);
	bool createEvent();
};
