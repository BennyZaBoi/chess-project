#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece{
    public:
        Rook(Color, int, int);
        bool moveValid(int, int, const Chessboard*) const;
};

#endif