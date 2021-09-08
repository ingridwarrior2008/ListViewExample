// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"

#include "FriendsModel.generated.h"

USTRUCT(BlueprintType)
struct FFriendsModelStruct : public FTableRowBase
{
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Friends")
    FString Username;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Friends")
    uint8 bIsConnected : 1 ;
};