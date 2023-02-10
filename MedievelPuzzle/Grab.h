// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grab.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDIEVELPUZZLE_API UGrab : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrab();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void Grab();

	UFUNCTION(BlueprintCallable)
		void Release();



private:
	UPROPERTY(EditAnywhere)
		float MaxGrabDistance = 400;

	UPROPERTY(EditAnywhere)
		float GrabRadius = 100;

	UPROPERTY(EditAnywhere)
		float HoldDistance = 100;

	bool GetGrabbableInReach(FHitResult& OutHitResult) const;
	
};
