#include chessboard.h

Chessboard::Chessboard(){
    board = new Square*[8][8];
}

bool Chessboard::pathClearStraight(Square* rowSqr, Square* clmnSqr){
    int row = rowSqr.getRow();
    int column = clmnSqr.getColumn(); 
    for (int i = column; i >= 0; --i){
        if (board[row][i].getPiece() != nullptr){
            return false;
        }
    }
    return true; 
}

bool Chessboard::pathClearDiagonal(Square* rowSqr, Square* clmnSqr){
    int row = rowSqr.getRow();
    int column = clmnSqr.getColumn(); 
    for (int i = column; i >= 0 && row >= 0; --i){
        if (board[row][i].getPiece() != nullptr){
            return false;
        }
        --row; 
    }
    for (int i = column; i < 8 && row < 8; ++i){
        if (board[row][i].getPiece() != nullptr){
            return false;
        }
        ++row; 
    }
    return true; 
}
