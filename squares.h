#pragma once 

class Squares {
    private: 
        int row; 
        int column; 
        Piece* piece; 
    public:
        int getRow(); 
        int getColumn(); 
        Piece* getPiece(); 
        Piece setPiece(Piece*);
        bool isOccupied(); 
}