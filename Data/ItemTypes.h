#pragma once

#include <string>

// This header defines the EItemType enum and a helper function to convert it to a string for display purposes.

// Enumeration of item types in the game.
//They can be gathered, stored in the inventory, and used in crafting recipes.
enum class EItemType
{
	Wood,
	Stone,
	Iron,
	Plank,
	Axe
	
};

//The switch statement converts the EItemType enum into values that are printed to the console when crafting items.
//ItemToString takes the EItemType and returns printable string representation of the item types to display them.
inline std::string ItemToString(EItemType type)
{
	switch (type)
	{
	case EItemType::Wood:
		return "Wood";
	case EItemType::Stone:
		return "Stone";
	case EItemType::Iron:
		return "Iron";
	case EItemType::Plank:
		return "Plank";
	case EItemType::Axe:
		return "Axe";
	default:
		return "Unknown";
	}
}