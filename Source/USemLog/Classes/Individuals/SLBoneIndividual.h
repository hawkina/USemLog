// Copyright 2017-2020, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Individuals/SLPerceivableIndividual.h"
#include "SLBoneIndividual.generated.h"

// Forward declaration
class USkeletalMeshComponent;
class USLSkeletalDataComponent;

/**
 *
 */
UCLASS(ClassGroup = SL)
class USEMLOG_API USLBoneIndividual : public USLPerceivableIndividual
{
    GENERATED_BODY()

    // TODO see if this makes sense for setting the class, ids etc.
    //// Only the owning skeletal individual should be able to change values
    //friend class USLSkeletalIndividal;

public:
    // Ctor
    USLBoneIndividual();

    // Called before destroying the object.
    virtual void BeginDestroy() override;

    // Set the parameters required when initalizing the individual (should be called right after construction by the skeletal individual)
    bool PreInit(int32 NewBoneIndex, int32 NewMaterialIndex, bool bReset = false);

    // Check if the individual is pre initalized 
    bool IsPreInit() const { return bIsPreInit; };

    // Init asset references (bForced forces re-initialization)
    virtual bool Init(bool bReset);

    // Load semantic data (bForced forces re-loading)
    virtual bool Load(bool bReset, bool bTryImport);

    // Get the type name as string
    virtual FString GetTypeName() const override { return FString("BoneIndividual"); };

    /* Begin Perceivable individual interface */
    // Apply visual mask material
    virtual bool ApplyMaskMaterials(bool bIncludeChildren = false) override;

    // Apply original materials
    virtual bool ApplyOriginalMaterials() override;
    /* End Perceivable individual interface */

    // Calculate the current bone transform
    bool CacheCurrentBoneTransform();

    // Get the cached bone transform
    FTransform GetCachedTransform() const { return CachedTransform; };

    // Get the attachment location name (bone/socket)
    FName GetAttachmentLocationName();

protected:
    // Get class name, virtual since each invidiual type will have different name
    virtual FString CalcDefaultClassValue() override;

    // Set pointer to parent actor
    virtual bool SetParentActor() override;

private:
    // Set dependencies
    bool InitImpl();

    // Set data
    bool LoadImpl(bool bTryImport);

    // Clear all values of the individual
    void InitReset();

    // Clear all data of the individual
    void LoadReset();

    // Check if the bone index is valid
    bool HasValidBoneIndex() const;

    // Check if the static mesh component is set
    bool HasValidSkeletalMesh() const;

    // Set sekeletal mesh
    bool SetSkeletalMesh();

    // Check if the material index is valid
    bool HasValidMaterialIndex() const;

protected:
    // Pre init
    UPROPERTY(VisibleAnywhere, Category = "SL")
    bool bIsPreInit;

    // Mask material index
    UPROPERTY(VisibleAnywhere, Category = "SL")
    int32 MaterialIndex;

    // Bone index
    UPROPERTY(VisibleAnywhere, Category = "SL")
    int32 BoneIndex;

    // Parent skeletal mesh
    UPROPERTY()
    USkeletalMeshComponent* SkeletalMeshComponent;

    // Cached transform
    FTransform CachedTransform;
};