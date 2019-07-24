// Copyright 2019 dgtanaka@gmail.com All Rights Reserved.

#include "PlatformMinLodModule.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "AssetTypeActions_PlatformMinLod.h"

#define LOCTEXT_NAMESPACE "FPlatformMinLodModule"

void FPlatformMinLodModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	PlatformMinLodTypeActions = MakeShared<FAssetTypeActions_PlatformMinLod>();
	PlatformMinLodTypeActions->SetParent(FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().GetAssetTypeActionsForClass(UStaticMesh::StaticClass()).Pin());
	FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RegisterAssetTypeActions(PlatformMinLodTypeActions.ToSharedRef());
}

void FPlatformMinLodModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get().UnregisterAssetTypeActions(PlatformMinLodTypeActions.ToSharedRef());
	}
	PlatformMinLodTypeActions.Reset();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPlatformMinLodModule, PlatformMinLod)