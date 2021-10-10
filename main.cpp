#include "board.h"
#include <string>
#include <iostream>

int main(){
    Board board{"4k3/7n/8/8/8/8/8/K7 w"};
    board.printBoard();
    board.getMovesForPiece(15);
    return 0;
}