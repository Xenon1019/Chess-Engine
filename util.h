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

Location keyToLocation(LocationKey, short boardSize = 8);
LocationKey locationToKey(Location, short boardSize = 8);
bool inBoard(Location, short);
std::array<Location , 4> mirrorVectors4(Location);
Location addVector(Location, Location);

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
