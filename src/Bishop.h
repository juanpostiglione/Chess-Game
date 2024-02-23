#include<iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include "Rules.h"

using namespace std;

class Bishop : public Rules
{
private:
    /// MAP POSITIONS WHITE BISHOP ///
    mutable std::map<int, int> nextPositionsY;
    mutable std::map<int, int> nextPositionsX;
    mutable std::map<int, sf::Vector2f> latestPosition;

    /// MAP POSITIONS BLACK BISHOP ///
    mutable std::map<int, int> nextPositionsY2;
    mutable std::map<int, int> nextPositionsX2;
    mutable std::map<int, sf::Vector2f> latestPosition2;

public:
    /// FUNCTION TO MOVE AND DRAW BISHOP ///
    void move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
              vector<sf::Sprite>& pieces, const sf::Vector2i& mouse, int positionX, int positionY) const override;

    /// RULE MOVEMENT FUNCTION FOR WHITE BISHOP ///
    void whitePieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        vector<sf::Sprite>& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY, const sf::Vector2i& mouse) const override;

    /// RULE MOVEMENT FUNCTION FOR BLACK BISHOP ///
    void blackPieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        vector<sf::Sprite>& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY,const sf::Vector2i& mouse)const override;

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE BISHOP ///
    void whitePieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,vector<sf::Sprite>& pieces) const override;

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK BISHOP ///
    void blackPieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,vector<sf::Sprite>& pieces)const override;

};





