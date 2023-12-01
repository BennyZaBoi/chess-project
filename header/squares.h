#pragma once 

class Squares {
    private: 
        int row; 
        int column; 
        Piece* piece; 
    public:
        Squares()
            :row(-1),
             column(-1),
             piece(nullptr),
            {
            }

        Squares(int row, int column, Piece* piece)
            :row(row),
             column(column), 
             piece(piece)
            {
            }

        int getRow() const; 
        int getColumn() const; 
        Piece* getPiece() const; 
        void setPiece(Piece* piece);
        bool isOccupied() const; 
}