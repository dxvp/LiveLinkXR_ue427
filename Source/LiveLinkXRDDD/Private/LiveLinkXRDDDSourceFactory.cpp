// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiveLinkXRDDDSourceFactory.h"
#include "LiveLinkXRDDDSource.h"
#include "SLiveLinkXRDDDSourceFactory.h"
#include "LiveLinkXRDDDSourceSettings.h"

#include "ILiveLinkClient.h"
#include "Features/IModularFeatures.h"

#define LOCTEXT_NAMESPACE "LiveLinkXRDDDSourceFactory"

FText ULiveLinkXRDDDSourceFactory::GetSourceDisplayName() const
{
	return LOCTEXT("SourceDisplayName", "LiveLinkXRDDD Source");	
}

FText ULiveLinkXRDDDSourceFactory::GetSourceTooltip() const
{
	return LOCTEXT("SourceTooltip", "Allows creation of multiple LiveLink sources using the XR tracking system");
}

TSharedPtr<SWidget> ULiveLinkXRDDDSourceFactory::BuildCreationPanel(FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated) const
{
	return SNew(SLiveLinkXRDDDSourceFactory)
		.OnConnectionSettingsAccepted(FOnLiveLinkXRDDDConnectionSettingsAccepted::CreateUObject(this, &ULiveLinkXRDDDSourceFactory::CreateSourceFromSettings, InOnLiveLinkSourceCreated));
}

TSharedPtr<ILiveLinkSource> ULiveLinkXRDDDSourceFactory::CreateSource(const FString& ConnectionString) const
{
	FLiveLinkXRDDDConnectionSettings ConnectionSettings;
	if (!ConnectionString.IsEmpty())
	{
		FLiveLinkXRDDDConnectionSettings::StaticStruct()->ImportText(*ConnectionString, &ConnectionSettings, nullptr, PPF_None, GLog, TEXT("ULiveLinkXRDDDSourceFactory"));
	}
	return MakeShared<FLiveLinkXRDDDSource>(ConnectionSettings);
}

void ULiveLinkXRDDDSourceFactory::CreateSourceFromSettings(FLiveLinkXRDDDConnectionSettings InConnectionSettings, FOnLiveLinkSourceCreated OnSourceCreated) const
{
	FString ConnectionString;
	FLiveLinkXRDDDConnectionSettings::StaticStruct()->ExportText(ConnectionString, &InConnectionSettings, nullptr, nullptr, PPF_None, nullptr);

	TSharedPtr<FLiveLinkXRDDDSource> SharedPtr = MakeShared<FLiveLinkXRDDDSource>(InConnectionSettings);
	OnSourceCreated.ExecuteIfBound(SharedPtr, MoveTemp(ConnectionString));
}

#undef LOCTEXT_NAMESPACE
