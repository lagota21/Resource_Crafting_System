#pragma once

#include <string>

// This header defines the EItemType enum and a helper function to convert it to a string for display purposes.

// Enumeration of item types in the game.
//They can be gathered, stored in the inventory, and used in crafting recipes.
enum class EItemType
{
	//wood tier
	NormalLog,
	OakLog,
	WillowLog,

	//stone tier
	Stone,
	IronOre,
	GoldOre,

	//fish tier
	RawShrimp,
	RawSalmon,
	RawShark,

	//craft items
	Plank,
	IronBar,
	CookedShrimp,
	Axe
	
};

//The switch statement converts the EItemType enum into values that are printed to the console when crafting items.
//ItemToString takes the EItemType and returns printable string representation of the item types to display them.
inline std::string ItemToString(EItemType type)
{
	switch (type)
	{
	case EItemType::NormalLog:
		return "Normal Log";
	case EItemType::OakLog:
		return "Oak Log";
	case EItemType::WillowLog:
		return "Willow Log";
	case EItemType::Stone:
		return "Stone";
	case EItemType::IronOre:
		return "Iron Ore";
	case EItemType::GoldOre:
		return "Gold Ore";
	case EItemType::RawShrimp:
		return "Raw Shrimp";
	case EItemType::RawSalmon:
		return "Raw Salmon";
	case EItemType::RawShark:
		return "Raw Shark";
	case EItemType::Plank:
		return "Normal Plank";
	case EItemType::IronBar:
		return "Iron Bar";
	case EItemType::CookedShrimp:
		return "Shrimp";
	case EItemType::Axe:
		return "Axe";
	default:
		return "Unknown";
	}
}