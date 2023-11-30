#include squares.h

~Squares::Squares(){ 
    delete piece; 
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

Piece Squares::setPiece(Piece* selectedPiece){
    piece = selectedPiece;
}

bool Squares::isOccupied() const {
    if (getPiece() != nullptr){
        return true;
    }
    return false; 
}
