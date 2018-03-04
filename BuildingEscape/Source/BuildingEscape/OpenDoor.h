// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	AActor * Owner;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = .5f;

	float LastDoorOpenTime;

	UPROPERTY(VisibleAnywhere)
	float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume * PressurePlate;

		AActor * ActorThatOpensDoor;
};
