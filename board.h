#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include "pieces.h"
#define CLASSICAL_BITBOARD_BLACK 0b\
11111111\
11111111\
00000000\
00000000\
00000000\
00000000\
00000000\
00000000

#define CLASSICAL_BITBOARD_WHITE 0b\
00000000\
00000000\
00000000\
00000000\
00000000\
00000000\
11111111\
11111111

class Board{
private:
    static const int b_size = 8;
    Bitboard b_bitboard_white;
    Bitboard b_bitboard_black;
    std::unordered_map<LocationKey , Piece*> b_pieces;   //Change to std::map and see the changes in efficiency.
    bool b_whiteToMove;
    std::pair<LocationKey , LocationKey> b_kings;
public:
    ~Board(){
        for (auto piece: b_pieces) delete piece.second;
    }
    static bool getTileColor(Location);
    static Piece *defaultPiece(LocationKey) ;

    explicit Board(int size = 8);
    explicit Board(const std::string&);

    void setPiece(Piece*, LocationKey);
    Piece* getPieceByLocation(LocationKey);
    void printTile(LocationKey);
    void printBoard();

    void getMovesForPiece(LocationKey);

};
#endif