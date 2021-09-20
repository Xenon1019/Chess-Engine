#include "pieces.h"
#include "board.h"
#include <cctype>
#include <iostream>
#include <iomanip>

const int DefaultCharPrintWidth = 5;


Tile::Tile(bool tileColor)
    :t_tileColor{tileColor}, t_piece{*(new Piece{})}
    {}

bool Tile::isEmpty(){return t_piece.isNone();}       
Piece & Tile::getPiece() const {return t_piece;}
PieceType Tile::pieceType(){ return t_piece.type();}
void Tile::setColor(bool color){t_tileColor = color;}
void Tile::setPiece(Piece &piece) {t_piece = piece;}
void Tile::printTile(){
    char printChar;
    if(t_piece.isNone()){
        printChar = '-';
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
    :b_size{size}, b_numTiles{size * size}, b_tiles{}
{
    if (!b_tiles.empty())   throw "Something is wrong!!1\n";
    b_tiles.resize(b_numTiles);
    for(int tileIndex{0};tileIndex < b_numTiles;tileIndex++){
        b_tiles.at(tileIndex).setColor(tileIndex % 2 == 0);
        b_tiles.at(tileIndex).setPiece(defaultPiece(tileIndex));
    }
}

void Board::printBoard(){
    for(int tileIndex{0};tileIndex < b_numTiles;tileIndex++){
        if(tileIndex % b_size == 0)     std::cout << std::endl;
        b_tiles.at(tileIndex).printTile();
    }
}
Piece &Board::defaultPiece(int boardIndex) const{
    if (b_size != 8)    throw "Board size is not supported.";
    if (boardIndex >= b_numTiles)   throw "Invalid board index.";
    int row{boardIndex / b_size};
    if (row >= 2 && row < 6)    return  *(new Piece{});
    int column{boardIndex % b_size};
    bool pieceColor{row >= 6};
    PieceType pieceType{PieceType::NONE};
    if (row == 1 || row == 6)
        pieceType = PieceType::PAWN;
    else if(column == 0 || column == 7)
        pieceType = PieceType::ROOK;
    else if(column == 1 || column == 6)
        pieceType = PieceType::KNIGHT;
    else if(column == 2 || column == 5)
        pieceType = PieceType::BISHOP;
    else if(column == 3)
        pieceType = PieceType::QUEEN;
    else if(column == 4)
        pieceType = PieceType::KING;
    else throw "Something went wrong.";
    return *(new Piece(pieceColor, pieceType));
}

Board::Board(const std::string& fenString)
    :b_size{8}, b_numTiles{64}, b_tiles{}
{}
