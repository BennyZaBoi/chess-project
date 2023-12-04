#include "../header/Knight.h"

Knight::Knight(Color _color, int _row, int _column) : Piece(_color, Kn, _row, _column){}

const bool Knight::moveValid(int newRow, int newColumn){//, Chessboard* board){
// checks if new position is on the board and that the knight is not moving to the same position
    if(onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){
        int rowMovement = (newRow - row);
        int columnMovement = (newColumn - column);
        // checks to see if new location is not being occupied by an Ally
        //if(check if new location is occupied by ally){
            // checks for default movement
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
        //}
    }
    return false;
}