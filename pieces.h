#ifndef PIECES_H
#define PIECES_H

#include <cctype>
#include <utility>
//#include "moves.h"
#include <cassert>
#include <array>
#include <vector>

typedef std::pair<int, int> Location;
enum class PieceType{
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING,
};
/*
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
*/
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
class Pawn: public Piece{
private:
    const PieceType p_type = PieceType::PAWN;
public:
};
class Bishop: public Piece{
private:
    const PieceType p_type = PieceType::BISHOP;
public:
};
class Knight: public Piece{
private:
    const PieceType p_type = PieceType::KNIGHT;
public:
};
class King: public Piece{
private:
    bool hasMoved;
    const PieceType p_type = PieceType::KING;
public:
};
class Queen: public Piece{
private:
    const PieceType p_type = PieceType::QUEEN;
public:
};
class Rook: public Piece{
private:
    bool hasMoved;
    const PieceType p_type = PieceType::ROOK;
public:
};


#endif