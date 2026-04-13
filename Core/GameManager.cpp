#include "GameManager.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void GameManager::Init()
{
	Crafter.InitRecipes();

}

void GameManager::Run()
{

	int Choice = 0;

	const int RefreshRate = 7; 
	int ActionCounter = 0;

	while (true)
	{
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

		if (std::cin.fail())
		{
			std::cin.clear(); // Clear error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << "Invalid input!" << std::endl;
			continue;
		}

		if (Choice == 4)
			break;

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

		ActionCounter++;
		if (ActionCounter >= RefreshRate)
		{
			ActionCounter = 0;
		}
	}
}

void GameManager::HandleGathering()
{
	EItemType Item = Gatherer.GatherResource();
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
