#include "../header/chessboard.h"

Chessboard::Chessboard(){
    board = new Squares**[8];
    for (int i = 0; i < 8; ++i){
        board[i] = new Squares*[8];
    }

    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            board[i][j] = new Squares(i, j, nullptr);
        }
    }
}

Chessboard::~Chessboard(){
    for (int i = 0; i < 8; ++i){
        delete[] board[i];
    }   
    delete[] board; 
}

bool Chessboard::pathClearStraight(Squares* sqrOne, Squares* sqrTwo) const {
    int sqrOneRow = sqrOne->getRow();
    int sqrOneColumn = sqrOne->getColumn(); 
    int sqrTwoRow = sqrTwo->getRow();
    int sqrTwoColumn = sqrTwo->getColumn();

    if ((sqrOneRow != sqrTwoRow) && (sqrOneColumn != sqrTwoColumn)){
        return false; 
    }
    else if ((sqrOneRow == sqrTwoRow) && (sqrOneColumn == sqrTwoColumn)){
        return false; 
    }
    else if (sqrOneColumn == sqrTwoColumn){
         if (sqrOneRow < sqrTwoRow){
            for (int i = (sqrOneRow + 1); i <= sqrTwoRow; ++i){
                if (board[i][sqrOneColumn]->getPiece() != nullptr){
                    return false; 
                }
            }
        }
        else {
            for (int i = (sqrOneRow - 1); i >= sqrTwoRow; --i){
                if (board[i][sqrOneColumn]->getPiece() != nullptr){
                    return false; 
                }
            }
        }
    }
    else if (sqrOneRow == sqrTwoRow){
        if (sqrOneColumn < sqrTwoColumn){
            for (int i = (sqrOneColumn + 1); i <= sqrTwoColumn; ++i){
                if (board[sqrOneRow][i]->getPiece() != nullptr){
                    return false; 
                }
            }
        }
        else {
            for (int i = (sqrOneColumn - 1); i >= sqrTwoColumn; --i){
                if (board[sqrOneRow][i]->getPiece() != nullptr){
                    return false; 
                }
            }
        }
    }
    return true; 
}

bool Chessboard::pathClearDiagonal(Squares* sqrOne, Squares* sqrTwo) const {
    int sqrOneRow = sqrOne->getRow();
    int sqrOneColumn = sqrOne->getColumn(); 
    int sqrTwoRow = sqrTwo->getRow();
    int sqrTwoColumn = sqrTwo->getColumn();
    int compareColumn = 0; 
    int compareRow = 0;

    if ((sqrOneRow == sqrTwoRow) || (sqrOneColumn == sqrTwoColumn)){
        return false; 
    }
    else if (sqrOneRow < sqrTwoRow){
        if (sqrOneColumn < sqrTwoColumn){
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; ++i){
                if (i == sqrTwoRow){
                    if (compareColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                ++compareColumn; 
            }
            compareColumn = (sqrOneColumn + 1);
            for (int i = (sqrOneRow + 1); i <= sqrTwoRow; ++i){
                if (board[i][compareColumn]->getPiece() != nullptr){
                    return false; 
                }
                ++compareColumn;
            }
            return true; 
        }
        else if (sqrOneColumn > sqrTwoColumn){
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i <= sqrTwoRow; ++i){
                if (i == sqrTwoRow){
                    if (compareColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                --compareColumn; 
            }
            compareColumn = (sqrOneColumn - 1);
            for (int i = (sqrOneRow + 1); i <= sqrTwoRow; ++i){
                if (board[i][compareColumn]->getPiece() != nullptr){
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
            for (int i = sqrOneRow; i >= sqrTwoRow; --i){
                if (i == sqrTwoRow){
                    if (compareColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                ++compareColumn; 
            }
            compareColumn = (sqrOneColumn + 1);
            for (int i = (sqrOneRow - 1); i >= sqrTwoRow; --i){
                if (board[i][compareColumn]->getPiece() != nullptr){
                    return false; 
                }
                ++compareColumn;
            }
            return true; 
        }
        else {
            compareColumn = sqrOneColumn;
            for (int i = sqrOneRow; i >= sqrTwoRow; --i){
                if (i == sqrTwoRow){
                    if (compareColumn != sqrTwoColumn){
                        return false; 
                    }
                }
                --compareColumn; 
            }
            compareColumn = (sqrOneColumn - 1);
            for (int i = (sqrOneRow - 1); i >= sqrTwoRow; --i){
                if (board[i][compareColumn]->getPiece() != nullptr){
                    return false; 
                }
                --compareColumn;
            }
            return true; 
        }

    }
}

Squares* Chessboard::getSquare(int row, int column){
    return board[row][column]; 
}  
