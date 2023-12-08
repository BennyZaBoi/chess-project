#include "../header/Rook.h"
#include "../header/chessboard.h"
#include "../header/squares.h"

Rook::Rook(Color _color, int _row, int _column) : Piece(_color, Rk, _row, _column){}

bool Rook::moveValid(int newRow, int newColumn, const Chessboard* board) const{
    // checks if new position is on the board and that the queen is not moving to the same position
    if(onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){

        if(attackingAlly(newRow, newColumn, board)){
            return false;
        }

        Squares* currentSquare = board->getSquare(row, column);
        Squares* targetSquare = board->getSquare(newRow, newColumn);

        // checks to make sure the path between the two squares is empty and a valid horizontal or vertical movement
        if(board->pathClearStraight(currentSquare, targetSquare)){
            return true;
        }
    }
    return false;
}