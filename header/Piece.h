#ifndef PIECE_H
#define PIECE_H


#include "Color.h"
#include <cstdlib>


// forward declarations
class Chessboard;
class Squares;


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
        virtual ~Piece() = default;
        Color getColor() const;
        Type getType() const;
        int getRow() const;
        int getColumn() const;
        void setRow(int);
        void setColumn(int);
        bool onBoard(int, int) const;
        bool isMoving(int, int) const;
        bool attackingAlly(int, int, const Chessboard*) const;
        virtual bool moveValid(int, int, const Chessboard*) const = 0;
};


#endif
