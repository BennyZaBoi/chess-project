#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
    public:
        Knight(Color, int, int);
        bool moveValid(int, int, const Chessboard*) const;
};

#endif