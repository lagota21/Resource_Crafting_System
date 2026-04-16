#pragma once
#include "../Systems/Inventory.h"

class Player
{
public:
	int Level = 1;
	int XP = 0;

	//Reference to the Inventory class to handle Inventory logic in the GM.
	Inventory PlayerInventory;
};