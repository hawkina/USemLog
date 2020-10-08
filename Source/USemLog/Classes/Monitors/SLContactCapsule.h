// Copyright 2017-2020, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "SLContactMonitorInterface.h"
#include "SLContactCapsule.generated.h"

/**
 * Collision area listening for semantic collision events
 */
UCLASS(ClassGroup = SL, meta = (BlueprintSpawnableComponent), hidecategories = (HLOD, Mobile, Cooking, Navigation, Physics), DisplayName = "SL Contact Capsule")
class USEMLOG_API USLContactCapsule : public UCapsuleComponent, public ISLContactMonitorInterface
{
	GENERATED_BODY()
public:
	// Default constructor
	USLContactCapsule();

	// Dtor
	~USLContactCapsule();

	/* Begin ISLContactMonitorInterface*/
	// Initialize trigger area for runtime, check if outer is valid and semantically annotated
	virtual void Init(bool bLogSupportedByEvents = true) override;

	// Start publishing overlap events, trigger currently overlapping objects
	virtual void Start() override;

#if WITH_EDITOR
	// Update bounds visual (red/green -- parent is not/is semantically annotated)
	// it is public so it can be accessed from the editor panel for updates
	virtual void UpdateVisualColor() override;
#endif // WITH_EDITOR
	/* End ISLContactMonitorInterface*/

protected:
	// Called at level startup
	virtual void BeginPlay() override;

	// Called when actor removed from game or game ended
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
private:
	// UObject interface
	// Called after the C++ constructor and after the properties have been initialized
	virtual void PostInitProperties() override;

	// Called when a property is changed in the editor
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	// End of UObject interface

	// USceneComponent interface
	// Called when this component is moved in the editor
	virtual void PostEditComponentMove(bool bFinished) override;
	// End of USceneComponent interface

	/* Begin ISLContactMonitorInterface*/
	// Load and apply cached parameters from tags
	virtual bool LoadShapeBounds() override;

	// Calculate and apply trigger area size
	virtual bool CalcShapeBounds() override;

	// Save current parameters to tags
	virtual bool StoreShapeBounds() override;
	/* End ISLContactMonitorInterface*/
#endif // WITH_EDITOR

#if WITH_EDITOR
private:
	// Box extent scale factor (smaller will be chosen)
	UPROPERTY(EditAnywhere, Category = "Semantic Logger")
	float CapsuleScaleFactor;

	// The box extent will be at least this big
	UPROPERTY(EditAnywhere, Category = "Semantic Logger")
	float CapsuleMinSize;

	// The box extent will be at most this big
	UPROPERTY(EditAnywhere, Category = "Semantic Logger")
	float CapsuleMaxSize;

	// Mimics a button
	UPROPERTY(EditAnywhere, Category = "Semantic Logger")
	bool bReCalcShapeButton;
#endif // WITH_EDITOR
};