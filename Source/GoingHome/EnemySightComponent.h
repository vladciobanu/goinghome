// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "EnemySightComponent.generated.h"

/**
 * EnemySightComponent creates a trigger box in front of it and 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GOINGHOME_API UEnemySightComponent : public USceneComponent
{
	GENERATED_BODY()


public:	
	//~=============================================================================
	// Constructors and overrides.

	/** Default constructor. */
	UEnemySightComponent(const FObjectInitializer& ObjectInitializer);

	/** Called when the game starts. */
	virtual void BeginPlay() override;
	
	/** Called every frame. */
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


	//~=============================================================================
	// Properties
	
	/** Size of the box thing. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SightProperties")
	float SightRange;

	/** BoxComponent used for collision detection. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ZDontChangeMe")
	class UBoxComponent* SightCollisionComponent;
	

	//~=============================================================================
	// Private
private:

	/** Enemy Pawn casted to the appropriate class. */
	class AEnemyPawn* EnemyPawn;

	/** Enemy Controller casted to the appropriate class. */
	class AEnemyAIController* EnemyController;

	/** Player Pawn, not casted but still here for easy access. */
	class APawn* PlayerPawn;

	/** 
	 * Only if we're overlapping with the Box do we check for the angle and fire the 
	 * overlap event to the controller. 
	 */
	bool isOverlapping;

	/** For some reason this callback has to be a UFUNCTION. Called when the BoxComponent overlaps with something. */
	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult & SweepResult);

	/** For some reason this callback has to be a UFUNCTION. Called when the BoxComponent ends the overlap with something. */
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
