#pragma once

#include <string>

enum class EItemType
{
	Wood,
	Stone,
	Iron,
	Plank,
	Axe
	
};

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