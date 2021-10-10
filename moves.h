// Created by xenon on 23/09/21.
#ifndef CHESS_ENGINE_MOVES_H
#define CHESS_ENGINE_MOVES_H
#include "pieces.h"
#include "board.h"
#include <array>
typedef std::pair<int, int> Location;
enum class MoveType{
    SLIDE,
    JUMP,
    PUSH,
    CASTLE,
    MIXED,
    SPECIAL
};

class Move{
private:
    MoveType m_moveType;
    Location m_from;
    Location m_to;
    PieceType m_piece;
public:

};
#endif //CHESS_ENGINE_MOVES_H
