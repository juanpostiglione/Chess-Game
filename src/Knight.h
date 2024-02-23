#include<iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include "Rules.h"

using namespace std;

class Knight : public Rules
{
private:
    /// MAP POSITIONS WHITE KNIGHT ///
    mutable std::map<int, int> nextPositionsY;
    mutable std::map<int, int> nextPositionsX;
    mutable std::map<int, sf::Vector2f> latestPosition;

    /// MAP POSITIONS BLACK KNIGHT ///
    mutable std::map<int, int> nextPositionsY2;
    mutable std::map<int, int> nextPositionsX2;
    mutable std::map<int, sf::Vector2f> latestPosition2;

public:
    /// FUNCTION TO MOVE AND DRAW KNIGHTS ///
    void move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
              vector<sf::Sprite>& pieces, const sf::Vector2i& mouse, int positionX, int positionY) const override;

    /// RULE MOVEMENT FUNCTION FOR WHITE KNIGHT ///
    void whitePieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        vector<sf::Sprite>& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY, const sf::Vector2i& mouse) const override;

    /// RULE MOVEMENT FUNCTION FOR BLACK KNIGHT ///
    void blackPieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        vector<sf::Sprite>& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY,const sf::Vector2i& mouse)const override;

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE KNIGHT ///
    void whitePieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,vector<sf::Sprite>& pieces) const override;

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK KNIGHT ///
    void blackPieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,vector<sf::Sprite>& pieces)const override;
};



