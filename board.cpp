#include "pieces.h"
#include "board.h"
#include "moves.h"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cassert>

const int DefaultCharPrintWidth = 5;


bool Board::getTileColor(Location loc){
    return (loc.first + loc.second) % 2 == 0;
}

Piece* Board::defaultPiece(LocationKey loc) {
    //Have to implement the function using Location....
    if (loc >= b_size * b_size)   throw "Invalid board index.";
    int row{loc / b_size};
    if (row >= 2 && row < 6)    return nullptr;
    int column{loc % b_size};
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

Piece* Board::getPieceByLocation(LocationKey loc){
    auto element = b_pieces.find(loc);
    if (element == b_pieces.end()) return nullptr;
    else return element->second;
}

void Board::setPiece(Piece* piece, LocationKey loc){
    if (b_pieces.count(loc) > 1) throw "The key bucket size is more than 1";
    if (piece == nullptr)
        b_pieces.erase(loc);
    else
        b_pieces.insert_or_assign(loc, piece);
}


void Board::printTile(LocationKey loc){
    char printChar;
    const Piece* piece{getPieceByLocation(loc)};
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
    if (! piece->isWhite())       printChar = tolower(printChar);
    std::cout << std::setw(DefaultCharPrintWidth)
              << printChar;
}

void Board::printBoard(){
    for(int i{};i < b_size;i++)
        std::cout << std::setfill('-') << std::setw(DefaultCharPrintWidth)<< "X";
    std::cout << std::setfill(' ');
    for(int tileIndex{0};tileIndex < b_size * b_size;tileIndex++){
        if(tileIndex % b_size == 0)     std::cout << std::endl;
        printTile(tileIndex);
    }
    std::cout << std::endl;
    for(int i{};i < b_size;i++)
        std::cout << std::setfill('-') << std::setw(DefaultCharPrintWidth)<< "X";
    std::cout << std::endl;
}

/*
---------------------------
 00 01 02 03 04 05 06 07
 08 09 10 11 12 13 14 15
 16 17 18 19 20 21 22 23
 24 25 26 27 28 29 30 31
 32 33 34 35 36 37 38 39
 40 41 42 43 44 45 46 47
 48 49 50 51 52 53 54 55
 56 57 58 59 60 61 62 63
----------------------------
*/
Board::Board(int size)
    :b_whiteToMove{true}, b_kings{60,4}, b_bitboard_black{CLASSICAL_BITBOARD_BLACK}, b_bitboard_white{CLASSICAL_BITBOARD_WHITE}
{
    for(int tileIndex{0};tileIndex < b_size * b_size;tileIndex++){
        setPiece(defaultPiece(tileIndex), tileIndex);
    }
}



Board::Board(const std::string& fenString): b_bitboard_black{0}, b_bitboard_white{0}
{
    bool boardFlag{true};
    bool hasWhiteKing{false}, hasBlackKing{false};
    int rowCount{0}, stringIndex{0}, emptyTileCounter{0};
    char ch;
    int boardIndex{0};
    for (;boardFlag;stringIndex++){
        ch = fenString.at(stringIndex);
        if(ch == '/') {
            rowCount++,assert(boardIndex % 8 == 0);
        }
        else if(isalpha(ch)){
            if (ch == 'K') {
                assert(!hasWhiteKing && "Already has a white king.");
                b_kings.first = boardIndex;
                hasWhiteKing = true;
            }
            else if(ch == 'k') {
                assert(!hasBlackKing && "Already has a black king.");
                b_kings.second = boardIndex;
                hasBlackKing = true;
            }
            (isupper(ch)?b_bitboard_white:b_bitboard_black).setBit(boardIndex);
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
    assert (hasBlackKing && hasWhiteKing);
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

void Board::getMovesForPiece(LocationKey loc) {
    Piece *piece = getPieceByLocation(loc);
    std::vector<Location> vects {{1, 2}, {2, 1}};
    for (auto moveType: piece->getMoveTypes()){
        std::cout << Jumper::getPrelimMoves(loc, vects, b_size).size() << std::endl;
    }

}


