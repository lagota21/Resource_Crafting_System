#include "GameManager.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void GameManager::Init()
{
	// Initialize crafting recipes using the Recipe struct defined in Recipe.h.
	//Defines required amounts, display names, and the resulting item for each recipe.
	Crafter.InitRecipes();
	Gatherer.InitNodes();

}

void GameManager::Run()
{
	
	// The choice variable is used to store the action selected by the player from the interaction menu.
	int Choice = 0;

	// The RefreshRate constant determines how many player actions occur before the console is cleared and the menu is refreshed,
	//avoids clogging the console with repeated actions and keeps the interface clean and user-friendly with refreshing the menu.
	const int RefreshRate = 5; 
	//Keeps track of actions taken by the player.
	int ActionCounter = 0;

	// The main game loop continues until the player chooses to exit (Choice == 4).
	while (true)
	{
		//UI will be displayed at start with the action counter check at 0.
		if (ActionCounter == 0)
		{
			//clears the screen
			UI.ClearScreen();

			//the function adds the title string text with seperators.
			UI.DrawTitle("RPG SIMULATION");

			//the action menu will display all actions that can be selected.
			std::cout << "\n___ Action Menu ___\n";
			UI.DrawMenu({
				"Gather Resource",
				"Craft Item",
				"View Inventory",
				"Travel",
				"Exit"

				});
		}

		
		std::cout << "\nChoose an action: ";
		
		std::cin >> Choice;

		// Input validation to ensure the player enters a valid integer choice.
		if (std::cin.fail())
		{
			std::cin.clear(); // Clear error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << "Invalid input!" << std::endl;
			continue;
		}

		//Exit condition to break the loop and end the game the value is determined on the number of actions of the switch +1.
		if (Choice == 5)
			break;

		// Handle the player's choice by calling the appropriate function based on the selected action.
		//The case value corresponds to the menu options displayed to the player, allowing them to gather resources, craft items, or view their inventory.
		switch (Choice)
		{
		case 1:
			HandleGathering();
			break;
		case 2:
			HandleCrafting();
			break;
		case 3:
			PlayerCharacter.PlayerInventory.Print();
			break;
		case 4:
			Traveler.HandleTravel();
			break;
		default:
			std::cout << "\nInvalid choice!" << std::endl;
			break;

		}

		// Increment the ActionCounter after each action.
		ActionCounter++;

		//Resets the ActionCounter to 0 when it reaches the RefreshRate, triggering a menu refresh on the next iteration of the loop.
		if (ActionCounter >= RefreshRate)
		{
			ActionCounter = 0;
		}
	}
}


void GameManager::HandleGathering()
{
	//Getting the player's current location from the travel system.
	//This determines which resource are available per location.
	ELocationType Location = Traveler.GetCurrentLocation();

	//Retrive a read-only reference to the resource nodes for the current location.
	//Const reference avoid copying the vector while allowing safe access for validation.
	const auto& Nodes = Gatherer.GetNodes(Location);

	//If no nodes exist at the location (e.g., Town), prevent gathering.
	if (Nodes.empty())
	{
		std::cout << "\nNo resources here!\n";
		return;
	}

	//Display available resource nodes to the player.
	//Handled by the gathering system to keep UI logic seperate from GM.
	Gatherer.ShowNodes(Location);

	int Selection;
	std::cout << "\nChoose resource: ";
	std::cin >> Selection;

	int Index = Selection - 1; // convert to vector index 0;

	// Validate input to ensure the selected index is in range - prevents invalid access.
	if (Index < 0 || Index > Nodes.size())
	{
		std::cout << "\nInvalid selection!\n";
		return;
	}

	std::cout << std::endl;

	const FResourceNode& Node = Nodes[Index];

	UI.PlayerActionAnimation(Node.ActionName);
	//Pass the selected node index, location, and player ref to the gather system.
	//The system handles resource validation, and adding the item to the player's inventory.
	Gatherer.GatherFromNode(Index, Location, PlayerCharacter);
}

void GameManager::HandleCrafting()
{
	//Retrive all recipes that can be crafted based on the player's inventory contents.
	//Crafting system filters out recipes that are missing items.
	auto ValidRecipes = Crafter.GetValidRecipes(PlayerCharacter.PlayerInventory);

	//If no recipes are valid - material requirements are lacking.
	//The Recipes will be an empty list and will return.
	if (ValidRecipes.empty())
	{
		std::cout << "\nNo valid recipes to craft!\n";
		return;
	}

	std::cout << "\nAvailable Recipes:\n";

	//Display all possible recipes through iterating the recipes vector.
	for (size_t i = 0; i < ValidRecipes.size(); ++i)
	{
		std::cout << i + 1 << ": " << ValidRecipes[i].DisplayName << "\n";
	}

	int Selection;
	std::cout << "\nChoose recipe: ";
	std::cin >> Selection;
	std::cout << std::endl;

	// input validation - prevent invalid input from breaking logic.
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input!\n";
		return;
	}

	//Convert User input (1) -> vector index (0)
	Selection -= 1;

	//Validate selection is within vector bounds to prevent out-of-range access
	//Ensure the index is not negative and does not exceed the size of the ValidRecipes vector.
	if (Selection >= 0 && Selection < static_cast<int>(ValidRecipes.size()))
	{
		UI.PlayerActionAnimation("Crafting");
		std::cout << std::endl;
		//Attempt to craft the selected recipe.
		//Crafting System Handles:
		// - Checking/removing required materials.
		// - Adding the crafted item to the player's inventory.
		Crafter.CraftRecipe(ValidRecipes[Selection], PlayerCharacter.PlayerInventory);
	}
	else
	{
		std::cout << "Invalid selection!\n";
	}
}
