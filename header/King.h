#ifndef KING_H
#define KING_H

#include "SpecialPiece.h"

class King : public SpecialPiece{
    public:
        King(Color, int, int);
        bool moveValid(int, int, const Chessboard*) const;
};

#endif