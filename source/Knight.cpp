#include "../header/Knight.h"
#include "../header/chessboard.h"
#include "../header/squares.h"

Knight::Knight(Color _color, int _row, int _column) : Piece(_color, Kn, _row, _column){}

bool Knight::moveValid(int newRow, int newColumn, const Chessboard* board) const {
    // checks if new position is on the board and that the knight is not moving to the same position
    if(onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){

        if(attackingAlly(newRow, newColumn, board)){
            return false;
        }

        int rowMovement = (newRow - row);
        int columnMovement = (newColumn - column);
        //checks for 8 possible variations of movement
        if(rowMovement == 1 && columnMovement == 2){
            return true;
        }
        else if(rowMovement == 1 && columnMovement == -2){
            return true;
        }
        else if(rowMovement == -1 && columnMovement == 2){
            return true;
        }
        else if(rowMovement == -1 && columnMovement == -2){
            return true;
        }
        else if(rowMovement == 2 && columnMovement == 1){
            return true;
        }
        else if(rowMovement == 2 && columnMovement == -1){
            return true;
        }
        else if(rowMovement == -2 && columnMovement == 1){
            return true;
        }
        else if(rowMovement == -2 && columnMovement == -1){
            return true;
        }
    }
    return false;
}