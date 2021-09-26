#include "pieces.h"

bool Piece::isWhite() const{return p_color;}
bool Piece::isBishop()const{return p_type == PieceType::BISHOP;}
bool Piece::isRook()const{return p_type == PieceType::ROOK;}
bool Piece::isQueen()const{return p_type == PieceType::QUEEN;}
bool Piece::isKnight()const{return p_type == PieceType::KNIGHT;}
bool Piece::isKing()const{return p_type == PieceType::KING;}
bool Piece::isPawn()const{return p_type == PieceType::PAWN;}
PieceType Piece::type()const{return p_type;}
Piece::Piece(bool color, PieceType type)
    :p_color{color}, p_type{type}
    {}

Piece &Piece::pieceFromChar(char ch){
    assert (isalpha(ch));
    bool color = isupper(ch);
    PieceType type;
    switch (ch) {
        case 'K':
        case 'k':
            type = PieceType::KING;
            break;
        case 'Q':
        case 'q':
            type = PieceType::QUEEN;
            break;
        case 'R':
        case 'r':
            type = PieceType::ROOK;
            break;
        case 'N':
        case 'n':
            type = PieceType::KNIGHT;
            break;
        case 'B':
        case 'b':
            type = PieceType::BISHOP;
            break;
        case 'P':
        case 'p':
            type = PieceType::PAWN;
            break;
        default:
            throw "Something went wrong!!!";
    }
    return *(new Piece(color, type));
}