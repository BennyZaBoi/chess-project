#include "../header/Pawn.h"
#include "../header/chessboard.h"
#include "../header/squares.h"

Pawn::Pawn(Color _color, int _row, int _column, bool _movesUp) : SpecialPiece(_color, Pn, _row, _column), movesUp(_movesUp){};

bool Pawn::moveValid(int newRow, int newColumn, const Chessboard* board) const{
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
            Squares* targetSquare = board->getSquare(newRow, newColumn);
            // checks that new location is not occupied if moving forward
            if(!(targetSquare->isOccupied())){
                if(rowMovement == 1 && columnMovement == 0 ){
                    return true;
                }
            }
            // checks that pawn is attacking an enemy if trying to move diagonally
            else if(targetSquare->getPiece()->getColor() != color){
                if(rowMovement == 1 && columnMovement == 1){
                    return true;
                }
                else if(rowMovement == 1 && columnMovement == -1){
                    return true;
                }
            }
        }
    }
    return false;
}