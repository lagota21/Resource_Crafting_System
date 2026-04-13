#pragma once

#include "ItemTypes.h"
#include <map>

struct FRecipe
{
	EItemType Result;
	std::map<EItemType, int> Ingredients;
	std::string DisplayName; // Optional: For better display purposes showing multiple items in the recipe
};
