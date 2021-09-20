#ifndef BOARD_H
#define BOARD_H
#include <array>

class Tile{
private:
    Piece t_piece;
public:
    bool isEmpty();      
    Piece &getPiece();
};

class Board{
private:
    const int b_size;
    const int b_numTiles{b_size * b_size};
    std::array <Tile,64> b_board;
public:
    ;
};
#endif