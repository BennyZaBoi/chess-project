#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "../header/chessboard.h"
#include "../header/Player.h"
#include "../header/Piece.h"
#include "../header/King.h"
#include "../header/Bishop.h"
#include "../header/Knight.h"
#include "../header/Rook.h"
#include "../header/Pawn.h"
#include "../header/Queen.h"

void playGame(Player player1, Player player2, Chessboard *board);

#endif