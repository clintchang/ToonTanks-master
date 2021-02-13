// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateScore();

	//test functions not needed
	// UFUNCTION(BlueprintCallable)
	// void CallBoop();

	//test functions not needed
	// UFUNCTION(BlueprintCallable)
	// int32 GetBoop();

private:

	//test functions not needed
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
	// int32 Boop = 333;



protected:
	
};
