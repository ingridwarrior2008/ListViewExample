// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FriendEntryWidget.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "UI/FriendsDataObject.h"

void UFriendEntryWidget::InitializeWidgetWithData(UObject* ListItemObject)
{
    if (!IsValid(ListItemObject))
    {
        return;
    }
    
    UFriendsDataObject* FriendsDataObject = Cast<UFriendsDataObject>(ListItemObject);

    if (!IsValid(FriendsDataObject))
    {
        return;
    }
    UsernameText->SetText(FriendsDataObject->FriendsUsername);
    ConnectionStatusIndicator->BrushColor = FriendsDataObject->ColorIndicator;
}
