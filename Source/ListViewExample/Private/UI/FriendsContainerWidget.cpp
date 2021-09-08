// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FriendsContainerWidget.h"
#include "Engine/DataTable.h"
#include "Components/Button.h"
#include "Components/ListView.h"
#include "UI/FriendsDataObject.h"
#include "UI/FriendsModel.h"

#pragma region GameCycle

void UFriendsContainerWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (IsValid(ToggleConnectedListButton))
    {
        ToggleConnectedListButton->OnClicked.AddDynamic(this, &UFriendsContainerWidget::OnToggleConnectedList);
    }

    if (IsValid(ToggleDisconnectedListButton))
    {
        ToggleDisconnectedListButton->OnClicked.AddDynamic(this, &UFriendsContainerWidget::OnToggleDisconnectedList);
    }

    FetchFakeData();
}

void UFriendsContainerWidget::NativeDestruct()
{
    Super::NativeDestruct();

    if (IsValid(ToggleConnectedListButton))
    {
        ToggleConnectedListButton->OnClicked.RemoveDynamic(this, &UFriendsContainerWidget::OnToggleConnectedList);
    }

    if (IsValid(ToggleDisconnectedListButton))
    {
        ToggleDisconnectedListButton->OnClicked.RemoveDynamic(this, &UFriendsContainerWidget::OnToggleDisconnectedList);
    }
}


#pragma endregion

#pragma region Public methods

#pragma endregion

#pragma region Private methods

void UFriendsContainerWidget::FetchFakeData()
{
    if (!IsValid(FriendsData) || !IsValid(ConnectedListView) || !IsValid(DisconnectedListView))
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid values"));
        return;
    }

    for (const TPair<FName, uint8*> FriendsRowMap : FriendsData->GetRowMap())
    {
        FFriendsModelStruct* FriendsRow = FriendsData->FindRow<FFriendsModelStruct>(FriendsRowMap.Key, TEXT(""));

        if (!FriendsRow)
        {
            continue;
        }

        const FLinearColor ColorIndicator = FriendsRow->bIsConnected ? FLinearColor::Green : FLinearColor::Red;
        UFriendsDataObject* FriendsDataObject = UFriendsDataObject::InitializeObject(this, FText::FromString(FriendsRow->Username), ColorIndicator);

        if (FriendsRow->bIsConnected)
        {
            ConnectedListView->AddItem(FriendsDataObject);
        }
        else
        {
            DisconnectedListView->AddItem(FriendsDataObject);
        }
    }
}

void UFriendsContainerWidget::OnToggleConnectedList()
{
    ToggleListView(ConnectedListView);
}
	
void UFriendsContainerWidget::OnToggleDisconnectedList()
{
    ToggleListView(DisconnectedListView);
}

void UFriendsContainerWidget::ToggleListView(UListView* ListView)
{
    if (!IsValid(ListView))
    {
        UE_LOG(LogTemp, Warning, TEXT("Not valid list reference"));
        return;
    }
    
    const bool bIsCollapsed = ListView->Visibility == ESlateVisibility::Collapsed;

    if (bIsCollapsed)
    {
        OnExpandListAnimation(ListView);
    }
    else
    {
        OnCollapsedListAnimation(ListView);
    }
}

#pragma endregion
