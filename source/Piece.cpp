#include "../header/Piece.h"
#include "../header/chessboard.h"
#include "../header/squares.h"
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

Color Piece::getColor() const{
    return color;
}

Type Piece::getType() const{
    return type;
}

int Piece::getRow() const{
    return row;
}

int Piece::getColumn() const{
    return column;
}

void Piece::setRow(int newRow){
    row = newRow;
}

void Piece::setColumn(int newColumn){
    column = newColumn;
}

bool Piece::onBoard(int _row, int _column) const{
    return (_row >= 0 && _row <= 7 && _column >= 0 && _column <= 7);
}

bool Piece::isMoving(int _row, int _column) const{
    return (_row != row || _column != column);
}
bool Piece::attackingAlly(int _row, int _column, const Chessboard* board) const{
    Squares* targetSquare = board->getSquare(_row, _column);
    // checks if the square if occupied by a piece
    if(targetSquare->isOccupied()){
        if (targetSquare->getPiece()->getColor() == color){
            return true;
        }
    }
    return false;
}