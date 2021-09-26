#include "pieces.h"
#include "board.h"
#include "moves.h"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cassert>

const int DefaultCharPrintWidth = 5;


Tile::Tile(bool tileColor)
    :t_tileColor{tileColor}, t_piece{nullptr}
    {}

inline bool Tile::isEmpty(){return t_piece == nullptr;}
Piece& Tile::getPiece() const {return *t_piece;}
PieceType Tile::pieceType(){ return t_piece->type();}
void Tile::setColor(bool color){t_tileColor = color;}
void Tile::setPiece(Piece &piece) {t_piece = &piece;}
void Tile::setEmpty(){t_piece = nullptr;}

void Tile::printTile(){
    char printChar;
    if(t_piece == nullptr){
        printChar = '-';
        std::cout << std::setw(DefaultCharPrintWidth)
                  << printChar;
        return;
    }
    else if (t_piece->isKing())    printChar = 'K';
    else if (t_piece->isPawn())    printChar = 'P';
    else if (t_piece->isBishop())  printChar = 'B';
    else if (t_piece->isKnight())  printChar = 'N';
    else if (t_piece->isRook())    printChar = 'R';
    else if (t_piece->isQueen())   printChar = 'Q';
    else throw "How the hell did you get here!?!";
    if (!t_piece->isWhite())       printChar = tolower(printChar);
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
    :b_size{size}, b_numTiles{size * size}, b_tiles{}, b_whiteToMove{true}
{
    b_tiles.resize(b_numTiles);
    for(int tileIndex{0};tileIndex < b_numTiles;tileIndex++){
        b_tiles.at(tileIndex).setColor(tileIndex % 2 == 0);
        b_tiles.at(tileIndex).setPiece(*defaultPiece(tileIndex));
    }
}

void Board::printBoard(){
    for(int i{};i < b_size;i++)
        std::cout << std::setfill('-') << std::setw(DefaultCharPrintWidth)<< "X";
    std::cout << std::setfill(' ');
    for(int tileIndex{0};tileIndex < b_numTiles;tileIndex++){
        if(tileIndex % b_size == 0)     std::cout << std::endl;
        b_tiles.at(tileIndex).printTile();
    }
    std::cout << std::endl;
    for(int i{};i < b_size;i++)
        std::cout << std::setfill('-') << std::setw(DefaultCharPrintWidth)<< "X";
    std::cout << std::endl;
}
Piece* Board::defaultPiece(int boardIndex) const{
    if (b_size != 8)    throw "Board size is not supported.";
    if (boardIndex >= b_numTiles)   throw "Invalid board index.";
    int row{boardIndex / b_size};
    if (row >= 2 && row < 6)    return nullptr;
    int column{boardIndex % b_size};
    bool pieceColor{row >= 6};
    PieceType pieceType;
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
    return new Piece(pieceColor, pieceType);
}

Board::Board(const std::string& fenString)
    :b_size{8}, b_numTiles{64}, b_tiles{}
{
    if (!b_tiles.empty())   throw "Something is wrong!!\n";
    b_tiles.resize(b_numTiles);
    bool boardFlag{true};
    int rowCount{0}, stringIndex{0}, emptyTileCounter{0};
    char ch;
    int boardIndex{0};
    for (;boardFlag;stringIndex++){
        ch = fenString.at(stringIndex);
        if(ch == '/') {
            rowCount++,assert(boardIndex % 8 == 0);
        }
        else if(isalpha(ch)){
            b_tiles.at(boardIndex).setPiece(Piece::pieceFromChar(ch));
            boardIndex++;
        }
        else if(std::isdigit(ch)){
            emptyTileCounter = (int)(ch - '0');
            assert(emptyTileCounter > 0 && emptyTileCounter <= 8);
            for(;emptyTileCounter > 0;boardIndex++,emptyTileCounter--)
                b_tiles.at(boardIndex).setEmpty();
            emptyTileCounter = 0;
        }
        else{
            assert (boardIndex == b_numTiles);
            assert(rowCount == 7);
            boardFlag = false;
        }
    }
    while (fenString.at(stringIndex) == ' ')
        stringIndex++;
    char toMoveFlag = tolower(fenString.at(stringIndex));
    if (toMoveFlag == 'w')
        b_whiteToMove = true;
    else if(toMoveFlag == 'b')
        b_whiteToMove = false;
    else
        throw "Invalid FEN String!!";
    //CASTLING AND EN-PASSANT FLAGS FLAGS AND MOVES YET TO BE IMPLEMENTED.
}

Location Board::getLocation(int tileIndex) {
    //TO BE IMPLEMENTED
    assert (tileIndex >= 0 && tileIndex < 64);
    return Location {5, 5};
}
