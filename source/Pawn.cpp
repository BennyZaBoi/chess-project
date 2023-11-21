#include "../header/Pawn.h"

Pawn::Pawn(Color _color, int _row, int _column, bool _movesUp) : SpecialPiece(_color, Pn, _row, _column), movesUp(_movesUp){};

const bool Pawn::moveValid(int newRow, int newColumn){//, Chessboard* board){
    // checks if new postion is on the board and that the pawn is not staying on the spot
    if (onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){
        int direction = 0;
        if(movesUp){
            direction = -1;
        }
        else{
            direction = 1;
        }
        int rowMovement = (newRow - row);
        int columnMovement = (newColumn - column);
        // checks if pawn is moving the correct direction
        if((rowMovement * direction) > 0){
            rowMovement = abs(rowMovement);
            if(rowMovement == 1 && columnMovement == 0 ){// && spot is not occupied){
                return true;
            }
            else if(rowMovement == 1 && columnMovement == 1){// && spot is occupied by enemy
                return true;
            }
            else if(rowMovement == 1 && columnMovement == -1){// spot is occupied by enemy
                return true;
            }
        }
    }
    return false;
}