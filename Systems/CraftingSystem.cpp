#include "CraftingSystem.h"
#include <iostream>

void CraftingSystem::InitRecipes()
{
	//Plank Recipe: 2 Wood -> 1 Plank
	FRecipe Plank;
	Plank.Result = EItemType::Plank;
	Plank.DisplayName = "Plank";
	Plank.Ingredients[EItemType::Wood] = 2;
	Recipes.push_back(Plank);

	// Axe Recipe: 3 Wood + 2 Iron -> 1 Axe
	FRecipe Axe;
	Axe.Result = EItemType::Axe;
	Axe.DisplayName = "Axe";
	Axe.Ingredients[EItemType::Wood] = 3;
	Axe.Ingredients[EItemType::Iron] = 2;
	Recipes.push_back(Axe);
}

std::vector<FRecipe> CraftingSystem::GetValidRecipes(const Inventory& Inv) const
{
	std::vector<FRecipe> Valid;

	for (const FRecipe& Recipe : Recipes)
	{
		if (Inv.HasItems(Recipe.Ingredients))
		{
			Valid.push_back(Recipe);
		}
	}
	return Valid;
}

bool CraftingSystem::CraftRecipe(const FRecipe& Recipe, Inventory& Inv)
{
	if (!Inv.HasItems(Recipe.Ingredients)) return false;
	
	Inv.RemoveItems(Recipe.Ingredients);
	Inv.AddItem(Recipe.Result, 1);

	return true;
}

