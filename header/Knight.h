#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
    public:
        Knight(Color, int, int);
        const bool moveValid(int, int);//, Chessboard*);
};

#endif