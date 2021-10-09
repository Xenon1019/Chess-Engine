#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include "pieces.h"

class Board{
private:
    static const int b_size = 8;
    std::unordered_map<int , Piece> b_pieces;
    bool b_whiteToMove;
public:
    static Location indexToLocation(int);
    static int locationToIndex(Location);
    static bool getTileColor(Location);

    void setPiece(Piece*, int);
    Piece* getPieceByLocation(Location);
    explicit Board(int size = 8);
    explicit Board(const std::string&);
    void printBoard();
    static Piece *defaultPiece(int) ;
    void printTile(Location);

};
#endif