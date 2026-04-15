#pragma once
#include "../Systems/Inventory.h"

class Player
{
public:
	int Level = 1;
	int XP = 0;

	Inventory PlayerInventory;
};