#include "../header/chessboard.h"
#include "../header/Rook.h"
#include "../header/Queen.h"
#include "../header/Knight.h"
#include "../header/Bishop.h"
#include "../header/Pawn.h"
#include "../header/King.h"
#include "../header/Color.h"


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
        for (int j = 0; j < 8; ++j){
            if (board[i][j] != nullptr){
                delete board[i][j];
            }
            board[i][j] = nullptr;
        }
        delete[] board[i];
        board[i] = nullptr;
    }  
    delete[] board;
    board= nullptr;
}


void Chessboard::initializeChessboard(Color playerOneColor, Color playerTwoColor){
    board[0][0]->setPiece(new Rook(playerOneColor, 0, 0));
    board[0][7]->setPiece(new Rook(playerOneColor, 0, 7));
    board[0][1]->setPiece(new Knight(playerOneColor, 0, 1));
    board[0][6]->setPiece(new Knight(playerOneColor, 0, 6));
    board[0][5]->setPiece(new Bishop(playerOneColor, 0, 5));
    board[0][2]->setPiece(new Bishop(playerOneColor, 0, 2));
    board[0][3]->setPiece(new Queen(playerOneColor, 0, 3));
    board[0][4]->setPiece(new King(playerOneColor, 0, 4));

    board[1][0]->setPiece(new Pawn(playerOneColor, 1, 0, false));
    board[1][1]->setPiece(new Pawn(playerOneColor, 1, 1, false));
    board[1][2]->setPiece(new Pawn(playerOneColor, 1, 2, false));
    board[1][3]->setPiece(new Pawn(playerOneColor, 1, 3, false));
    board[1][4]->setPiece(new Pawn(playerOneColor, 1, 4, false));
    board[1][5]->setPiece(new Pawn(playerOneColor, 1, 5, false));
    board[1][6]->setPiece(new Pawn(playerOneColor, 1, 6, false));
    board[1][7]->setPiece(new Pawn(playerOneColor, 1, 7, false));

    board[6][0]->setPiece(new Pawn(playerTwoColor, 6, 0, true));
    board[6][1]->setPiece(new Pawn(playerTwoColor, 6, 1, true));
    board[6][2]->setPiece(new Pawn(playerTwoColor, 6, 2, true));
    board[6][3]->setPiece(new Pawn(playerTwoColor, 6, 3, true));
    board[6][4]->setPiece(new Pawn(playerTwoColor, 6, 4, true));
    board[6][5]->setPiece(new Pawn(playerTwoColor, 6, 5, true));
    board[6][6]->setPiece(new Pawn(playerTwoColor, 6, 6, true));
    board[6][7]->setPiece(new Pawn(playerTwoColor, 6, 7, true));


    board[7][0]->setPiece(new Rook(playerTwoColor, 7, 0));
    board[7][7]->setPiece(new Rook(playerTwoColor, 7, 7));
    board[7][1]->setPiece(new Knight(playerTwoColor, 7, 1));
    board[7][6]->setPiece(new Knight(playerTwoColor, 7, 6));
    board[7][5]->setPiece(new Bishop(playerTwoColor, 7, 5));
    board[7][2]->setPiece(new Bishop(playerTwoColor, 7, 2));
    board[7][3]->setPiece(new Queen(playerTwoColor, 7, 3));
    board[7][4]->setPiece(new King(playerTwoColor, 7, 4));



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
            for (int i = (sqrOneRow + 1); i < sqrTwoRow; ++i){
                if (board[i][sqrOneColumn]->getPiece() != nullptr){
                    return false; 
                }
            }
        }
        else {
            for (int i = (sqrOneRow - 1); i > sqrTwoRow; --i){
                if (board[i][sqrOneColumn]->getPiece() != nullptr){
                    return false; 
                }
            }
        }
    }
    else if (sqrOneRow == sqrTwoRow){
        if (sqrOneColumn < sqrTwoColumn){
            for (int i = (sqrOneColumn + 1); i < sqrTwoColumn; ++i){
                if (board[sqrOneRow][i]->getPiece() != nullptr){
                    return false; 
                }
            }
        }
        else {
            for (int i = (sqrOneColumn - 1); i > sqrTwoColumn; --i){
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
            for (int i = (sqrOneRow + 1); i < sqrTwoRow; ++i){
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
            for (int i = (sqrOneRow + 1); i < sqrTwoRow; ++i){
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
            for (int i = (sqrOneRow - 1); i > sqrTwoRow; --i){
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
            for (int i = (sqrOneRow - 1); i > sqrTwoRow; --i){
                if (board[i][compareColumn]->getPiece() != nullptr){
                    return false; 
                }
                --compareColumn;
            }
            return true; 
        } 
    }
    return false; 
}

Squares* Chessboard::getSquare(int row, int column) const {
    return board[row][column]; 
}  