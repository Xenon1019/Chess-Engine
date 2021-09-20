#ifndef PIECES_H
#define PIECES_H

class Piece{
public:
    enum PieceType{
        PAWN,
        ROOK,
        BISHOP,
        KNIGHT,
        QUEEN,
        KING,
        NONE
    };
private:
    PieceType p_type;
public:
    bool isNone();
};
#endif