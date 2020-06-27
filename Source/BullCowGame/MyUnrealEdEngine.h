// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Editor/UnrealEdEngine.h"
#include "MyUnrealEdEngine.generated.h"

/**
 * 
 */
UCLASS()
class BULLCOWGAME_API UMyUnrealEdEngine : public UUnrealEdEngine
{
	GENERATED_BODY()
	
public:
	//~ Begin UEngine Interface.
	virtual void Init(IEngineLoop* InEngineLoop) override;
	//~ End UEngine Interface.

};
