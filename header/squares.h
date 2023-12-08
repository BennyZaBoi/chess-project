#pragma once 

#include "Piece.h"
#include "SpecialPiece.h"
#include "Rook.h"
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
                if (row < 0 || row > 7 || column < 0 || column > 7){
                    throw std::invalid_argument("piece isnt on board"); 
                }
            }

        ~Squares();
        int getRow() const; 
        int getColumn() const; 
        Piece* getPiece() const; 
        void setPiece(Piece* piece);
        bool isOccupied() const; 
};