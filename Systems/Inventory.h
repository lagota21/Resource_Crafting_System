#pragma once
#include "../Data/ItemTypes.h"
#include <map>

class Inventory
{
public:
	//AddItem an item to the inventory. If the item already exists, it increases the quantity by the specified amount.
	void AddItem(EItemType Item, int Amount);
	//HasItems checks if the inventory contains the required items and quantities specified in the cost map.
	bool HasItems(const std::map<EItemType, int>& cost) const;
	//RemoveItems removes the specified items and quantities from the inventory. 
	void RemoveItems(const std::map<EItemType, int>& cost);
	
	//Print displays the current contents of the inventory.
	void Print() const;

private:
	//The items in the inventory are stored in a map where the key is the EItemType and the value is the quantity of that item.
	std::map<EItemType, int> Items;
};
