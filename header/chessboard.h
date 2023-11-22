#pragma once

class Chessboard{
    private: 
        auto board = new Square*[8][8];
    public: 
        bool pathClearStraight(Square* rowSqr, Square* clmnSqr);
        bool pathClearDiagonal(Square* rowSqr, Square* clmnSqr);
        void displayBoard();  
}