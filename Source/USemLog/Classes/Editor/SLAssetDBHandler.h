// Copyright 2019, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "Editor/SLEditorStructs.h"
#if SL_WITH_LIBMONGO_C
	THIRD_PARTY_INCLUDES_START
	#if PLATFORM_WINDOWS
		#include "Windows/AllowWindowsPlatformTypes.h"
		#include <mongoc/mongoc.h>
		#include "Windows/HideWindowsPlatformTypes.h"
	#else
		#include <mongoc/mongoc.h>
	#endif // #if PLATFORM_WINDOWS
THIRD_PARTY_INCLUDES_END
#endif //SL_WITH_LIBMONGO_C

/**
 * Helper class for reading and writing vision related data to mongodb
 */
class FSLAssetDBHandler
{
public:
	// Ctor
	FSLAssetDBHandler();

	// Connect to the database
	bool Connect(const FString& DBName, const FString& ServerIp,
		uint16 ServerPort, ESLAssetAction InAction, bool bOverwrite = false);

	// Disconnect and clean db connection
	void Disconnect() const;

	// Create indexes on the inserted data
	void CreateIndexes() const;

	// Execute the upload or download action
	void Execute();

private:
	// Upload assets
	void Upload();

	// Download assets
	void Download();

#if SL_WITH_LIBMONGO_C
	// Save image to gridfs, get the file oid and return true if succeeded
	bool AddToGridFs(const TArray<uint8>& InData, bson_oid_t* out_oid) const;
#endif //SL_WITH_LIBMONGO_C

private:
	// Cache the action
	ESLAssetAction Action;

#if SL_WITH_LIBMONGO_C
	// Server uri
	mongoc_uri_t* uri;

	// MongoC connection client
	mongoc_client_t* client;

	// Database to access
	mongoc_database_t* database;

	// Database collection
	mongoc_collection_t* collection;

	// Store image binaries
	mongoc_gridfs_t* gridfs;
#endif //SL_WITH_LIBMONGO_C		
};