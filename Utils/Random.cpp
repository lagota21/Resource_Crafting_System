#include "Random.h"
#include <random>

int Random::Range(int min, int max)
{
	static std::mt19937 Gen(std::random_device{}()); // Initialize random number generator with a random seed
	std::uniform_int_distribution<> Dist(min, max); // Create a uniform distribution in the range [min, max]
	return Dist(Gen); // Generate and return a random number from the distribution
}
