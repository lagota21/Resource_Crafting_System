#pragma once
#include "../Data/ItemTypes.h"
#include <map>

class Inventory
{
public:
	void AddItem(EItemType Item, int Amount);
	bool HasItems(const std::map<EItemType, int>& cost) const;
	void RemoveItems(const std::map<EItemType, int>& cost);

	void Print() const;

private:
	std::map<EItemType, int> Items;
};
