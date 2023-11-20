#include "../header/Pawn.h"

Pawn::Pawn(Color _color, int _row, int _column, bool _movesUp) : SpecialPiece(_color, Pn, _row, _column), movesUp(_movesUp){};

const bool Pawn::moveValid(int newRow, int newColumn){//, Chessboard* board){
    //checks if new position is on the board
    if(newRow < 0 || newRow > 7 || newColumn < 0 || newColumn > 7){
        return false;
    }
    //makes sure pawn is not moving sideways
    if(newColumn != column){
        return false;
    }
    int rowMovement = (newRow - row);
    //makes sure pawn is moving in the correct direction
    if(movesUp){
        if(rowMovement > 0)
        {
            return false;
        }
    }
    else
    {
        if(rowMovement < 0)
        {
            return false;
        }
    }
    //checks to make sure it at max moved 2 squares
    if(abs(rowMovement) > 2){
        return false;
    }
    //checks to make sure that if it is moving 2 squares that it also has not moved yet
    if(moved && abs(rowMovement) > 1)
    {
        return false;
    }
    return true;
}