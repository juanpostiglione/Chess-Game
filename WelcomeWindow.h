#pragma once
#include<iostream>
#include"Board.h"
#include <SFML/Graphics.hpp>

using namespace std;

class WelcomeWindow {
    int width;
    int height;
    string playerName;

public:
    
    /// DEFAULT CONSTRUCTOR ///
    WelcomeWindow();
    
    /// FUNCTION TO DISPLAY WELCOME WINDOW ///
    void welcomeWindowDisplay(Board& chessBoard);

    /// SET TEXT TO THE CENTER ///
    void setText(sf::Text &text, float x, float y); 
};
