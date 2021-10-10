//
// Created by xenon on 10/10/21.
//

#ifndef CHESS_ENGINE_UTIL_H
#define CHESS_ENGINE_UTIL_H
#include <cstdint>
#include <utility>
#include <array>
typedef std::pair<int, int> Location;
typedef unsigned short LocationKey;
typedef std::uint_fast64_t Bit;


Location keyToLocation(LocationKey loc, short boardSize = 8){
    return Location {loc / boardSize + 1, loc % boardSize + 1};
}

LocationKey locationToKey(Location loc, short boardSize = 8){
    return boardSize * (loc.first - 1) + loc.second - 1;
}
bool inBoard(Location loc, int boardSize){
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
class Bitboard{
private:
    Bit b_board;
public:
    Bitboard operator+(const Bitboard& bitboard2) const{
        return Bitboard(bitboard2.b_board | this->b_board);
    }
    Bitboard(Bit bitboard):b_board{bitboard}{}
    void setBit(LocationKey loc){
        Bit tempBit{1};
        tempBit <<= loc;
        b_board |= tempBit;
    }
    void setNull(LocationKey loc){
        Bit tempBit{1};
        tempBit <<= loc;
        b_board &= ~tempBit;
    }
    bool getVal(LocationKey loc) const{
        Bit tempBit{1};
        tempBit <<= loc;
        return tempBit | b_board;
    }
};
#endif //CHESS_ENGINE_UTIL_H
