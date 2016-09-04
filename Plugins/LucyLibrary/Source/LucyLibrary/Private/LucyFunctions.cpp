#include "LucyLibraryPrivatePCH.h"
#include "LucyFunctions.h"

ULucyFunctions::ULucyFunctions(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

void ULucyFunctions::SetMouseLockedToViewport(const bool Locked)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SViewport> ViewportWidget = ViewportClient->GetGameViewportWidget();
	if (!ViewportWidget.IsValid())
	{
		return;
	}

	TArray<APlayerController*> LocalPlayerControllers;
	GEngine->GetAllLocalPlayerControllers(LocalPlayerControllers);

	for (APlayerController* LocalPlayerController : LocalPlayerControllers)
	{
		if (LocalPlayerController == nullptr)
		{
			continue;
		}

		ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(LocalPlayerController->Player);
		if (LocalPlayer == nullptr)
		{
			continue;
		}

		if (Locked)
		{
			LocalPlayer->GetSlateOperations().LockMouseToWidget(ViewportWidget.ToSharedRef());
		}
		else
		{
			LocalPlayer->GetSlateOperations().ReleaseMouseLock();
		}
	}
}

void ULucyFunctions::GetPrimaryMonitorResolution(int32& Width, int32& Height)
{
	FDisplayMetrics DisplayMetrics;
	FDisplayMetrics::GetDisplayMetrics(DisplayMetrics);

	Width = DisplayMetrics.PrimaryDisplayWidth;
	Height = DisplayMetrics.PrimaryDisplayHeight;
}

UWidget* ULucyFunctions::GetRootWidget(const class UUserWidget* UserWidget)
{
	return UserWidget->GetRootWidget();
}

UPanelWidget* ULucyFunctions::GetAsPanelWidget(const class UWidget* Widget)
{
	return (UPanelWidget*)Widget;
}

void ULucyFunctions::GetTextSize(const FString& Text, const FSlateFontInfo& FontInfo, FVector2D& Size)
{
	TSharedRef<FSlateFontMeasure> FontMeasure = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
	Size = FontMeasure->Measure(Text, FontInfo, 1.0);
}

