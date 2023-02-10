// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();



}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* Actor = GetAccaptableActor();
	if (Actor != nullptr)
	{
		//bileþenin önceki bileþen olup olmadýðýný kontorl edecek
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr) {
			Component->SetSimulatePhysics(false);
		}
		Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		Move->SetShouldMove(true);
	}
	else
	{
		Move->SetShouldMove(false);
	}
	
}

void UTriggerComponent::SetMover(UMove* NewMove) {
	Move = NewMove;
}

AActor* UTriggerComponent::GetAccaptableActor() const {
	AActor* ReturnActor = nullptr;
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(TagName))
		{
			return Actor;
		}

	}

	return nullptr;

}