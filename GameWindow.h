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

class GameWindow{
private:
    int width;
    int height;
    sf::Sprite selectedPiece;

public:
    /// DEFAULT CONSTRUCTOR ///
    GameWindow();

    /// FUNCTION TO DISPLAY GAME WINDOW ///
    void GameWindowDisplay(Board& chessBoard, Pawn& pawnPieces, Rook& rookPieces, Knight& knightPieces, Bishop& bishopPieces, King& kingPieces, Queen& queenPieces) const;
};
