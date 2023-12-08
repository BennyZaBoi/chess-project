#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece{
    public:
        Queen(Color, int, int);
        bool moveValid(int, int, const Chessboard*) const;
};

#endif