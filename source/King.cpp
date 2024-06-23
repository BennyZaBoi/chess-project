#include "../header/King.h"
#include "../header/chessboard.h"
#include "../header/squares.h"

King::King(Color _color, int _row, int _column) : SpecialPiece(_color, Kg, _row, _column){}

bool King::moveValid(int newRow, int newColumn, const Chessboard* board) const{
    // checks if new position is on the board and that king is not moving to the same position
    if(onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){

        if(attackingAlly(newRow, newColumn, board)){
            return false;
        }
        
        // checks for default movement
        if(abs(newRow-row) <= 1 && abs(newColumn - column) <= 1){
            return true;
        }
    }
    return false;
}