// Copyright 2019 dgtanaka@gmail.com All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAssetTypeActions_PlatformMinLod;

class FPlatformMinLodModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<FAssetTypeActions_PlatformMinLod> PlatformMinLodTypeActions;
};
