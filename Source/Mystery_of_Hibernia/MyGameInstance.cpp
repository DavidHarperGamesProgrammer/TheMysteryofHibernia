// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MoviePlayer.h"


void UMyGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UMyGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UMyGameInstance::EndLoadingScreen);
}

void UMyGameInstance::BeginLoadingScreen(const FString& InMapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		
LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		if (wLoadingScreen)
		{
			MyLoadingScreen = CreateWidget<UUserWidget>(this, wLoadingScreen);
			LoadWidget = MyLoadingScreen->TakeWidget();

			if (MyLoadingScreen)
			{
				LoadingScreen.WidgetLoadingScreen = LoadWidget;
			}
		}


		
		

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void UMyGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{

}



