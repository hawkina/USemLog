// Copyright 2020, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/PoseableMeshComponent.h"
#include "SLVizMarker.generated.h"

/*
* Active visual type
*/
UENUM()
enum class ESLVizVisualType : uint8
{
	NONE			UMETA(DisplayName = "Box"),
	Static			UMETA(DisplayName = "Static"),
	Skeletal		UMETA(DisplayName = "Skeletal")
};

/*
* Marker primitive types
*/
UENUM()
enum class ESLVizMarkerType : uint8
{
	Box				UMETA(DisplayName = "Box"),
	Sphere			UMETA(DisplayName = "Sphere"),
	Cylinder		UMETA(DisplayName = "Cylinder"),
	Arrow			UMETA(DisplayName = "Arrow"),
	Axis			UMETA(DisplayName = "Axis"),
};

/**
 * Class capable of visualizing multiple types of markers as instanced static meshes
 */
UCLASS()
class USEMLOG_API USLVizMarker : public UInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Constructor
	USLVizMarker();

	// Set the visuals of the marker
	void Init(ESLVizMarkerType Type = ESLVizMarkerType::Box,
		const FVector& InScale = FVector(0.1),
		const FLinearColor& Color = FLinearColor::Green,
		bool bUnlit = false);

	// Set the visuals of the marker from the static mesh component with its original colors
	void Init(UStaticMeshComponent* SMC);

	// Set the visuals of the marker from the static mesh component with custom color
	void Init(UStaticMeshComponent* SMC, const FLinearColor& Color, bool bUnlit = false);

	// Set the visuals of the marker from the skeletal mesh component with its original colors
	void Init(USkeletalMeshComponent* SkMC);

	// Set the visuals of the marker from the skeletal mesh component with custom color
	void Init(USkeletalMeshComponent* SkMC, const FLinearColor& Color, bool bUnlit = false);

	// Set the visuals of the marker from the bone (material index) skeletal mesh component with its original colors
	void Init(USkeletalMeshComponent* SkMC, int32 MaterialIndex);

	// Set the visuals of the marker from the bone (material index) skeletal mesh component with custom color
	void Init(USkeletalMeshComponent* SkMC, int32 MaterialIndex, const FLinearColor& Color, bool bUnlit = false);

	// Set the visuals of the marker from the bone (material index) skeletal mesh component with its original colors
	void Init(USkeletalMeshComponent* SkMC, TArray<int32>& MaterialIndexes);

	// Set the visuals of the marker from the bone (material index) skeletal mesh component with custom color
	void Init(USkeletalMeshComponent* SkMC, TArray<int32>& MaterialIndexes, const FLinearColor& Color, bool bUnlit = false);

	// Add instances at location
	void Add(const FVector& Location);

	// Add instances at pose
	void Add(const FTransform& Pose);

	// Add instances with the locations
	void Add(const TArray<FVector>& Locations);
	
	// Add instances with the poses
	void Add(const TArray<FTransform>& Poses);

	// Add skeletal pose
	void Add(TPair<FTransform, TMap<FString, FTransform>>& SkeletalPose);

	// Add skeletal poses
	void Add(const TArray<TPair<FTransform, TMap<FString, FTransform>>>& SkeletalPoses);

	// Clear marker by notifing the parent manager
	bool DestroyThroughManager();

	//~ Begin ActorComponent Interface
	virtual void DestroyComponent(bool bPromoteChildren = false) override;
	//~ End ActorComponent Interface

protected:
	// Clear any previously set related data (mesh / materials)
	void Reset();

	// Create and register a new poseable mesh component
	UPoseableMeshComponent* CreateNewSkeletalInstance();

	// Load marker mesh and material assets
	void LoadAssets();

	// Get the marker static mesh from its type
	UStaticMesh* GetPrimitiveMarkerMesh(ESLVizMarkerType Type) const;

protected:
	// Scale of the visuals
	FVector Scale;

	// Enum showing the current active visual type
	ESLVizVisualType CurrentVisualType;

	/* Skeletal components */
	// Skeletal mesh marker to render
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkeletalMarker, meta = (AllowPrivateAccess = "true"))
	class USkeletalMesh* SkeletalMesh;

	// Skeletal materials
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkeletalMarker, meta = (AllowPrivateAccess = "true"))
	TMap<int32, class UMaterialInterface*> SkeletalMaterials;

	// Instances of the skeletal marker
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkeletalMarker, meta = (AllowPrivateAccess = "true"))
	TArray<UPoseableMeshComponent*> SkeletalInstances;
	
	/* Marker visual static meshes */
	UStaticMesh* MeshBox;	
	UStaticMesh* MeshSphere;
	UStaticMesh* MeshCylinder;
	UStaticMesh* MeshArrow;
	UStaticMesh* MeshAxis;

	/* Marker materials */
	UMaterial* MaterialLit;
	UMaterial* MaterialUnlit;
	UMaterial* MaterialInvisible;
};
