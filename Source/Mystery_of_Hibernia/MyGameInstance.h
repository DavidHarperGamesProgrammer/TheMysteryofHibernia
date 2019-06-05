// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Widget.h"
#include "Widgets/SWidget.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "MyGameInstance.generated.h"





UCLASS()
class MYSTERY_OF_HIBERNIA_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	UFUNCTION()
		virtual void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
		virtual void EndLoadingScreen(UWorld* InLoadedWorld);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wLoadingScreen;

	UUserWidget* MyLoadingScreen;
	
private:
	TSharedPtr <class SWidget> LoadWidget;
	
};
