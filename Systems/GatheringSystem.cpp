#include "GatheringSystem.h"
#include "../Core/Player.h"
#include <iostream>

void GatheringSystem::InitNodes()
{
	//Forest Nodes
	LocationNodes[ELocationType::Forest] =
	{
		{"Tree [lvl.1]", EItemType::NormalLog, 1},
	    {"Oak Tree [lvl.5]", EItemType::OakLog, 5},
		{"Willow Tree [lvl.15]", EItemType::WillowLog, 15}
	};

	LocationNodes[ELocationType::Mine] =
	{
		{"Rock [lvl.1]", EItemType::Stone, 1},
		{"Iron Ore [lvl.5]", EItemType::IronOre, 5},
		{"Gold Ore [lvl.15]", EItemType::GoldOre, 15}
	};

	LocationNodes[ELocationType::River] =
	{
		{"Shallow Waters [lvl.1]", EItemType::RawShrimp, 1},
		{"Waterfall [lvl.5]", EItemType::RawSalmon, 5},
		{"Deep Waters [lvl.15]", EItemType::RawShark, 15}
	};
}

void GatheringSystem::ShowNodes(ELocationType Location)
{
	auto it = LocationNodes.find(Location);
	
	if (it == LocationNodes.end())
	{
		std::cout << "No Resources Here!\n";
		return;
	}

	for (size_t i = 0; i < it->second.size(); ++i)
	{
		std::cout << i + 1 << ". " << it->second[i].Name << "\n";
	}
}

void GatheringSystem::GatherFromNode(int Index, ELocationType Location, Player& Player)
{
	auto it = LocationNodes.find(Location);
	if (it == LocationNodes.end()) return;

	if (Index < 0 || Index >= it->second.size()) return;

	const FResourceNode& Node = it->second[Index];

	Player.PlayerInventory.AddItem(Node.ResourceType, 1);

	std::cout << "Gathered : " << ItemToString(Node.ResourceType) << "\n";
}

const std::vector<FResourceNode>& GatheringSystem::GetNodes(ELocationType Location) const
{
	static const std::vector<FResourceNode> Empty;

	auto it = LocationNodes.find(Location);

	if (it == LocationNodes.end())
	{
		return Empty;
	}

	return it->second;
}

