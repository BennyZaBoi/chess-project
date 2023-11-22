#ifndef KING_H
#define KING_H

#include "SpecialPiece.h"

class King : public SpecialPiece{
    private:
        bool captured;
    public:
        King(Color, int, int);
        const bool isCaptured();
        void setCaptured();
        const bool moveValid(int, int);//, Chessboard*);
};

#endif