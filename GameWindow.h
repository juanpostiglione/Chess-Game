#include<iostream>
#include <SFML/Graphics.hpp>
#pragma once

using namespace std;

class Board;

class GameWindow{
private:
    int width;
    int height;
    sf::Sprite selectedPiece;

public:
    /// DEFAULT CONSTRUCTOR ///
    GameWindow();

    /// FUNCTION TO DISPLAY GAME WINDOW ///
    void GameWindowDisplay(Board& chessBoard) const;
};
