#include "GameManager.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void GameManager::Init()
{
	// Initialize crafting recipes using the Recipe struct defined in Recipe.h.
	//Defines required amounts, display names, and the resulting item for each recipe.
	Crafter.InitRecipes();

}

void GameManager::Run()
{
	// The choice variable is used to store the action selected by the player from the interaction menu.
	int Choice = 0;

	// The RefreshRate constant determines how many player actions occur before the console is cleared and the menu is refreshed,
	//avoids clogging the console with repeated actions and keeps the interface clean and user-friendly with refreshing the menu.
	const int RefreshRate = 7; 
	//Keeps track of actions taken by the player.
	int ActionCounter = 0;

	// The main game loop continues until the player chooses to exit (Choice == 4).
	while (true)
	{
		//The menu is displayed always and refreshes when the ActionCounter hits the RefreshRate value.
		if (ActionCounter == 0)
		{
			system("cls");

			std::cout << "\n=== Resource Gathering & Crafting System ===\n";

			std::cout <<
				"\n1. Gather Resource\n"
				<< "2. Craft Item\n"
				<< "3. View Inventory\n"
				<< "4. Exit\n";
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

		//Exit condition to break the loop and end the game.
		if (Choice == 4)
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
			PlayerInventory.Print();
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
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
	//The random resource gathered is stored in the Item variable.
	EItemType Item = Gatherer.GatherResource();
	//
	PlayerInventory.AddItem(Item, 1);

	std::cout << "Gathered: " << ItemToString(Item) << std::endl;
}

void GameManager::HandleCrafting()
{
	auto ValidRecipes = Crafter.GetValidRecipes(PlayerInventory);

	if (ValidRecipes.empty())
	{
		std::cout << "No valid recipes to craft!" << std::endl;
		return;
	}

	std::cout << "\nAvailable Recipes:\n";

	for (size_t i = 0; i < ValidRecipes.size(); ++i)
	{
		std::cout << i + 1 << ": " << ValidRecipes[i].DisplayName << "\n";
	}

	int Selection;
	std::cin >> Selection;
	Selection -= 1; // Adjust for 0-based index

	if (Selection >= 0 && Selection < ValidRecipes.size())
	{
		Crafter.CraftRecipe(ValidRecipes[Selection], PlayerInventory);
	}
	else
		{
		std::cout << "Invalid selection!" << std::endl;
	}
}
