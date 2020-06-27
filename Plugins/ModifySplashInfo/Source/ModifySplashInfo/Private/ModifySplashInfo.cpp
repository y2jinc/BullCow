// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ModifySplashInfo.h"
#include "HAL/PlatformSplash.h"
#include "Misc/App.h"
#include "Misc/EngineVersion.h"
#include "Misc/EngineBuildSettings.h"

#define LOCTEXT_NAMESPACE "FModifySplashInfoModule"

void FModifySplashInfoModule::StartupModule()
{
	// decide on which splash screen to show
	const FText GameName = FText::FromString(FApp::GetProjectName());
	FText VersionInfo;
	FText AppName;

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	const FText Version = FText::FromString(FEngineVersion::Current().ToString(FEngineBuildSettings::IsPerforceBuild() ? EVersionComponent::Branch : EVersionComponent::Patch));
	VersionInfo = FText::Format(NSLOCTEXT("UnrealEd", "UnrealEdTitleWithVersion_F", "Unreal Editor {0}  -  {1} Master or DEV"), Version, GameName);
	AppName = FText::Format(NSLOCTEXT("UnrealEd", "UnrealEdTitle_F", "Unreal Editor - {0} Master or DEV"), GameName);
	
	//FPlatformSplash::SetSplashText(SplashTextType::GameName, FApp::GetProjectName());
	FPlatformSplash::SetSplashText(SplashTextType::GameName, *AppName.ToString());
	FPlatformSplash::SetSplashText(SplashTextType::VersionInfo1, *VersionInfo.ToString());

	FModuleManager::Get().UnloadModule(FName(TEXT("ModifySplashInfo")), true);
}

void FModifySplashInfoModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FModifySplashInfoModule, ModifySplashInfo)