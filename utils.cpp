//
// Created by xenon on 10/10/21.
//
#include "util.h"

Location keyToLocation(LocationKey loc, short boardSize){
    return Location {loc / boardSize + 1, loc % boardSize + 1};
}

LocationKey locationToKey(Location loc, short boardSize){
    return boardSize * (loc.first - 1) + loc.second - 1;
}
bool inBoard(Location loc, short boardSize){
    if (loc.first < 1 || loc.second < 1)
        return false;
    if (loc.first > boardSize || loc.second > boardSize)
        return false;
    return true;
}
std::array<Location , 4> mirrorVectors4(Location vect){
    std::array<Location , 4> mirroredLocations{};
    mirroredLocations[0] = vect;
    mirroredLocations[1] = Location {-vect.second, vect.first};
    mirroredLocations[2] = Location {-vect.first, -vect.second};
    mirroredLocations[4] = Location {vect.second, -vect.first};
    return mirroredLocations;
}
Location addVector(Location loc1, Location loc2){
    return  Location {loc1.first + loc2.first, loc1.second + loc2.second};
}