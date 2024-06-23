#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "squares.h"

class Chessboard{
    private:
        Squares* **board;
    public:
        Chessboard();
        ~Chessboard();
        void initializeChessboard(Color playerOneColor, Color playerTwoColor);
        bool pathClearStraight(Squares* sqrOne, Squares* sqrTwo) const;
        bool pathClearDiagonal(Squares* sqrOne, Squares* sqrTwo) const;
        Squares* getSquare(int row, int column) const;
};

#endif