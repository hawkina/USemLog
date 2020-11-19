// Copyright 2017-2020, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SLCVQScene.generated.h"

// Forward declaration
class ASLKnowrobManager;

/**
 * Base class for viz queries
 */
UCLASS()
class USLCVQScene : public UDataAsset
{
	GENERATED_BODY()

public:
	// Public execute function
	void Execute(ASLKnowrobManager* KRManager);

	// Get the scene name
	FString GetSceneName() const { return "DefaultSceneName"; };

protected:
#if WITH_EDITOR
	// Execute function called from the editor, references need to be set manually
	void ManualExecute();

	// Called when a property is changed in the editor
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	// Check if the references are set for calling the execute function from the editor
	bool IsReadyForManualExecution() const;
#endif // WITH_EDITOR

	// Execute batch command if any
	void ExecuteChildren(ASLKnowrobManager* KRManager);

	// Virtual implementation of the execute function
	virtual void ExecuteImpl(ASLKnowrobManager* KRManager);

protected:
	/* Children to be called in a batch */
	UPROPERTY(EditAnywhere, Category = "Children")
	TArray<USLCVQScene*> Children;

	UPROPERTY(EditAnywhere, Category = "Children")
	bool bExecuteChildrenFirst = false;


	/* Manual interaction */
	UPROPERTY(EditAnywhere, Category = "Manual Interaction")
	TSoftObjectPtr<ASLKnowrobManager> KnowrobManager = nullptr;

	UPROPERTY(EditAnywhere, Category = "Manual Interaction")
	bool bManualExecuteButton = false;


	/* Base properties */
	UPROPERTY(EditAnywhere, Category = "VizQ")
	FString Description;

	UPROPERTY(EditAnywhere, Category = "VizQ")
	bool bIgnore;
};