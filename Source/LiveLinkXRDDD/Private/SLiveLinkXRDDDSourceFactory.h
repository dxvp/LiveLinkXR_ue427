// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LiveLinkXRDDDConnectionSettings.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

#if WITH_EDITOR
#include "IStructureDetailsView.h"
#endif //WITH_EDITOR

#include "Input/Reply.h"

struct FLiveLinkXRDDDConnectionSettings;

DECLARE_DELEGATE_OneParam(FOnLiveLinkXRDDDConnectionSettingsAccepted, FLiveLinkXRDDDConnectionSettings);

class SLiveLinkXRDDDSourceFactory : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SLiveLinkXRDDDSourceFactory)
	{}
		SLATE_EVENT(FOnLiveLinkXRDDDConnectionSettingsAccepted, OnConnectionSettingsAccepted)
	SLATE_END_ARGS()

	void Construct(const FArguments& Args);


private:
	FLiveLinkXRDDDConnectionSettings ConnectionSettings;

#if WITH_EDITOR
	TSharedPtr<FStructOnScope> StructOnScope;
	TSharedPtr<IStructureDetailsView> StructureDetailsView;
#endif //WITH_EDITOR

	FReply OnSettingsAccepted();
	FOnLiveLinkXRDDDConnectionSettingsAccepted OnConnectionSettingsAccepted;
};