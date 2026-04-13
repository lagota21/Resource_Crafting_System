#pragma once
#include "../Data/Recipe.h"
#include "../Systems/Inventory.h"
#include <vector>

class CraftingSystem
{
public:

	void InitRecipes();

	std::vector<FRecipe> GetValidRecipes(const Inventory& Inv) const;

	bool CraftRecipe(const FRecipe& Recipe,Inventory& Inv);

private:
	std::vector<FRecipe> Recipes;

};