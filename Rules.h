#include<iostream>
#include <SFML/Graphics.hpp>
#include <map>
#pragma once

using namespace std;
class Rules {
public:

    /// FUNCTION TO MOVE AND DRAW THE PIECE ///
    virtual void move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
                      vector<sf::Sprite>& piece, const sf::Vector2i& mouse, int positionX, int positionY) const = 0;

    virtual void whitePieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                    vector<sf::Sprite>& pieces,bool& pawn_selected, bool& piece_released,
                    int posX, int positionY, const sf::Vector2i& mouse) const = 0;

   virtual void blackPieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                     vector<sf::Sprite>& pieces,bool& piece_selected, bool& piece_released,
                     int posX, int positionY,const sf::Vector2i& mouse) const = 0;

    virtual void whitePieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                           int positionY ,vector<sf::Sprite>& pieces) const = 0;

    virtual void blackPieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                           int positionY ,vector<sf::Sprite>& pieces)const = 0;
};

