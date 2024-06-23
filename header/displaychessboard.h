#ifndef CHESSBOARDDISPLAY_H
#define CHESSBOARDDISPLAY_H

#include "chessboard.h"

class ChessboardDisplay{
    private:
    public:
        ChessboardDisplay(){}
        ~ChessboardDisplay() = default;
        bool displayTrue(Chessboard* board);
        void displayBoard(Chessboard* board);
};

#endif