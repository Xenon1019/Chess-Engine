#include "pieces.h"

bool Piece::isWhite(){return p_color;}
bool Piece::isNone(){ return p_type == PieceType::NONE;}
bool Piece::isBishop(){return p_type == PieceType::BISHOP;}
bool Piece::isRook(){return p_type == PieceType::ROOK;}
bool Piece::isQueen(){return p_type == PieceType::QUEEN;}
bool Piece::isKnight(){return p_type == PieceType::KNIGHT;}
bool Piece::isKing(){return p_type == PieceType::KING;}
bool Piece::isPawn(){return p_type == PieceType::PAWN;}
PieceType Piece::type(){return p_type;}
Piece::Piece(bool color, PieceType type)
    :p_color{color}, p_type{type}
    {}