// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"


int32 UScoreWidget::GetBoop() 
{
    return Boop;
}

void UScoreWidget::CallBoop() 
{
    UE_LOG(LogTemp, Warning, TEXT("CallBoop"));
}
