// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FriendsDataObject.generated.h"

/**
 * 
 */
UCLASS()
class LISTVIEWEXAMPLE_API UFriendsDataObject : public UObject
{
	GENERATED_BODY()
	
public:

	static UFriendsDataObject* InitializeObject(UObject* Owner, const FText Username, const FLinearColor Color);

    UPROPERTY(BlueprintReadOnly, Category = FriendDataObject)
    FText FriendsUsername;

	UPROPERTY(BlueprintReadOnly, Category = FriendDataObject)
	FLinearColor ColorIndicator;
};
