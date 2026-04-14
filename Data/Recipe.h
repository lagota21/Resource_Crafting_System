#pragma once

#include "ItemTypes.h"
#include <map>

//This struct defines crafting a recipe in the game.

struct FRecipe
{
	// The Result field specifies the type of item that will be produced when the recipe is crafted.
	EItemType Result;
	// The Ingredients map holds the required items and their quantities needed to craft the resulting item.
	std::map<EItemType, int> Ingredients;
	// The DisplayName is a human-readable name for the recipe, used for displaying in the UI or console output.
	std::string DisplayName; 
};
