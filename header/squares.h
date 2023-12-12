#pragma once 

#include "Piece.h"
#include <stdexcept>

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