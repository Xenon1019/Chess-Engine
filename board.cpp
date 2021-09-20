#include "pieces.h"
#include "board.h"
#include <cctype>
#include <iostream>
#include <iomanip>
const int DefaultCharPrintWidth = 5;


Tile::Tile(bool tileColor)
    :t_tileColor{tileColor}, t_piece{*(new Piece{})}
    {}
Tile::~Tile(){delete &t_piece;}

bool Tile::isEmpty(){return t_piece.isNone();}       
Piece &Tile::getPiece(){return t_piece;}
PieceType Tile::pieceType(){ return t_piece.type();}
void Tile::setColor(bool color){t_tileColor = color;}
void Tile::setPiece(Piece &piece){
    Piece* temp{&t_piece};
    t_piece = piece;
    delete temp;
}
void Tile::printTile(void){
    char printChar;
    if(t_piece.isNone()){
        if(t_tileColor)           printChar = 'W';
        else                      printChar = 'B';
    }
    else if (t_piece.isKing())    printChar = 'K';
    else if (t_piece.isPawn())    printChar = 'P';
    else if (t_piece.isBishop())  printChar = 'B';
    else if (t_piece.isKnight())  printChar = 'N';
    else if (t_piece.isRook())    printChar = 'R';
    else if (t_piece.isQueen())   printChar = 'Q';
    else throw "How the hell did you get here!?!";
    if (!t_piece.isWhite())       printChar = tolower(printChar);
    std::cout << std::setw(DefaultCharPrintWidth)
              << printChar;
}



Tile &Board::getTileByLocation(int row, int column){
    if (row < 1 || row > b_size)    throw "Row number exceeds the board.";
    if (column < 1 || column > b_size)    throw "Column number exceeds the board.";
    row--;column--;
    int index{b_size * row + column};
    return b_tiles.at(index);
}
Board::Board(int size)
    :b_size{size}, b_numTiles{size * size}, b_tiles(b_numTiles, Tile())
{
    for(int tileIndex{};tileIndex < b_numTiles;tileIndex++){
        b_tiles.at(tileIndex).setColor(tileIndex % 2 == 0);
//        b_tiles.at(tileIndex).setPiece();
    }
}

void Board::printBoard(void){
    for(int tileIndex{};tileIndex < b_numTiles;tileIndex++){
        if(tileIndex % b_size == 0)     std::cout << std::endl;
        b_tiles.at(tileIndex).printTile();
    }
}