//
// Created by xenon on 23/09/21.
//

#ifndef CHESS_ENGINE_MOVES_H
#define CHESS_ENGINE_MOVES_H
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
public:
};
#endif //CHESS_ENGINE_MOVES_H
