#ifndef PIECES_H
#define PIECES_H

#include <cctype>
#include <cassert>

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
    explicit Piece(bool color = true, PieceType type = PieceType::NONE);
    bool isWhite() const;
    bool isNone()const;
    bool isPawn()const;
    bool isBishop()const;
    bool isRook()const;
    bool isKing()const;
    bool isQueen()const;
    bool isKnight()const;
    PieceType type()const;
    static Piece &pieceFromChar(char ch);
};
#endif