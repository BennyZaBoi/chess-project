#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
    public:
        Bishop(Color, int, int);
        bool moveValid(int, int, const Chessboard*) const;
};

#endif