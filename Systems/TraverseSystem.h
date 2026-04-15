#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "../Data/LocationTypes.h"

class TraverseSystem
{
public:
    TraverseSystem();

    // Core
    void InitMap();
    void HandleTravel();

    bool TravelTo(ELocationType Destination);

    ELocationType GetCurrentLocation() const;
    std::string GetLocationName(ELocationType Location) const;

    // UI
    void PrintWorldMap() const;

private:
    ELocationType CurrentLocation;

    std::map<ELocationType, std::vector<ELocationType>> Connections;

private:
    bool CanTravelTo(ELocationType Destination) const;
    void SetStartingLocation(ELocationType StartLocation);
};