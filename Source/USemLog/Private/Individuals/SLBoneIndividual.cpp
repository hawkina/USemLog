// Copyright 2017-2020, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "Individuals/SLBoneIndividual.h"
#include "Individuals/SLSkeletalIndividual.h"
#include "Skeletal/SLSkeletalDataComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Ctor
USLBoneIndividual::USLBoneIndividual()
{
	MaterialIndex = INDEX_NONE;
	BoneIndex = INDEX_NONE;
	bIsPreInit = false;
}

// Called before destroying the object.
void USLBoneIndividual::BeginDestroy()
{
	SetIsInit(false);
	Super::BeginDestroy();
}

// Set the parameters required when initalizing the individual
bool USLBoneIndividual::PreInit(int32 NewBoneIndex, int32 NewMaterialIndex, bool bReset)
{
	if (bReset)
	{
		bIsPreInit = false;
	}

	if (IsPreInit())
	{
		return true;
	}

	BoneIndex = NewBoneIndex;
	MaterialIndex = NewMaterialIndex;
	TagType += "Bone" + FString::FromInt(BoneIndex);
	bIsPreInit = true;
	return true;
}

// Set pointer to the semantic owner
bool USLBoneIndividual::Init(bool bReset)
{
	if (bReset)
	{
		InitReset();
	}

	if (IsInit())
	{
		return true;
	}

	SetIsInit(Super::Init(bReset) && InitImpl());
	return IsInit();
}

// Load semantic data
bool USLBoneIndividual::Load(bool bReset, bool bTryImport)
{
	if (bReset)
	{
		LoadReset();
	}

	if (IsLoaded())
	{
		return true;
	}

	if (!IsInit())
	{
		if (!Init(bReset))
		{
			UE_LOG(LogTemp, Log, TEXT("%s::%d Cannot load  individual %s, init fails.."),
				*FString(__FUNCTION__), __LINE__, *GetFullName());
			return false;
		}
	}

	SetIsLoaded(Super::Load(bReset, bTryImport) && LoadImpl(bTryImport));
	return IsLoaded();
}

// Apply visual mask material
bool USLBoneIndividual::ApplyMaskMaterials(bool bIncludeChildren /*= false*/)
{
	if (!IsInit())
	{
		return false;
	}

	if (!bIsMaskMaterialOn)
	{
		SkeletalMeshComponent->SetMaterial(MaterialIndex, VisualMaskDynamicMaterial);
		bIsMaskMaterialOn = true;
		return true;
	}
	return false;
}

// Apply original materials
bool USLBoneIndividual::ApplyOriginalMaterials()
{
	if (!IsInit())
	{
		return false;
	}

	// Bones share the same original materials with the skeletal parent, this will only set the flag value
	if (bIsMaskMaterialOn)
	{
		// Applied in parent
		bIsMaskMaterialOn = false;
		return true;
	}
	return false;
}

// Calculate current bone transform
bool USLBoneIndividual::CacheCurrentBoneTransform()
{
	if (IsInit())
	{
		CachedTransform = SkeletalMeshComponent->GetBoneTransform(BoneIndex);
		return true;
	}
	return false;
}

// Get the attachment location name (bone/socket)
FName USLBoneIndividual::GetAttachmentLocationName()
{
	if (HasValidSkeletalMesh() && HasValidBoneIndex())
	{
		return SkeletalMeshComponent->GetBoneName(BoneIndex);
	}
	return NAME_None;
}

// Get class name, virtual since each invidiual type will have different name
FString USLBoneIndividual::CalcDefaultClassValue()
{
	if (IsInit())
	{
		if (USLSkeletalIndividual* SkI = Cast<USLSkeletalIndividual>(GetOuter()))
		{
			if (SkI->HasValidSkeletalDataAsset())
			{
				if (FString* BoneClassValue = SkI->SkeletalDataAsset->BoneIndexClass.Find(BoneIndex))
				{
					if (!BoneClassValue->IsEmpty())
					{
						return *BoneClassValue;
					}
				}
			}
		}
	}
	return GetTypeName();
}

// Set the skeletal actor as parent
bool USLBoneIndividual::SetParentActor()
{
	if (USLSkeletalIndividual* SkI = Cast<USLSkeletalIndividual>(GetOuter()))
	{
		if (UActorComponent* AC = Cast<UActorComponent>(SkI->GetOuter()))
		{
			if (AActor* CompOwner = Cast<AActor>(AC->GetOuter()))
			{
				ParentActor = CompOwner;
				return true;
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("%s::%d %s's third outer should be the parent actor.."),
					*FString(__FUNCTION__), __LINE__, *GetFullName());
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("%s::%d %s's second outer should be an actor component.."),
				*FString(__FUNCTION__), __LINE__, *GetFullName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s::%d %s's outer should be a skeletal individual.."),
			*FString(__FUNCTION__), __LINE__, *GetFullName());
	}
	return false;
}

// Private init implementation
bool USLBoneIndividual::InitImpl()
{
	if (!IsPreInit())
	{
		UE_LOG(LogTemp, Log, TEXT("%s::%d Cannot init individual %s, pre init need to be called right after creation.."),
			*FString(__FUNCTION__), __LINE__, *GetFullName());
		return false;
	}

	// Make sure the visual mesh is set
	if (HasValidSkeletalMesh() || SetSkeletalMesh())
	{
		if (HasValidMaterialIndex())
		{
			return true;
		}
		// TODO set parent and child bone individual
	}
	return false;
}

// Private load implementation
bool USLBoneIndividual::LoadImpl(bool bTryImport)
{
	return true;
}

// Clear all values of the individual
void USLBoneIndividual::InitReset()
{
	LoadReset();
	SetIsInit(false);
}

// Clear all data of the individual
void USLBoneIndividual::LoadReset()
{
	SetIsLoaded(false);
}

// Check if the bone index is valid
bool USLBoneIndividual::HasValidBoneIndex() const
{
	return HasValidSkeletalMesh()
		&& BoneIndex != INDEX_NONE
		&& BoneIndex < SkeletalMeshComponent->GetNumBones();
}

// Check if the material index is valid
bool USLBoneIndividual::HasValidMaterialIndex() const
{
	return HasValidSkeletalMesh()
		&& MaterialIndex != INDEX_NONE
		&& MaterialIndex < SkeletalMeshComponent->GetNumMaterials();
}

// Check if the static mesh component is set
bool USLBoneIndividual::HasValidSkeletalMesh() const
{
	return SkeletalMeshComponent && SkeletalMeshComponent->IsValidLowLevel() && !SkeletalMeshComponent->IsPendingKill();
}

// Set sekeletal mesh
bool USLBoneIndividual::SetSkeletalMesh()
{
	// Outer should be the skeletal individual
	if (USLSkeletalIndividual* SkI = Cast<USLSkeletalIndividual>(GetOuter()))
	{
		if (SkI->HasValidSkeletalMeshComponent())
		{
			SkeletalMeshComponent = SkI->SkeletalMeshComponent;
			return true;
		}
	}
	return false;
}