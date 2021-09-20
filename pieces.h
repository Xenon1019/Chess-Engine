#ifndef PIECES_H
#define PIECES_H

enum class PieceType{
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING,
    NONE
};

class Piece{    
private:
    PieceType p_type;
    bool p_color;  //true for white          false for black
public:
    Piece(bool color = true, PieceType type = PieceType::NONE);
    bool isWhite();
    bool isNone();
    bool isPawn();
    bool isBishop();
    bool isRook();
    bool isKing();
    bool isQueen();
    bool isKnight();
    PieceType type();
};
#endif