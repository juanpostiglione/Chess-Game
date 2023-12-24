#pragma once
#include<iostream>
#include "GameWindow.h"
#include <SFML/Graphics.hpp>

using namespace std;

class WelcomeWindow {
private:

    /// DIMENSIONS FOR THE WINDOW ///
    float width;
    float height;

public:

    /// DEFAULT CONSTRUCTOR ///
    WelcomeWindow();

    /// FUNCTION TO DISPLAY WELCOME WINDOW ///
    void welcomeWindowDisplay(Board& chessBoard, Pawn& pawnPieces, Rook& rookPieces, Knight& knightPieces,
                              Bishop& bishopPieces, King& kingPieces, Queen& queenPieces, WinGame& winGame) const;

    /// SET TEXT TO THE CENTER ///
    static void setText(sf::Text &text, float x, float y);
};
