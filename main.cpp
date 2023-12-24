#include"WelcomeWindow.h"
#include "Piece.h"
#include "Board.h"
#include "WinGame.h"
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
