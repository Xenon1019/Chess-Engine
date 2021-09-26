#ifndef PIECES_H
#define PIECES_H

#include <cctype>
//#include "moves.h"
#include <cassert>
#include <array>
#include <vector>

typedef std::array<int, 2> Location;
enum class PieceType{
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING,
};
class BasicPiece{
private:
    Location p_location;
    bool p_color;
public:
    BasicPiece(int row, int column, bool color)
        : p_location{row, column}, p_color{color}
    {}
    virtual std::vector <Location> getMoveSquares() = 0;
};

class BasicSlider:public BasicPiece{
public:
    enum Directions{
        N, E, W, S,
        NE, SE, SW, NW
    };
private:
    Directions s_moveDir;
    short s_moveSize;
public:
    //MoveType getMoveType();
};

class Piece{
private:
    PieceType p_type;
    bool p_color;  //true for white          false for black
public:
    explicit Piece(bool color, PieceType type);
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