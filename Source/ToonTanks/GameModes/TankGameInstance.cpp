// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameInstance.h"


void UTankGameInstance::UpdateScore(int32 Value) 
{
    GameScore = GameScore + Value;
}

int32 UTankGameInstance::GetScore() 
{
    return GameScore;
}
