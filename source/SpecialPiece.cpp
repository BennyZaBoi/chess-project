#include "../header/SpecialPiece.h"

SpecialPiece::SpecialPiece(Color _color, Type _type, int _row, int _column) : Piece(_color, _type, _row, _column), moved(false){}

const bool SpecialPiece::hasMoved(){
    return moved;
}

void SpecialPiece::setMoved(){
    moved = true;
}