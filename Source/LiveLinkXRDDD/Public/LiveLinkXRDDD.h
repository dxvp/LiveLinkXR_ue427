// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogLiveLinkXRDDD, Log, All);

class FLiveLinkXRDDDModule : public IModuleInterface
{
public:

	static FLiveLinkXRDDDModule& Get()
	{
		return FModuleManager::Get().LoadModuleChecked<FLiveLinkXRDDDModule>(TEXT("LiveLinkXRDDD"));
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
