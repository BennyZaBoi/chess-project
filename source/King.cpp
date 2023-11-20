#include "../header/King.h"

King::King(Color _color, int _row, int _column) : SpecialPiece(_color, Kg, _row, _column), captured(false){}

const bool King::isCaptured(){
    return captured;
}

void King::setCaptured(){
    captured = true;
}

const bool King::moveValid(int newRow, int newColumn){//, Chessboard* board){
    // checks if new position is on the board
    if(newRow < 0 || newRow > 7 || newColumn < 0 || newColumn > 7){
        return false;
    }
    // checks for default movement
    if(abs(newRow - row) > 1 || abs(newColumn - column) > 1){
        return false;
    }
    return true;
}