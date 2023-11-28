#ifndef PAWN_H
#define PAWN_H

#include "SpecialPiece.h"

class Pawn : public SpecialPiece{
    private:
        bool movesUp;
    public:
        Pawn(Color, int, int, bool);
        const bool moveValid(int, int);//, Chessboard*);
};

#endif