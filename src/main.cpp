#include"WelcomeWindow.h"
#include "Board.h"
#include "WinGame.h"
#include "Pawn.h"
#include "Knight.h"
#include"Rook.h"
#include"Bishop.h"
#include"King.h"
#include"Queen.h"

int main()
{
    /// CREATE CLASS INSTANCES ///
    Board chessBoard;
    Pawn pawnPieces;
    Rook rookPieces;
    Knight knightPieces;
    Bishop bishopPieces;
    King kingPieces;
    Queen queenPieces;
    WinGame winGame;
    WelcomeWindow window1;

    /// DISPLAY WELCOME WINDOW ///
    window1.welcomeWindowDisplay(chessBoard, pawnPieces, rookPieces, knightPieces, bishopPieces, kingPieces,queenPieces, winGame);
    return 0;
}


