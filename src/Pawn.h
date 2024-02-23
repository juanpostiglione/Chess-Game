#include<iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include "Rules.h"

using namespace std;

class Pawn : public Rules
{
private:
    /// MAP POSITIONS FOR WHITE PAWNS ///
    mutable std::map<int, int> nextPositionsX;
    mutable std::map<int, int> nextPositionsY;
    mutable std::map<int, sf::Vector2f> latestPosition;

    /// COUNTER FOR WHITE PAWNS ///
    mutable std::map<int, int> counterMove; /// Track how many times the piece is moved

    /// MAP POSITIONS FOR BLACK PAWNS ///
    mutable std::map<int, int> nextPositionsX2;
    mutable std::map<int, int> nextPositionsY2;
    mutable std::map<int, sf::Vector2f> latestPosition2;

    /// COUNTER FOR BLACK PAWNS ///
    mutable std::map<int, int> counterMove2; /// Track how many times the piece is moved
public:

    /// FUNCTION TO MOVE AND DRAW PAWNS ///
    void move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
              vector<sf::Sprite>& pieces, const sf::Vector2i& mouse, int positionX, int positionY) const override;

    /// RULE MOVEMENT FUNCTION FOR WHITE PAWN ///
    void whitePieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        vector<sf::Sprite>& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY, const sf::Vector2i& mouse) const override;

    /// RULE MOVEMENT FUNCTION FOR BLACK PAWN ///
    void blackPieceRule(sf::Event& event, sf::RenderWindow& gameWindow,
                        vector<sf::Sprite>& pieces,bool& piece_selected, bool& piece_released,
                        int posX, int positionY,const sf::Vector2i& mouse) const override;

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK PAWN ///
    void whitePieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,vector<sf::Sprite>& pieces) const override;

    /// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE PAWN ///
    void blackPieceBehavior(sf::RenderWindow& gameWindow,const sf::Vector2i& mouse, int positionX,
                            int positionY ,vector<sf::Sprite>& pieces) const override;
};


