#include "../header/squares.h"
#include "../header/Piece.h"

Squares::~Squares(){ 
    if (piece != nullptr){
        delete piece; 
    }
}

int Squares::getColumn() const {
    return column;
}

int Squares::getRow() const {
    return row;
}

Piece* Squares::getPiece() const {
    return piece; 
}

void Squares::setPiece(Piece* selectedPiece){
    piece = selectedPiece;
    piece->setRow(row);
    piece->setColumn(column); 
}

Piece* Squares::pickUpPiece(){
    Piece* pickedUpPiece = piece;  
    piece = nullptr; 
    return pickedUpPiece; 
} 

void Squares::removePiece(){
    delete piece;
    piece = nullptr; 
}

bool Squares::isOccupied() const {
    if (getPiece() != nullptr){
        return true;
    }
    return false; 
}
