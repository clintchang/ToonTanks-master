// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameInfoHUD.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AGameInfoHUD : public AHUD
{
	GENERATED_BODY()


public:

	AGameInfoHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> ScoreWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UUserWidget* CurrentWidget;


private:

	// UPROPERTY(EditAnywhere, Category = "Health")
	// TSubclassOf<class UUserWidget> HUDWidgetClass;

	// UPROPERTY(EditAnywhere, Category = "Health")
	// class UUserWidget* CurrentWidget;


};
