#pragma once
#include <vector>
#include <map>
#include "../Data/ItemTypes.h"
#include "../Data/LocationTypes.h"

class Player;

struct FResourceNode
{
	std::string Name;
	EItemType ResourceType;
	int RequiredLevel;
	std::string ActionName;
};

class GatheringSystem
{
public:

	void InitNodes();
	void ShowNodes(ELocationType Location);
	void GatherFromNode(int Index, ELocationType Location, Player& Player);
	const std::vector<FResourceNode>& GetNodes(ELocationType Location) const;

private:
	std::map<ELocationType, std::vector<FResourceNode>> LocationNodes;
};