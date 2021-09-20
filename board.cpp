#include "pieces.h"
#include "board.h"


bool Tile::isEmpty(){return t_piece.isNone();}       
Piece &Tile::getPiece(){return t_piece;}

