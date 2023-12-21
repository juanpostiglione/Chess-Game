#pragma once
#include<iostream>
#include"Board.h"
#include <SFML/Graphics.hpp>

using namespace std;

class WelcomeWindow {
    float width;
    float height;
    string playerName;

public:

    /// DEFAULT CONSTRUCTOR ///
    WelcomeWindow();

    /// FUNCTION TO DISPLAY WELCOME WINDOW ///
    void welcomeWindowDisplay(Board& chessBoard, Pawn& pawnPieces, Rook& rookPieces, Knight& knightPieces, Bishop& bishopPieces, King& kingPieces, Queen& queenPieces);

    /// SET TEXT TO THE CENTER ///
    void setText(sf::Text &text, float x, float y);
};
