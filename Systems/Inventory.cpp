#include "Inventory.h"
#include <iostream>

void Inventory::AddItem(EItemType Item, int Amount)
{
	Items[Item] += Amount;
}

bool Inventory::HasItems(const std::map<EItemType, int>& cost) const
{
	for (const auto& Pair : cost)
	{
		auto it = Items.find(Pair.first);
		if (it == Items.end() || it->second < Pair.second)
		{
			return false;
		}
	}
	return true;
}

void Inventory::RemoveItems(const std::map<EItemType, int>& cost)
{
	for (const auto& Pair : cost)
	{
		Items[Pair.first] -= Pair.second;
	}
}

void Inventory::Print() const
{
	std::cout << "\n--- Inventory ---\n";
	for (const auto& Pair : Items)
	{
		std::cout << ItemToString(Pair.first) << ": " << Pair.second << "\n";
	}
}
