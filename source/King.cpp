#include "../header/King.h"

King::King(Color _color, int _row, int _column) : SpecialPiece(_color, Kg, _row, _column), captured(false){}

const bool King::isCaptured(){
    return captured;
}

void King::setCaptured(){
    captured = true;
}

const bool King::moveValid(int newRow, int newColumn){//, Chessboard* board){
    // checks if new position is on the board and that king is not moving to the same position
    if(onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){
        // checks to see if new location is not being occupied by an Ally
        //if(check if new location is occupied by ally){
            // checks for default movement
            if(abs(newRow-row) <= 1 && abs(newColumn - column) <= 1){
                return true;
            }
        //}
    }
    return false;
}