// Copyright 2019, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "SLMetadataLogger.h"
#include "SLEntitiesManager.h"
#include "Conversions.h"
#include "Tags.h"
#include "Components/SkeletalMeshComponent.h"

// Ctor
USLMetadataLogger::USLMetadataLogger()
{
	bIsInit = false;
	bIsStarted = false;
	bIsFinished = false;
}

// Dtor
USLMetadataLogger::~USLMetadataLogger()
{
	if (!bIsFinished && !IsTemplate())
	{
		Finish(true);
	}

	// Disconnect and clean db connection
	Disconnect();
}

// Init logger
void USLMetadataLogger::Init(const FString& InLocation, const FString InEpisodeId, const FString InServerIp, uint16 InServerPort,
		 UWorld* World, bool bScanItems, bool bOverwrite)
{
	if (!bIsInit)
	{
		if(!Connect(InLocation, InServerIp, InServerPort, bOverwrite))
		{
			return;
		}

		// Create the bson metadata document
		CreateDoc();

		if(bScanItems)
		{
			ItemsScanner = NewObject<USLItemScanner>(this);
			ItemsScanner->Init(World);
		}

		bIsInit = true;
	}
}

// Start logger
void USLMetadataLogger::Start(const FString& InTaskDescription)
{
	if (!bIsStarted && bIsInit)
	{
		// Add data to the document
		AddTaskDescription(InTaskDescription);
		AddEnvironmentData();
		AddCameraViews();

		// Scan items and include the data in the document
		if(ItemsScanner)
		{
			ItemsScanner->Start();
		}
		
		bIsStarted = true;
	}
}

// Finish logger
void USLMetadataLogger::Finish(bool bForced)
{
	if (!bIsFinished && (bIsInit || bIsStarted))
	{
		InsertDoc();

		if(ItemsScanner)
		{
			ItemsScanner->Finish();
		}
		
		bIsStarted = false;
		bIsInit = false;
		bIsFinished = true;
	}
}

// Connect to the database
bool USLMetadataLogger::Connect(const FString& DBName, const FString& ServerIp, uint16 ServerPort, bool bOverwrite)
{
	const FString MetaCollName = DBName + ".meta";
	
#if SL_WITH_LIBMONGO_C
	// Required to initialize libmongoc's internals	
	mongoc_init();

	// Stores any error that might appear during the connection
	bson_error_t error;

	// Safely create a MongoDB URI object from the given string
	FString Uri = TEXT("mongodb://") + ServerIp + TEXT(":") + FString::FromInt(ServerPort);
	uri = mongoc_uri_new_with_error(TCHAR_TO_UTF8(*Uri), &error);
	if (!uri)
	{
		UE_LOG(LogTemp, Error, TEXT("%s::%d Err.:%s; [Uri=%s]"),
			*FString(__func__), __LINE__, *FString(error.message), *Uri);
		return false;
	}

	// Create a new client instance
	client = mongoc_client_new_from_uri(uri);
	if (!client)
	{
		return false;
	}

	// Register the application name so we can track it in the profile logs on the server
	mongoc_client_set_appname(client, TCHAR_TO_UTF8(*("SL_" + MetaCollName)));
	
	// Get a handle on the database "db_name" and collection "coll_name"
	database = mongoc_client_get_database(client, TCHAR_TO_UTF8(*DBName));

	// Give a warning if the collection already exists or not
	if (mongoc_database_has_collection(database, TCHAR_TO_UTF8(*MetaCollName), &error))
	{
		if(bOverwrite)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s::%d Meta collection %s already exists, will be removed and overwritten.."),
				*FString(__func__), __LINE__, *MetaCollName);
			if(!mongoc_collection_drop (mongoc_database_get_collection(database, TCHAR_TO_UTF8(*MetaCollName)), &error))
			{
				UE_LOG(LogTemp, Error, TEXT("%s::%d Could not drop collection, err.:%s;"),
					*FString(__func__), __LINE__, *FString(error.message));
				return false;
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s::%d Meta collection %s already exists and should not be overwritten, skipping metadata logging.."),
				*FString(__func__), __LINE__, *MetaCollName);
			return false;
		}
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("%s::%d Meta collection %s does not exist, creating a new one.."),
			*FString(__func__), __LINE__, *MetaCollName);
	}

	collection = mongoc_database_get_collection(database, TCHAR_TO_UTF8(*MetaCollName));

	// Double check that the server is alive. Ping the "admin" database
	bson_t* server_ping_cmd;
	server_ping_cmd = BCON_NEW("ping", BCON_INT32(1));
	if (!mongoc_client_command_simple(client, "admin", server_ping_cmd, NULL, NULL, &error))
	{
		UE_LOG(LogTemp, Error, TEXT("%s::%d Check server err.: %s"),
			*FString(__func__), __LINE__, *FString(error.message));
		bson_destroy(server_ping_cmd);
		return false;
	}

	bson_destroy(server_ping_cmd);
	return true;
#else
	return false;
#endif //SL_WITH_LIBMONGO_C
}

// Disconnect from the database
void USLMetadataLogger::Disconnect()
{
#if SL_WITH_LIBMONGO_C
	// Release handles and clean up mongoc
	if(uri)
	{
		mongoc_uri_destroy(uri);
	}
	if(client)
	{
		mongoc_client_destroy(client);
	}
	if(database)
	{
		mongoc_database_destroy(database);
	}
	if(collection)
	{
		mongoc_collection_destroy(collection);
	}
	if(doc)
	{
		bson_destroy(doc);
	}
	mongoc_cleanup();
#endif //SL_WITH_LIBMONGO_C
}

// Create the metadata document
void USLMetadataLogger::CreateDoc()
{
#if SL_WITH_LIBMONGO_C
	bson_oid_t oid;
	doc =  bson_new();

	bson_oid_init(&oid, NULL);
	BSON_APPEND_OID(doc, "_id", &oid);
#endif //SL_WITH_LIBMONGO_C
}

// Write the task description to the document
void USLMetadataLogger::AddTaskDescription(const FString& InTaskDescription)
{
#if SL_WITH_LIBMONGO_C
	BSON_APPEND_UTF8(doc, "task_description", TCHAR_TO_UTF8(*InTaskDescription));
#endif //SL_WITH_LIBMONGO_C
}

void USLMetadataLogger::AddEnvironmentData()
{
#if SL_WITH_LIBMONGO_C
	bson_t arr;
	bson_t sk_arr;
	bson_t arr_obj;
	char idx_str[16];
	const char *idx_key;
	uint32_t idx = 0;

	// Add entities to array
	BSON_APPEND_ARRAY_BEGIN(doc, "entities", &arr);
	// Iterate non skeletal semantic entities
	for (const auto& Pair : FSLEntitiesManager::GetInstance()->GetObjectsSemanticData())
	{
		const FSLEntity SemEntity = Pair.Value;

		// Ignore skeletal entities
		if (Cast<ASkeletalMeshActor>(SemEntity.Obj) || Cast<USkeletalMeshComponent>(SemEntity.Obj))
		{
			continue;
		}

		// Start array doc
		bson_uint32_to_string(idx, &idx_key, idx_str, sizeof idx_str);
		BSON_APPEND_DOCUMENT_BEGIN(&arr, idx_key, &arr_obj);

		BSON_APPEND_UTF8(&arr_obj, "id", TCHAR_TO_UTF8(*Pair.Value.Id));
		BSON_APPEND_UTF8(&arr_obj, "class", TCHAR_TO_UTF8(*Pair.Value.Class));

		FString ColorHex = FTags::GetValue(Pair.Value.Obj, "SemLog", "VisMask");
		if (!ColorHex.IsEmpty())
		{
			BSON_APPEND_UTF8(&arr_obj, "mask_hex", TCHAR_TO_UTF8(*ColorHex));
		}

		// Check if location data is available
		if (AActor* ObjAsAct = Cast<AActor>(SemEntity.Obj))
		{
			const FVector Loc = ObjAsAct->GetActorLocation();
			const FQuat Quat = ObjAsAct->GetActorQuat();
			AddPoseChild(Loc, Quat, &arr_obj);
		}
		else if (USceneComponent* ObjAsSceneComp = Cast<USceneComponent>(SemEntity.Obj))
		{
			const FVector Loc = ObjAsSceneComp->GetComponentLocation();
			const FQuat Quat = ObjAsSceneComp->GetComponentQuat();
			AddPoseChild(Loc, Quat, &arr_obj);
		}

		// Finish array doc
		bson_append_document_end(&arr, &arr_obj);
		idx++;
	}
	bson_append_array_end(doc, &arr);

	// Add skel entities to array
	BSON_APPEND_ARRAY_BEGIN(doc, "skel_entities", &sk_arr);
	// Reset array index
	idx=0;
	// Iterate skeletal semantic entities
	for (const auto& Pair : FSLEntitiesManager::GetInstance()->GetObjectsSkeletalSemanticData())
	{
		USLSkeletalDataComponent* SkelDataComp = Pair.Value;
		USkeletalMeshComponent* SkMComp = SkelDataComp->SkeletalMeshParent;
		const FSLEntity OwnerSemData = SkelDataComp->OwnerSemanticData;
		UObject* SemOwner = SkelDataComp->SemanticOwner;

		bson_uint32_to_string(idx, &idx_key, idx_str, sizeof idx_str);
		BSON_APPEND_DOCUMENT_BEGIN(&sk_arr, idx_key, &arr_obj);

		BSON_APPEND_UTF8(&arr_obj, "id", TCHAR_TO_UTF8(*OwnerSemData.Id));
		BSON_APPEND_UTF8(&arr_obj, "class", TCHAR_TO_UTF8(*OwnerSemData.Class));

		// Add semantic owner (component or actor) location
		if (AActor* ObjAsAct = Cast<AActor>(SemOwner))
		{
			const FVector Loc = ObjAsAct->GetActorLocation();
			const FQuat Quat = ObjAsAct->GetActorQuat();
			AddPoseChild(Loc, Quat, &arr_obj);
		}
		else if (USceneComponent* ObjAsSceneComp = Cast<USceneComponent>(SemOwner))
		{
			const FVector Loc = ObjAsSceneComp->GetComponentLocation();
			const FQuat Quat = ObjAsSceneComp->GetComponentQuat();
			AddPoseChild(Loc, Quat, &arr_obj);
		}

		// Check if the skeletal mesh is valid
		if (SkMComp)
		{
			bson_t bones_arr;
			bson_t bones_arr_obj;
			char jdx_str[16];
			const char *jdx_key;
			uint32_t jdx = 0;

			BSON_APPEND_ARRAY_BEGIN(&arr_obj, "bones", &bones_arr);
			// Create array of all the bones (with and without(empty strings) semantic data)
			for (const auto& BoneNameToDataPair : SkelDataComp->AllBonesData)
			{
				const FName BoneName = BoneNameToDataPair.Key;
				const FSLBoneData BoneData = BoneNameToDataPair.Value;
				const FVector BoneLoc = SkMComp->GetBoneLocation(BoneName);
				const FQuat BoneQuat = SkMComp->GetBoneQuaternion(BoneName);

				bson_uint32_to_string(jdx, &jdx_key, jdx_str, sizeof jdx_str);
				BSON_APPEND_DOCUMENT_BEGIN(&bones_arr, jdx_key, &bones_arr_obj);

				BSON_APPEND_UTF8(&bones_arr_obj, "name", TCHAR_TO_UTF8(*BoneName.ToString()));

				if (!BoneData.Class.IsEmpty())
				{
					BSON_APPEND_UTF8(&bones_arr_obj, "class", TCHAR_TO_UTF8(*BoneData.Class));

					if (!BoneData.MaskColorHex.IsEmpty())
					{
						BSON_APPEND_UTF8(&bones_arr_obj, "mask_hex", TCHAR_TO_UTF8(*BoneData.MaskColorHex));
					}
				}

				AddPoseChild(BoneLoc, BoneQuat, &bones_arr_obj);

				bson_append_document_end(&bones_arr, &bones_arr_obj);
				jdx++;
			}
			// Add the created array to the semantic item
			bson_append_array_end(&arr_obj, &bones_arr);
		}

		// Add the semantic item to the array
		bson_append_document_end(&sk_arr, &arr_obj);
		idx++;
	}
	bson_append_array_end(doc, &sk_arr);
#endif //SL_WITH_LIBMONGO_C
}

// Add camera views
void USLMetadataLogger::AddCameraViews()
{
#if SL_WITH_LIBMONGO_C
	bson_t arr;
	bson_t arr_obj;
	char idx_str[16];
	const char *idx_key;
	uint32_t idx = 0;

	// Add entities to array
	BSON_APPEND_ARRAY_BEGIN(doc, "camera_views", &arr);

	// Iterate non skeletal semantic entities
	for (const auto& Pair : FSLEntitiesManager::GetInstance()->GetCameraViewsSemanticData())
	{
		const FSLEntity SemEntity = Pair.Value;

		if (Cast<ASkeletalMeshActor>(SemEntity.Obj) || Cast<USkeletalMeshComponent>(SemEntity.Obj))
		{
			continue;
		}

		// Start array doc
		bson_uint32_to_string(idx, &idx_key, idx_str, sizeof idx_str);
		BSON_APPEND_DOCUMENT_BEGIN(&arr, idx_key, &arr_obj);

		BSON_APPEND_UTF8(&arr_obj, "id", TCHAR_TO_UTF8(*Pair.Value.Id));
		BSON_APPEND_UTF8(&arr_obj, "class", TCHAR_TO_UTF8(*Pair.Value.Class));
		
		// Check if location data is available
		if (AActor* ObjAsAct = Cast<AActor>(SemEntity.Obj))
		{
			const FVector Loc = ObjAsAct->GetActorLocation();
			const FQuat Quat = ObjAsAct->GetActorQuat();
			AddPoseChild(Loc, Quat, &arr_obj);
		}
		else if (USceneComponent* ObjAsSceneComp = Cast<USceneComponent>(SemEntity.Obj))
		{
			const FVector Loc = ObjAsSceneComp->GetComponentLocation();
			const FQuat Quat = ObjAsSceneComp->GetComponentQuat();
			AddPoseChild(Loc, Quat, &arr_obj);
		}

		// Finish array doc
		bson_append_document_end(&arr, &arr_obj);
		idx++;
	}

	bson_append_array_end(doc, &arr);
#endif //SL_WITH_LIBMONGO_C
}

// Add item image scans
void USLMetadataLogger::AddScans()
{
	UE_LOG(LogTemp, Error, TEXT("%s::%d Scanning.."), *FString(__func__), __LINE__);
}

// Insert the document to the collection
void USLMetadataLogger::InsertDoc()
{
#if SL_WITH_LIBMONGO_C
	bson_error_t error;
	if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, &error))
	{
		UE_LOG(LogTemp, Error, TEXT("%s::%d Err.: %s"),
			*FString(__func__), __LINE__, *FString(error.message));
	}
#endif //SL_WITH_LIBMONGO_C
}

#if SL_WITH_LIBMONGO_C
// Add pose to document
void USLMetadataLogger::AddPoseChild(const FVector& InLoc, const FQuat& InQuat, bson_t* out_doc)
{
	// Switch to right handed ROS transformation
	const FVector ROSLoc = FConversions::UToROS(InLoc);
	const FQuat ROSQuat = FConversions::UToROS(InQuat);

	bson_t child_obj_loc;
	bson_t child_obj_rot;

	BSON_APPEND_DOCUMENT_BEGIN(out_doc, "loc", &child_obj_loc);
	BSON_APPEND_DOUBLE(&child_obj_loc, "x", ROSLoc.X);
	BSON_APPEND_DOUBLE(&child_obj_loc, "y", ROSLoc.Y);
	BSON_APPEND_DOUBLE(&child_obj_loc, "z", ROSLoc.Z);
	bson_append_document_end(out_doc, &child_obj_loc);

	BSON_APPEND_DOCUMENT_BEGIN(out_doc, "rot", &child_obj_rot);
	BSON_APPEND_DOUBLE(&child_obj_rot, "x", ROSQuat.X);
	BSON_APPEND_DOUBLE(&child_obj_rot, "y", ROSQuat.Y);
	BSON_APPEND_DOUBLE(&child_obj_rot, "z", ROSQuat.Z);
	BSON_APPEND_DOUBLE(&child_obj_rot, "w", ROSQuat.W);
	bson_append_document_end(out_doc, &child_obj_rot);
}
#endif //SL_WITH_LIBMONGO_C
