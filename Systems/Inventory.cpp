#include "Inventory.h"
#include <iostream>

void Inventory::AddItem(EItemType Item, int Amount)
{
	//This statement adds the Itemtype to the inventory plus the amount specified. If the item already exists, it increases the quantity by the specified amount.
	//if the item does not exist, it creates a new entry in the map with the specified amount.
	Items[Item] += Amount;
}

bool Inventory::HasItems(const std::map<EItemType, int>& cost) const
{
	//The range-based for loop iterates through the cost map, checking each pair of the ItemType and required amount.
	for (const auto& Pair : cost)
	{
		//Searches the inventory for the required ItemType (Pair.first).
		auto it = Items.find(Pair.first);
		
		/* Check to see if the item does not exist in the inventory (it == Items.end())
		* or if the quantity of the item in the inventory is less than the required amount (it->second < Pair.second).
		* and if either condition is true, it returns false, indicating that the inventory does not have the required items.
		*/
		if (it == Items.end() || it->second < Pair.second)
		{
			return false;
		}
	}
	//The loop will skip the if statement if all elements in the cost map are found of ItemType and amount.
	//If this is the case, the loop will complete and the function will return true, giving the ability to craft the item.
	return true;
}

void Inventory::RemoveItems(const std::map<EItemType, int>& cost)
{
	//The range-based for loop iterates over the cost map.
	for (const auto& Pair : cost)
	{
		//The Item amount in the inventory is reduced by the value specified in the cost map for each ItemType (Pair.first).
		//This removes the required items from the inventory after crafting an item.
		Items[Pair.first] -= Pair.second;
	}
}

void Inventory::Print() const
{
	std::cout << "\n--- Inventory ---\n";

	if (Items.empty())
	{
		std::cout << "\nThe Inventory currently does not have any items stored.\n";
	}
	//The range-based for loop iterates through the Items map, printing each ItemType and its corresponding quantity.
	for (const auto& Pair : Items)
	{
		std::cout << ItemToString(Pair.first) << ": " << Pair.second << "\n";
	}
}
