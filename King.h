#include<iostream>
#include <SFML/Graphics.hpp>
#include <map>

class King {
private:
    /// MAP POSITIONS FOR WHITE KINGS ///
    std::map<int, int> nextPositionsY;
    std::map<int, int> nextPositionsX;
    std::map<int, sf::Vector2f> latestPosition;

    /// MAP POSITIONS FOR BLACK KINGS ///
    std::map<int, int> nextPositionsY2;
    std::map<int, int> nextPositionsX2;
    std::map<int, sf::Vector2f> latestPosition2;

public:

    /// FUNCTION TO MOVE AND DRAW KINGS ///
    void move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
              sf::Sprite& pieces, const sf::Vector2i& mouse, int positionX, int positionY);

    /// RULE MOVEMENT FUNCTION FOR WHITE KINGS ///
    void whitePieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        sf::Sprite& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY, const sf::Vector2i& mouse);

    /// RULE MOVEMENT FUNCTION FOR BLACK KINGS ///
    void blackPieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                       sf::Sprite& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY,const sf::Vector2i& mouse);

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK KINGS ///
    void whitePieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,sf::Sprite& pieces);

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE KINGS ///
    void blackPieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,sf::Sprite& pieces);

};
