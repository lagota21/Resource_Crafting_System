#include "Random.h"
#include <cstdlib>

int Random::Range(int min, int max)
{
	return min + (std::rand() % (max - min + 1));
}
