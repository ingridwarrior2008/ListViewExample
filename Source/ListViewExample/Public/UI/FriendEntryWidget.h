// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"

#include "FriendEntryWidget.generated.h"

class UBorder;
class UFriendsDataObject;
class UTextBlock;

/**
 * 
 */
UCLASS()
class LISTVIEWEXAMPLE_API UFriendEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void InitializeWidgetWithData(UObject* ListItemObject);
	
    UPROPERTY(meta = (BindWidget))
    UTextBlock* UsernameText;
	
    UPROPERTY(meta = (BindWidget))
    UBorder* ConnectionStatusIndicator;
};
