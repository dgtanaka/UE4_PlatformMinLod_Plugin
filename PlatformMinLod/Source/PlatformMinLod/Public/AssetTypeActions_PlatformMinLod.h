// Copyright 2019 dgtanaka@gmail.com All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlatformMinLod.h"
#include "AssetTypeActions_Base.h"

class UStaticMesh;

class PLATFORMMINLOD_API FAssetTypeActions_PlatformMinLod : public FAssetTypeActions_Base
{
public:

	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override { return FColor(0, 255, 255); }
	virtual UClass* GetSupportedClass() const override { return UStaticMesh::StaticClass(); }
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Basic; }
	virtual class UThumbnailInfo* GetThumbnailInfo(UObject* Asset) const override;
	virtual bool IsImportedAsset() const override { return true; }
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
	virtual void GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const override;

	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

	void SetParent(TSharedPtr<IAssetTypeActions>InParent) { ParentAction = InParent;  }

private:
	void SetPlatformMinLod(TArray<TWeakObjectPtr<UStaticMesh>> Objects);

	TSharedPtr<IAssetTypeActions>ParentAction;
};
