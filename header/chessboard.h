#pragma once

class Chessboard{
    private: 
        Square* board;
    public: 
        Chessboard();
        ~Chessboard(); 
        bool pathClearStraight(Square* sqrOne, Square* sqrTwo) const;
        bool pathClearDiagonal(Square* sqrOne, Square* sqrTwo) const;
}