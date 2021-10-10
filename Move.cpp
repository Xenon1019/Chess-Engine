//
// Created by xenon on 23/09/21.
//
#include "moves.h"

std::vector<Jumper> Jumper::getPrelimMoves(LocationKey loc, const std::vector<Location> &vects, short boardSize = 8) {
    std::vector<Jumper> moves{};
    for (auto vect:vects){
        auto mirroredVects{mirrorVectors4(vect)};
        for(Location& mirrorVect:mirroredVects){
            mirrorVect = addVector(mirrorVect, keyToLocation(loc));
            if (inBoard(mirrorVect, boardSize))
                moves.push_back(Jumper(loc, locationToKey(mirrorVect,boardSize)));
        }
    }
    return moves;
}
