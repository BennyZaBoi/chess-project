#include "../header/SpecialPiece.h"
#include "../header/chessboard.h"
#include "../header/squares.h"

SpecialPiece::SpecialPiece(Color _color, Type _type, int _row, int _column) : Piece(_color, _type, _row, _column), moved(false){}

bool SpecialPiece::hasMoved() const{
    return moved;
}

void SpecialPiece::setMoved(){
    moved = true;
}