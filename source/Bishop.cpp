#include "../header/Bishop.h"
#include "../header/chessboard.h"
#include "../header/squares.h"

Bishop::Bishop(Color _color, int _row, int _column) : Piece(_color, Bp, _row, _column){}

bool Bishop::moveValid(int newRow, int newColumn, const Chessboard* board) const{
    // checks if new position is on the board and that the bishop is not moving to the same position
    if(onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){

        if(attackingAlly(newRow, newColumn, board)){
            return false;
        }

        Squares* currentSquare = board->getSquare(row, column);
        Squares* targetSquare = board->getSquare(newRow, newColumn);

        // checks to make sure the path between the two squares is empty and is a valid diagonal to move
        if(board->pathClearDiagonal(currentSquare, targetSquare)){
            return true;
        }
    }
    return false;
}