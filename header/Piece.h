#ifndef PIECE_H
#define PIECE_H

#include "Color.h"
#include <cstdlib>

enum Type{
    Pn,
    Bp,
    Kn,
    Rk,
    Qn,
    Kg
};

class Piece{
    protected:
        Color color;
        Type type;
        int row;
        int column;
    public:
        Piece(Color, Type, int, int);
        const Color getColor();
        const Type getType();
        const int getRow();
        const int getColumn();
        const bool onBoard(int, int);
        const bool isMoving(int, int);
        virtual const bool moveValid(int, int) = 0;//, Chessboard*) = 0;
};

#endif