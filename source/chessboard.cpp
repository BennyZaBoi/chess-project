#include chessboard.h

Chessboard::Chessboard(){
    board = new Square*[8][8];
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            board[i][j] = Squares(i, j, nullptr);
        }
    }
}

Chessboard::~Chessboard(){
    for (int i = 0; i < 8; ++i){
        delete[] board[i];
    }   
    delete[] board; 
}

bool Chessboard::pathClearStraight(Square* sqrOne, Square* sqrTwo){
    int sqrOneRow = sqrOne.getRow();
    int sqrOneColumn = sqrOne.getColumn(); 
    int sqrTwoRow = sqrTwo.getRow();
    int sqrTwoColumn = sqrtTwo.getColumn();

    if ((sqrOneRow != sqrTwoRow) && (sqrOneColumn != sqrTwoColumn)){
        return false; 
    }
    else if ((sqrOneRow == sqrTwoRow) && (sqrOneColumn == sqrTwoColumn)){
        return false; 
    }
    else if (sqrOneColumn == sqrTwoColumn){
         if (sqrOneRow < sqrTwoRow){
            for (int i = sqrOneRow; i <= sqrTwoRow; ++i){
                if (board[i][column].getPiece() != nullptr){
                    return false; 
                }
            }
        }
        else {
            for (int i = sqrOneRow; i >= sqrTwoRow; --i){
                if (board[i][column].getPiece() != nullptr){
                    return false; 
                }
            }
        }
    }
    else if (sqrOneRow == sqrTwoRow){
        if (sqrOneColumn < sqrTwoColumn){
            for (int i = sqrOneColumn; i <= sqrTwoColumn; ++i){
                if (board[row][i].getPiece() != nullptr){
                    return false; 
                }
            }
        }
        else {
            for (int i = sqrOneColumn; i >= sqrTwoColumn; ++i){
                if (board[row][i].getPiece() != nullptr){
                    return false; 
                }
            }
        }
    }
    return true; 
}

bool Chessboard::pathClearDiagonal(Square* sqrOne, Square* sqrTwo){
    int sqrOneRow = sqrOne.getRow();
    int sqrOneColumn = sqrOne.getColumn(); 
    int sqrTwoRow = sqrTwo.getRow();
    int sqrTwoColumn = sqrtTwo.getColumn();
    int compareColumn = 0; 
    int compareRow = 0;

    if ((sqrOneRow == sqrTwoRow) || (sqrOneColumn == sqrTwoColumn)){
        return false; 
    }
    if (sqrOneRow < sqrTwoRow){
        if (sqrOneColumn < sqrTwoColumn){
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; ++i){
                if (i == sqrTwoRow){
                    if (sqrOneColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                ++compareColumn; 
            }
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; ++i){
                if (board[i][compareColumn].getPiece() != nullptr){
                    return false; 
                }
                ++compareColumn;
            }
            return true; 
        }
        else {
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; ++i){
                if (i == sqrTwoRow){
                    if (sqrOneColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                --compareColumn; 
            }
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; ++i){
                if (board[i][compareColumn].getPiece() != nullptr){
                    return false; 
                }
                --compareColumn;
            }
            return true; 
        }
    } 
    else {
        if (sqrOneColumn < sqrTwoColumn){
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; --i){
                if (i == sqrTwoRow){
                    if (sqrOneColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                ++compareColumn; 
            }
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; --i){
                if (board[i][compareColumn].getPiece() != nullptr){
                    return false; 
                }
                ++compareColumn;
            }
            return true; 
        }
        else {
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; --i){
                if (i == sqrTwoRow){
                    if (sqrOneColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                --compareColumn; 
            }
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; --i){
                if (board[i][compareColumn].getPiece() != nullptr){
                    return false; 
                }
                --compareColumn;
            }
            return true; 
        }

    }
}

