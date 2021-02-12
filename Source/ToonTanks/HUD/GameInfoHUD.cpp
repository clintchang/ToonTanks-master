// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanks/Widgets/ScoreWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "GameInfoHUD.h"

AGameInfoHUD::AGameInfoHUD() 
{
    static ConstructorHelpers::FClassFinder<UUserWidget> ScoreWidgetObj(TEXT("/Game/Blueprints/Widgets/WBP_ScoreWidget"));
	ScoreWidgetClass = ScoreWidgetObj.Class;
}


void AGameInfoHUD::BeginPlay() 
{
    Super::BeginPlay();
	if (ScoreWidgetClass != nullptr)
	{	
        // .cpp - create the widget from the given class
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), ScoreWidgetClass);   

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AGameInfoHUD::DrawHUD() 
{
}
