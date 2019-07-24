// Copyright 2019 dgtanaka@gmail.com All Rights Reserved.

#include "AssetTypeActions_PlatformMinLod.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "PlatformMinLod.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"


FText FAssetTypeActions_PlatformMinLod::GetName() const
{
	if (ParentAction.IsValid())
	{
		return ParentAction->GetName();
	}
	return NSLOCTEXT("AssetTypeActions", "AssetTypwActions_PlatformMinLod", "PlatformMinLod");
}

void FAssetTypeActions_PlatformMinLod::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	ParentAction->GetActions(InObjects, MenuBuilder);

	auto PlatformMinLodImports = GetTypedWeakObjectPtrs<UStaticMesh>(InObjects);
	MenuBuilder.AddMenuEntry(
		LOCTEXT("PlatformMinLod_SetMinLod", "Set Platform minLod"),
		LOCTEXT("PlatformMinLod_SetMinLodToolTip", "Set Platform minLod settings."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateSP(
				this, &FAssetTypeActions_PlatformMinLod::SetPlatformMinLod, PlatformMinLodImports),
			FCanExecuteAction()
		)
	);

}

void FAssetTypeActions_PlatformMinLod::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	ParentAction->OpenAssetEditor(InObjects, EditWithinLevelEditor);
}

void FAssetTypeActions_PlatformMinLod::GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const
{
	ParentAction->GetResolvedSourceFilePaths(TypeAssets, OutSourceFilePaths);
}

UThumbnailInfo* FAssetTypeActions_PlatformMinLod::GetThumbnailInfo(UObject* Asset) const
{
	return ParentAction->GetThumbnailInfo(Asset);
}


void FAssetTypeActions_PlatformMinLod::SetPlatformMinLod(TArray<TWeakObjectPtr<UStaticMesh>> Objects)
{
	UPlatformMinLod* PlatformMinLod = NewObject<UPlatformMinLod>();

	for (auto ObjIt = Objects.CreateIterator(); ObjIt; ++ObjIt)
	{
		UStaticMesh* mesh = (*ObjIt).Get();
		if (IsValid(mesh))
		{
			PlatformMinLod->SetPlatformMinLod(mesh);
		}
	}
}

#undef LOCTEXT_NAMESPACE
