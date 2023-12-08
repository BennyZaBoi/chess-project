#pragma once
#include "chessboard.h" 

class ChessboardDisplay{
    private:
    public: 
        ChessboardDisplay(){} 
        ~ChessboardDisplay(); 
        bool displayTrue(Chessboard* board);
        void displayBoard(Chessboard* board); 
};