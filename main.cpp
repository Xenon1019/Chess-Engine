#include <iostream>
#include "board.h"

int main(){
    Board board;
    std::cout << board.getTileByLocation(1, 1).getPiece().isRook();
    board.printBoard();
    return 0;
}