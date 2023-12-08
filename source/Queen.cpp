#include "../header/Queen.h"
#include "../header/chessboard.h"
#include "../header/squares.h"

Queen::Queen(Color _color, int _row, int _column) : Piece(_color, Qn, _row, _column){}

bool Queen::moveValid(int newRow, int newColumn, const Chessboard* board) const{
    // checks if new position is on the board and that the queen is not moving to the same position
    if(onBoard(newRow, newColumn) && isMoving(newRow, newColumn)){

        if(attackingAlly(newRow, newColumn, board)){
            return false;
        }

        Squares* currentSquare = board->getSquare(row, column);
        Squares* targetSquare = board->getSquare(newRow, newColumn);

        // checks to make sure the path between the two squares is empty and that the movement is either diagonal or horizontal or vertical
        if(board->pathClearStraight(currentSquare, targetSquare) || board->pathClearDiagonal(currentSquare, targetSquare)){
            return true;
        }
    }
    return false;
}