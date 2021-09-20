#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "pieces.h"

class Tile{
private:
    Piece &t_piece;
    bool t_tileColor;
public:
    explicit Tile(bool tileColor = true);
    bool isEmpty();      
    Piece & getPiece() const;
    void setColor(bool);
    void setPiece(Piece &);
    PieceType pieceType();
    void printTile();

};

class Board{
private:
    const int b_size;
    const int b_numTiles;
    std::vector <Tile> b_tiles;
public:
    Tile & getTileByLocation(int, int);
    explicit Board(int size = 8);
    explicit Board(const std::string&);
    void printBoard();
    Piece &defaultPiece(int) const;
};
#endif