#include"WelcomeWindow.h"
#include "Piece.h"
int main()
{
    Board chessBoard;
    Pawn pawnPieces;
    Rook rookPieces;
    Knight knightPieces;
    Bishop bishopPieces;
    King kingPieces;
    Queen queenPieces;
    WelcomeWindow window1;
    window1.welcomeWindowDisplay(chessBoard, pawnPieces, rookPieces, knightPieces, bishopPieces, kingPieces,queenPieces);
    return 0;
}
