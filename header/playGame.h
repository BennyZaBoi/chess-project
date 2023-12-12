#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <vector>
#include "../header/chessboard.h"
#include "../header/displaychessboard.h"
#include "../header/Player.h"
#include "../header/Piece.h"
#include "../header/King.h"
#include "../header/Bishop.h"
#include "../header/Knight.h"
#include "../header/Rook.h"
#include "../header/Pawn.h"
#include "../header/Queen.h"

void playGame(Player player1, Player player2, Chessboard *&board, ChessboardDisplay *showChess);
void makeBetween0And7(int &startRow, int &startColumn);
void makeSelectOccupied(Chessboard *board, Squares *&currentSquare, int &startRow, int &startColumn);
void chooseSameColor(Chessboard *board, Squares *&currentSquare, Player player, int &startRow, int &startColumn);
void makeDiffStartAndEnd(int &endRow, int startRow, int &endColumn, int startColumn);
void makeValidMove(Player p1, Squares *&currentSquare, int &endRow, int &endColumn, int &startRow, int &startColumn, Chessboard *board);
void outputPieceMoved(Squares *currentSquare, string pieceType, int endRow, int endColumn);
bool isKingCaptured(Chessboard *board, vector<Player> playerList);

#endif