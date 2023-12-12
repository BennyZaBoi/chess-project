#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"
//#define NDEBUG
#include <assert.h>

class Squares {
    private:
        int row;
        int column;
        Piece* piece;
    public:
        Squares()
            :row(-1),
             column(-1),
             piece(nullptr)
            {
            }


        Squares(int row, int column, Piece* piece)
            :row(row),
             column(column),
             piece(piece)
            {
                assert(row >= 0 && row <= 7 && column >= 0 && column <= 7 && "Error: Invalid Inputs For Square");
            }


        ~Squares();
        int getRow() const; 
        int getColumn() const; 
        Piece* getPiece() const; 
        void setPiece(Piece* piece);
        Piece* pickUpPiece(); 
        void removePiece(); 
        bool isOccupied() const; 
};

#endif
