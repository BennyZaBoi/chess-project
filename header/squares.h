#pragma once 

class Squares {
    private: 
        int row; 
        int column; 
        Piece* piece; 
    public:
        Squares();
        int getRow(); 
        int getColumn(); 
        Piece* getPiece(); 
        Piece setPiece(Piece* piece);
        bool isOccupied(); 
}