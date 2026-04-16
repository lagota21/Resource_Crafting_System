#pragma once
#include "../Systems/Inventory.h"
#include "../Systems/GatheringSystem.h"
#include "../Systems/CraftingSystem.h"
#include "../Systems/TraverseSystem.h"
#include "../Core/Player.h"
#include "../UI/ConsoleUI.h"

class GameManager
{
public:
	//Initalises the reicpes in the crafting system and resource nodes in the gathering system.
	void Init();
	void Run();

	//function to handle gathering logic - tied to location-based resource nodes. 
	void HandleGathering();

	//function to handle crafting logic - compares inventory contents to ingredient requirements
	void HandleCrafting();

private:

	//class variables
	GatheringSystem Gatherer;
	CraftingSystem Crafter;
	TraverseSystem Traveler;
	Player PlayerCharacter;
	ConsoleUI UI;

	//actions taken 
	int ActionCounter = 0;

};