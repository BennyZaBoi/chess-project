#pragma once

#include "squares.h"

class Chessboard{
    private: 
        Squares* **board;
    public: 
        Chessboard();
        ~Chessboard(); 
        bool pathClearStraight(Squares* sqrOne, Squares* sqrTwo) const;
        bool pathClearDiagonal(Squares* sqrOne, Squares* sqrTwo) const;
        Squares* getSquare(int row, int column) const; 
};