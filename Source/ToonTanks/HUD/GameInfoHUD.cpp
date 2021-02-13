// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanks/Widgets/ScoreWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "GameInfoHUD.h"

AGameInfoHUD::AGameInfoHUD() 
{
	//links the the class of uscore widget
	ScoreWidgetClass = UScoreWidget::StaticClass();

    // static ConstructorHelpers::FClassFinder<UUserWidget> ScoreWidgetObj(TEXT("/Game/Blueprints/Widgets/WBP_ScoreWidget"));
	// ScoreWidgetClass = ScoreWidgetObj.Class;
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
	
	//reference to the scorewidget. this works!
	ScoreWidgetRef = Cast<UScoreWidget>(CurrentWidget);

	// GetObjectsOfClass(ScoreWidgetClass, WidgetArray);
	// ScoreWidgetRef = Cast<UScoreWidget>(WidgetArray[1]);

	// for (int32 i = 0; i < WidgetArray.Num(); i++)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("%s"), WidgetArray[i]->GetDesc());
		
	// }
	
	// UE_LOG(LogTemp, Warning, TEXT("%i is length of array"), WidgetArray.Num());

}

void AGameInfoHUD::UpdateScore() 
{

	//reference to the scorewidget. this works!
	// ScoreWidgetRef = Cast<UScoreWidget>(CurrentWidget);

	if (ScoreWidgetRef != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hubbidy Dibbity Doo UPDATE SCORE IS CALLED!1212211221"));
		ScoreWidgetRef->UpdateScore();
	}
	//tell the current widget to call its update score function
	//CurrentWidget->UpdateScore();
}

void AGameInfoHUD::DrawHUD() 
{
}
