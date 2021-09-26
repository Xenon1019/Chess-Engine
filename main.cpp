#include "board.h"
#include <string>
#include <iostream>

int main(){
    Board board{"8/8/8/8/8/8/8/K6Q w"};
    board.printBoard();
    return 0;
}