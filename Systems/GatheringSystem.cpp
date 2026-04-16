#include "GatheringSystem.h"
#include "../Core/Player.h"
#include <iostream>

void GatheringSystem::InitNodes()
{
	//Forest Nodes
	LocationNodes[ELocationType::Forest] =
	{
		{"Tree [lvl.1]", EItemType::NormalLog, 1, "Chopping"},
	    {"Oak Tree [lvl.5]", EItemType::OakLog, 5, "Chopping"},
		{"Willow Tree [lvl.15]", EItemType::WillowLog, 15, "Chopping"}
	};

	//Mining Nodes
	LocationNodes[ELocationType::Mine] =
	{
		{"Rock [lvl.1]", EItemType::Stone, 1, "Mining"},
		{"Iron Vein [lvl.5]", EItemType::IronOre, 5, "Mining"},
		{"Gold Vein [lvl.15]", EItemType::GoldOre, 15, "Mining"}
	};

	//Fishing Nodes.
	LocationNodes[ELocationType::River] =
	{
		{"Shallow Waters [lvl.1]", EItemType::RawShrimp, 1, "Fishing"},
		{"Waterfall [lvl.5]", EItemType::RawSalmon, 5, "Fishing"},
		{"Deep Waters [lvl.15]", EItemType::RawShark, 15, "Fishing"}
	};
}

void GatheringSystem::ShowNodes(ELocationType Location)
{
	//find the LocationTypes
	auto it = LocationNodes.find(Location);
	
	//If a location is not part of the map then it will print an output and return.
	if (it == LocationNodes.end())
	{
		std::cout << "No Resources Here!\n";
		return;
	}

	//iterate through the ResourceNode vector displaying the available nodes for the selected location.
	for (size_t i = 0; i < it->second.size(); ++i)
	{
		std::cout << i + 1 << ". " << it->second[i].Name << "\n";
	}
}

void GatheringSystem::GatherFromNode(int Index, ELocationType Location, Player& Player)
{
	
	auto it = LocationNodes.find(Location);
	if (it == LocationNodes.end()) return;

	//Validation check that returns when the index is negative and the index is not within the bounds of the ResourceNode vector.
	if (Index < 0 || Index >= it->second.size()) return;

	const FResourceNode& Node = it->second[Index];

	int GatherAmount = 1;

	//Adding the resource to the player inventory, passing in the resource type and amount to add.
	Player.PlayerInventory.AddItem(Node.ResourceType, GatherAmount);

	//
	std::cout << "\nGathered : " << ItemToString(Node.ResourceType) << " x" << GatherAmount << "\n";
}

const std::vector<FResourceNode>& GatheringSystem::GetNodes(ELocationType Location) const
{
	//
	static const std::vector<FResourceNode> Empty;

	//
	auto it = LocationNodes.find(Location);

	if (it == LocationNodes.end())
	{
		return Empty;
	}

	return it->second;
}

