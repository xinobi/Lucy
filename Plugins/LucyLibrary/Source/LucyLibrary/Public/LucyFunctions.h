#pragma once

#include "Engine.h"
#include "UserWidget.h"
#include "LucyFunctions.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class ULucyFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	* Sets the mouse locked to the viewport (meaning the mouse cursor won't be able to get out of the viewport).
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Mouse", Meta = (DisplayName = "Set Mouse Locked To Viewport", Keywords = "cursor confined min max"))
		static void SetMouseLockedToViewport(const bool Locked);

	/**
	* Returns the primary monitor resolution.
	*/
	UFUNCTION(BlueprintPure, Category = "Lucy Library|Monitor", Meta = (DisplayName = "Get Primary Monitor Resolution", Keywords = "screen size desktop"))
		static void GetPrimaryMonitorResolution(int32& Width, int32& Height);

	/**
	* Returns the root widget of User Widget.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Widget", Meta = (DisplayName = "Get Root Widget"))
		static UWidget* GetRootWidget(const class UUserWidget* UserWidget);

	/**
	* Casts Widget to Panel Widget.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Widget", Meta = (DisplayName = "Get As Panel Widget"))
		static UPanelWidget* GetAsPanelWidget(const class UWidget* Widget);

	/**
	* Return size of rendered text.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Widget", Meta = (DisplayName = "Get Text Size"))
		static void GetTextSize(const FString& Text, const FSlateFontInfo& FontInfo, FVector2D& Size);
};
