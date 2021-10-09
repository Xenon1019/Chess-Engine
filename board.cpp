#include "pieces.h"
#include "board.h"
#include "moves.h"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cassert>

const int DefaultCharPrintWidth = 5;


int Board::locationToIndex(Location loc){
    return (loc.first - 1) * 8 + loc.second - 1;
}
Location Board::indexToLocation(int index) {
    return Location{index / b_size + 1, index % b_size + 1};
}
bool Board::getTileColor(Location loc){
    return (loc.first + loc.second) % 2 == 0;
}


void Board::setPiece(Piece* piece, int index){
    if (b_pieces.count(index) > 1) throw "The key bucket size is more than 1";
    if (piece == nullptr)
        b_pieces.erase(index);
    else
        b_pieces.insert_or_assign(index, *piece);
}


void Board::printTile(Location loc){
    char printChar;
    const Piece* piece{getPieceByLocation((loc))};
    if(piece == nullptr){
        printChar = '-';
        std::cout << std::setw(DefaultCharPrintWidth)
                  << printChar;
        return;
    }
    else if (piece->isKing())    printChar = 'K';
    else if (piece->isPawn())    printChar = 'P';
    else if (piece->isBishop())  printChar = 'B';
    else if (piece->isKnight())  printChar = 'N';
    else if (piece->isRook())    printChar = 'R';
    else if (piece->isQueen())   printChar = 'Q';
    else throw "How the hell did you get here!?!";
    if (!piece->isWhite())       printChar = tolower(printChar);
    std::cout << std::setw(DefaultCharPrintWidth)
              << printChar;
}




Board::Board(int size)
    :b_whiteToMove{true}
{
    for(int tileIndex{0};tileIndex < b_size * b_size;tileIndex++){
        setPiece(defaultPiece(tileIndex), tileIndex);
    }
}

void Board::printBoard(){
    for(int i{};i < b_size;i++)
        std::cout << std::setfill('-') << std::setw(DefaultCharPrintWidth)<< "X";
    std::cout << std::setfill(' ');
    for(int tileIndex{0};tileIndex < b_size * b_size;tileIndex++){
        if(tileIndex % b_size == 0)     std::cout << std::endl;
        printTile(indexToLocation(tileIndex));
    }
    std::cout << std::endl;
    for(int i{};i < b_size;i++)
        std::cout << std::setfill('-') << std::setw(DefaultCharPrintWidth)<< "X";
    std::cout << std::endl;
}
Piece* Board::defaultPiece(int boardIndex) {
    //Have to implement the function using Location type...
    if (boardIndex >= b_size * b_size)   throw "Invalid board index.";
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
{
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
            setPiece(&Piece::pieceFromChar(ch), boardIndex);
            boardIndex++;
        }
        else if(std::isdigit(ch)){
            emptyTileCounter = (int)(ch - '0');
            assert(emptyTileCounter > 0 && emptyTileCounter <= 8);
            for(;emptyTileCounter > 0;boardIndex++,emptyTileCounter--)
                b_pieces.erase(boardIndex);
            emptyTileCounter = 0;
        }
        else{
            assert (boardIndex == b_size * b_size);
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



Piece* Board::getPieceByLocation(Location loc){
    auto element = b_pieces.find(locationToIndex(loc));
    if (element == b_pieces.end()) return nullptr;
    else return &element->second;
}
