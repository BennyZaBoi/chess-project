#include "../header/Piece.h"
#include <stdexcept>

Piece::Piece(Color _color, Type _type, int _row, int _column){
    color = _color;
    type = _type;
    row = _row;
    column = _column;
    if (row < 0 || row > 7 || column < 0 || column > 7) {
        throw std::invalid_argument("piece isnt on board");
    }
}

const Color Piece::getColor(){
    return color;
}

const Type Piece::getType(){
    return type;
}

const int Piece::getRow(){
    return row;
}

const int Piece::getColumn(){
    return column;
}

const bool Piece::onBoard(int _row, int _column){
    return (_row >= 0 && _row <= 7 && _column >= 0 && _column <= 7);
}

const bool Piece::isMoving(int _row, int _column){
    return (_row != row || _column != column);
}