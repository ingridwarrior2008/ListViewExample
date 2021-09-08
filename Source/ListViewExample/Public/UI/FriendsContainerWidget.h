// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"


#include "FriendsContainerWidget.generated.h"

class UButton;
class UListView;
class UDataTable;

/**
 * 
 */
UCLASS()
class LISTVIEWEXAMPLE_API UFriendsContainerWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void OnCollapsedListAnimation(UListView* ListView);

	UFUNCTION(BlueprintImplementableEvent)
    void OnExpandListAnimation(UListView* ListView);
	
	/** A list view property to display the connected users.*/
	UPROPERTY(meta = (BindWidget))
	UListView* ConnectedListView;
	
	/** A list view property to display the disconnected users.*/
	UPROPERTY(meta = (BindWidget))
	UListView* DisconnectedListView;

	/** A Toggle button to show or hide connected list.*/
	UPROPERTY(meta = (BindWidget))
	UButton* ToggleConnectedListButton;

	/** A Toggle button to show or hide disconnected list.*/
	UPROPERTY(meta = (BindWidget))
	UButton* ToggleDisconnectedListButton;

	UPROPERTY(EditDefaultsOnly)
	UDataTable* FriendsData;

protected:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
private:

	UFUNCTION()
    void FetchFakeData();
	
	UFUNCTION()
	void OnToggleConnectedList();
	
	UFUNCTION()
    void OnToggleDisconnectedList();

	UFUNCTION()
    void ToggleListView(UListView* ListView);
};
