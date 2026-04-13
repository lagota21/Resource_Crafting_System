#include "GatheringSystem.h"
#include "../utils/Random.h"

EItemType GatheringSystem::GatherResource()
{
	int Roll = Random::Range(0, 2);

	switch (Roll)
	{
		case 0:
			return EItemType::Wood;
		case 1:
			return EItemType::Stone;
		case 2:
			return EItemType::Iron;
	}

	return EItemType::Wood; // Default case, should never reach here
}
