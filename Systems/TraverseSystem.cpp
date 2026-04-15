#include "TraverseSystem.h"

TraverseSystem::TraverseSystem()
{
	InitMap();
	SetStartingLocation(ELocationType::Town);
}

void TraverseSystem::InitMap()
{
	Connections.clear();

	Connections[ELocationType::Town] = { ELocationType::Forest, ELocationType::Mine, ELocationType::River };
	Connections[ELocationType::Forest] = { ELocationType::Town };
	Connections[ELocationType::Mine] = { ELocationType::Town };
	Connections[ELocationType::River] = { ELocationType::Town };
}

void TraverseSystem::HandleTravel()
{
	PrintWorldMap();

	std::cout << "\n=== TRAVEL MAP ===\n";
	std::cout << "You are currently in: " << GetLocationName(CurrentLocation) << "\n\n";

	auto it = Connections.find(CurrentLocation);

	if (it == Connections.end() || it->second.empty())
	{
		std::cout << "No available travel paths.\n";
		return;
	}

	const std::vector<ELocationType>& Options = it->second;

	std::cout << "Where would you like to go?\n\n";

	for (size_t i = 0; i < Options.size(); i++)
	{
		std::cout << i + 1 << ". " << GetLocationName(Options[i]) << "\n";
	}

	int Choice;
	std::cin >> Choice;

	if (Choice <= 0 || Choice > Options.size())
	{
		std::cout << "Invalid choice!\n";
		return;
	}

	TravelTo(Options[Choice - 1]);
}

bool TraverseSystem::TravelTo(ELocationType Destination)
{
	if (!CanTravelTo(Destination))
	{
		std::cout << "Cannot travel there!\n";
		return false;
	}

	CurrentLocation = Destination;

	std::cout << "Traveled to: " << GetLocationName(Destination) << "\n";
	return true;
}

ELocationType TraverseSystem::GetCurrentLocation() const
{
	return CurrentLocation;
}

std::string TraverseSystem::GetLocationName(ELocationType Location) const
{
	switch (Location)
	{
	case ELocationType::Town:   return "Town";
	case ELocationType::Forest: return "Forest";
	case ELocationType::Mine:   return "Mine";
	case ELocationType::River:  return "River";
	default: return "Unknown";
	}
}

void TraverseSystem::PrintWorldMap() const
{
	std::cout << "\n=== WORLD MAP ===\n";
	std::cout << "        [Mine]\n";
	std::cout << "          |\n";
	std::cout << "[Forest]--+--[Town]\n";
	std::cout << "          |\n";
	std::cout << "        [River]\n\n";
}

bool TraverseSystem::CanTravelTo(ELocationType Destination) const
{
	auto it = Connections.find(CurrentLocation);

	if (it == Connections.end())
		return false;

	const std::vector<ELocationType>& Neighbours = it->second;

	for (const auto& Loc : Neighbours)
	{
		if (Loc == Destination)
			return true;
	}

	return false;
}

void TraverseSystem::SetStartingLocation(ELocationType StartLocation)
{
	CurrentLocation = StartLocation;
}