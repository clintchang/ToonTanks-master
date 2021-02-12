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

private:
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int32 GameScore = 0;

	void UpdateScore(int32 Value);

	UFUNCTION(BlueprintCallable)
	int32 GetScore();

protected:

	
};
