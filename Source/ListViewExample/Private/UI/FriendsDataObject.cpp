// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FriendsDataObject.h"

UFriendsDataObject* UFriendsDataObject::InitializeObject(UObject* Owner, const FText Username, const FLinearColor Color)
{
    UFriendsDataObject* FriendsDataObject = NewObject<UFriendsDataObject>(Owner);
    
    if (!IsValid(FriendsDataObject))
    {
        return nullptr;
    }

    FriendsDataObject->FriendsUsername = Username;
    FriendsDataObject->ColorIndicator = Color;
    
    return FriendsDataObject;
}
