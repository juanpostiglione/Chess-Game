#include<iostream>
#include <SFML/Graphics.hpp>
#include <map>

using namespace  std;
class Queen {
private:

public:

    /// FUNCTION TO MOVE AND DRAW QUEENS ///
    void move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
              sf::Sprite& pieces, const sf::Vector2i& mouse, int positionX, int positionY);

    /// RULE MOVEMENT FUNCTION FOR WHITE QUEENS ///
    void whitePieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        sf::Sprite& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY, const sf::Vector2i& mouse);

    /// RULE MOVEMENT FUNCTION FOR BLACK QUEENS ///
    void blackPieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        sf::Sprite& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY,const sf::Vector2i& mouse);
    
};
