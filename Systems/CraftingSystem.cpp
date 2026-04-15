#include "CraftingSystem.h"
#include <iostream>

void CraftingSystem::InitRecipes()
{
	//Initialises the crafting recipes with the reicpe structure defined in Recipe.h.

	//Plank Recipe: 2 Wood -> 1 Plank
	FRecipe Plank;
	Plank.Result = EItemType::Plank;
	Plank.DisplayName = "Plank";
	Plank.Ingredients[EItemType::NormalLog] = 2;

	//push_back adds the recipe to the Recipes vector, which is used to store all available crafting recipes in the game.
	Recipes.push_back(Plank);

	//Iron Bar Recipe: 2 Iron -> 1 iron Bar
	FRecipe IronBar;
	IronBar.Result = EItemType::IronBar;
	IronBar.DisplayName = "Iron Bar";
	IronBar.Ingredients[EItemType::IronOre] = 2;
	Recipes.push_back(IronBar);

	// Axe Recipe: 3 Wood + 2 Iron -> 1 Axe
	FRecipe Axe;
	Axe.Result = EItemType::Axe;
	Axe.DisplayName = "Axe";
	Axe.Ingredients[EItemType::NormalLog] = 3;
	Axe.Ingredients[EItemType::IronBar] = 2;
	Recipes.push_back(Axe);
}

std::vector<FRecipe> CraftingSystem::GetValidRecipes(const Inventory& Inv) const
{
	//Valid is an array of FRecipe structures that will hold the recipes that can be crafted.
	std::vector<FRecipe> Valid;

	//const FRecipe& Recipe is an element of the Recipes vector that will be checked against the player's inventory to match the required ingredients for crafting.
	for (const FRecipe& Recipe : Recipes)
	{
		//Check to see if the player has the required ingredients to craft a recipe.
		if (Inv.HasItems(Recipe.Ingredients))
		{
			//if the check returns true, the recipe is added to the Valid vector.
			Valid.push_back(Recipe);
		}
	}
	//The function returns the Valid vector, which contains all the recipes that the player can currently craft based on their inventory.
	return Valid;
}

bool CraftingSystem::CraftRecipe(const FRecipe& Recipe, Inventory& Inv)
{
	//An inital check to see if the player doesn't posses the required ingredients to craft a recipe and returns false if required ingredients are missing.
	if (!Inv.HasItems(Recipe.Ingredients)) return false;
	
	//If crafting is successful, the ingredients are removed from the inventory via the RemovItems function, removing the specific items and quantities for
	//the recipe being crafted.
	Inv.RemoveItems(Recipe.Ingredients);
	//The crafted item is added to the inventory with the resulting ItemType and a quantity of 1, using the AddItem function.
	Inv.AddItem(Recipe.Result, 1);

	std::cout << "Crafted: " << Recipe.DisplayName << "!\n";

	//The function returns true to indicate that the crafting process was successful.
	return true;
}

