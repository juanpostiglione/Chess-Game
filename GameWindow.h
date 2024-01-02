#include<iostream>
#include <SFML/Graphics.hpp>
#pragma once

using namespace std;

class Board;
class Pawn;
class Rook;
class Knight;
class Bishop;
class King;
class Queen;
class WinGame;

class GameWindow{
private:

    /// GAME WINDOW DIMENSIONS ///
    int width;
    int height;

public:
    /// DEFAULT CONSTRUCTOR ///
    GameWindow();

    /// FUNCTION TO DISPLAY GAME WINDOW ///
    void GameWindowDisplay(Board& chessBoard, Pawn& pawnPieces, Rook& rookPieces, Knight& knightPieces,
                           Bishop& bishopPieces, King& kingPieces, Queen& queenPieces, WinGame& winGame) ;
};
