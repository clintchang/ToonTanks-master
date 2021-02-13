// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"
#include "PawnTurret.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

    //get reference to the game instance
    //Get the world->game instance and cast to UTankGameInstance
    GameInstanceRef = Cast<UTankGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
    
    //get the HUD From the palyercontroller. the hud we'll tell to update the score
    HUDRef = Cast<AGameInfoHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
}

void APawnTurret::HandleDestruction() 
{

    //UE_LOG(LogTemp, Warning, TEXT("HandleDestruction"));
    //update score on death
    if (GameInstanceRef != nullptr)
	{	
        GameInstanceRef->IncrementScore(ScoreValue);

        //UE_LOG(LogTemp, Warning, TEXT("Increment Score call"));
        //tell HUD to update score
        if (HUDRef != nullptr)
        {
            HUDRef->UpdateScore();
        }

    }
    // Call base pawn class HandleDestruction to play effects.    
    Super::HandleDestruction();

    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);    

    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }

    RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition() 
{
    // If Player == null || is Dead THEN BAIL!!
    if(!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
    {
        return;
    }
    // If Player IS in range THEN FIRE!!
    if(ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
    }    
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if (!PlayerPawn)
    {
        return 0.0f;
    }
    
    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
