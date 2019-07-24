// Copyright 2019 dgtanaka@gmail.com All Rights Reserved.

#include "PlatformMinLod.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"

UPlatformMinLod::UPlatformMinLod(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void UPlatformMinLod::SetPlatformMinLod(UStaticMesh* InMesh)
{
	if (IsValid(InMesh))
	{
		if (InMesh->GetNumLODs() >= MinNumLod)
		{
			for (auto& plod :PlatformMinLodSettings)
			{
				InMesh->MinLOD.PerPlatform.Add(FName(*plod.PlatformName), plod.minLod);
			}
			InMesh->MarkPackageDirty();
		}
	}
}
