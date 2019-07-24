// Copyright 2019 dgtanaka@gmail.com All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlatformMinLod.generated.h"

/**
Add settings to DefaultEditor.ini.

Example:

[/Script/PlatformMinLod.PlatformMinLod]
MinNumLod=3
+PlatformMinLodSettings=(PlatformName="Console",minLod=1)
+PlatformMinLodSettings=(PlatformName="Mobile",minLod=2)

 */




class UStaticMesh;

USTRUCT(BlueprintType)
struct FPlatformMinLodSettings
{
	GENERATED_USTRUCT_BODY()

		FPlatformMinLodSettings()
		: PlatformName(TEXT(""))
		, minLod(0)
	{}

	UPROPERTY(config, EditAnywhere, Category = "PlatformMinLod")
	FString PlatformName;

	UPROPERTY(config, EditAnywhere, Category = "PlatformMinLod")
	int32 minLod;
};

UCLASS(config = Editor, defaultconfig)
class PLATFORMMINLOD_API UPlatformMinLod : public UObject
{
	GENERATED_UCLASS_BODY()
	
public:
	UPROPERTY(Config, BlueprintReadOnly, Category = "PlatformMinLod")
	int MinNumLod;

	UPROPERTY(Config, BlueprintReadOnly, Category = "PlatformMinLod")
	TArray<FPlatformMinLodSettings> PlatformMinLodSettings;

	UFUNCTION(BlueprintCallable, Category = "PlatformMinLod")
	void SetPlatformMinLod(UStaticMesh* staticMesh);
};
