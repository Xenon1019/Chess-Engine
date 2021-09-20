#include "pieces.h"

bool Piece::isWhite() const{return p_color;}
bool Piece::isNone()const{ return p_type == PieceType::NONE;}
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