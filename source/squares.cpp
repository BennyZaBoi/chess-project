#include squares.h

Squares::Squares(){
    Piece* piece = nullptr;    
}

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

Piece Squares::setPiece(Piece* piece){

}

bool Squares::isOccupied(){
    if (getPiece() != nullptr){
        return true;
    }
    return false; 
}
