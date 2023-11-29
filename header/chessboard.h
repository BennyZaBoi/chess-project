#pragma once

class Chessboard{
    private: 
        Square* board;
    public: 
        Chessboard();
        bool pathClearStraight(Square* rowSqr, Square* clmnSqr);
        bool pathClearDiagonal(Square* rowSqr, Square* clmnSqr);
}