#pragma once
#include "../Systems/Inventory.h"
#include "../Systems/GatheringSystem.h"
#include "../Systems/CraftingSystem.h"
#include "../Systems/TraverseSystem.h"
#include "../Core/Player.h"

class GameManager
{
public:
	void Init();
	void Run();

	void HandleGathering();
	void HandleCrafting();

private:
	GatheringSystem Gatherer;
	CraftingSystem Crafter;
	TraverseSystem Traveler;
	Player PlayerCharacter;

	int ActionCounter = 0;

};