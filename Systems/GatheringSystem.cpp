#include "GatheringSystem.h"
#include "../utils/Random.h"

EItemType GatheringSystem::GatherResource()
{
	//The utility function Random::range generates a random integer value between min and max.
	//The value will change depending on the amount of switch cases in the function.
	int Roll = Random::Range(0, 2);

	//When gathering a resource, a random number is generated to determine which type of resource is gathered.
	switch (Roll)
	{
		case 0:
			return EItemType::Wood;
		case 1:
			return EItemType::Stone;
		case 2:
			return EItemType::Iron;
		default:
			return EItemType::Wood; // Default case, should never reach here
	}

}
