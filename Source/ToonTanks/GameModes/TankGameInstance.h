// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TankGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UTankGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	void IncrementScore(int32 Value);

private:
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int32 GameScore = 0;


	UFUNCTION(BlueprintCallable)
	int32 GetScore();

protected:

	
};
