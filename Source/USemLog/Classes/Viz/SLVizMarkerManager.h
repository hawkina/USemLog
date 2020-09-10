// Copyright 2020, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Viz/Marker/SLVizPrimitiveMarker.h"
#include "Viz/Marker/SLVizStaticMeshMarker.h"
#include "Viz/Marker/SLVizSkeletalMeshMarker.h"
#include "SLVizMarkerManager.generated.h"


/*
* Spawns and keeps track of markers
* (AActor since AInfo & components seems not to be rendered during runtime)
*/
UCLASS(ClassGroup = (SL), DisplayName = "SL Viz Marker Manager")
class USEMLOG_API ASLVizMarkerManager : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ASLVizMarkerManager();

protected:
	// Called when actor removed from game or game ended
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Clear marker
	void ClearMarker(USLVizBaseMarker* Marker);
	
	// Clear all markers
	void ClearAllMarkers();

	// Create a static mesh visual marker at the given pose
	USLVizStaticMeshMarker* CreateStaticMeshMarker(const FTransform& Pose,
		UStaticMesh* SM,
		const FLinearColor& InColor = FLinearColor::Green,
		ESLVizMarkerMaterialType MaterialType = ESLVizMarkerMaterialType::Unlit);

	// Create a static mesh visual marker at the given poses
	USLVizStaticMeshMarker* CreateStaticMeshMarker(const TArray<FTransform>& Poses,
		UStaticMesh* SM,
		const FLinearColor& InColor = FLinearColor::Green,
		ESLVizMarkerMaterialType MaterialType = ESLVizMarkerMaterialType::Unlit);

	// Create a primitive marker at the given pose
	USLVizPrimitiveMarker* CreatePrimitiveMarker(const FTransform& Pose,
		ESLVizPrimitiveMarkerType PrimitiveType = ESLVizPrimitiveMarkerType::Box,
		float Size = .1f,
		const FLinearColor& InColor = FLinearColor::Green,
		ESLVizMarkerMaterialType MaterialType = ESLVizMarkerMaterialType::Unlit);

	// Create a primitive marker at the given poses
	USLVizPrimitiveMarker* CreatePrimitiveMarker(const TArray<FTransform>& Poses,
		ESLVizPrimitiveMarkerType PrimitiveType = ESLVizPrimitiveMarkerType::Box,
		float Size = .1f,
		const FLinearColor& InColor = FLinearColor::Green,
		ESLVizMarkerMaterialType MaterialType = ESLVizMarkerMaterialType::Unlit);

	// Create a skeletal mesh based marker at the given pose
	USLVizSkeletalMeshMarker* CreateSkeletalMarker(const FTransform& Pose,
		USkeletalMesh* SkelMesh,
		const TArray<int32>& MaterialIndexes = TArray<int32>(),
		const TMap<int32, FTransform>& BonePoses = TMap<int32, FTransform>(),
		const FLinearColor& InColor = FLinearColor::Green,
		ESLVizMarkerMaterialType MaterialType = ESLVizMarkerMaterialType::Unlit);

	// Create a skeletal mesh based marker at the given pose
	USLVizSkeletalMeshMarker* CreateSkeletaleMarker(const TArray<FTransform>& Poses,
		USkeletalMesh* SkelMesh,
		const TArray<int32>& MaterialIndexes = TArray<int32>(),
		const TArray<TMap<int32, FTransform>>& BonePosesArray = TArray<TMap<int32, FTransform>>(),
		const FLinearColor& InColor = FLinearColor::Green,
		ESLVizMarkerMaterialType MaterialType = ESLVizMarkerMaterialType::Unlit);

private:
	// Create markers helper function
	template <class T>
	T* CreateAndAddNewMarker()
	{
		T* Marker = NewObject<T>(this);
		Marker->RegisterComponent();
		//Marker->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
		// Removed because they are causing the components to remain in the actors components when changing maps
		//AddInstanceComponent(Marker); // Makes it appear in the editor
		//AddOwnedComponent(Marker);
		Markers.Add(Marker);
	}

protected:
	// Collection of the markers
	UPROPERTY(VisibleAnywhere, Transient, Category = "Semantic Logger")
	TSet<USLVizBaseMarker*> Markers;
};
