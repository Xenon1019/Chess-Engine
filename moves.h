// Created by xenon on 23/09/21.
#ifndef CHESS_ENGINE_MOVES_H
#define CHESS_ENGINE_MOVES_H
#include <vector>
#include "util.h"
enum class MoveType{
    SLIDE,
    JUMP,
    PUSH,
    PROMOTE,
    CASTLE,
    MIXED
};
class Move{
private:
    LocationKey m_from;
    LocationKey m_to;
public:
    Move(LocationKey from, LocationKey to):m_from{from}, m_to{to} {}
    //static std::vector <Move> getMoves(MoveType, LocationKey);
    virtual MoveType type() = 0;
};
class Slider: public Move{
public:
    Slider(LocationKey from, LocationKey to): Move{from, to} {}
    MoveType type() override{return MoveType::SLIDE;}
};

class Jumper: public Move{
public:
    Jumper(LocationKey from, LocationKey to): Move{from, to} {}
    MoveType type() override{ return MoveType::JUMP;}
    static std::vector<Jumper> getPrelimMoves(LocationKey loc, const std::vector<Location> &vects, int boardSize);
};

class Pusher: public Move{
public:

};
#endif //CHESS_ENGINE_MOVES_H
