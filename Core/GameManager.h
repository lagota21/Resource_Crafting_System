#pragma once
#include "../Systems/Inventory.h"
#include "../Systems/GatheringSystem.h"
#include "../Systems/CraftingSystem.h"

class GameManager
{
public:
	void Init();
	void Run();

	void HandleGathering();
	void HandleCrafting();

private:
	Inventory PlayerInventory;
	GatheringSystem Gatherer;
	CraftingSystem Crafter;
};