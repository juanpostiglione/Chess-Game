#include "King.h"


/// FUNCTION TO DRAW KINGS ///
void King::move(sf::RenderWindow& window, bool kingSelected, bool kingReleased,
                sf::Sprite& kings, const sf::Vector2i& mouse, int positionX, int positionY)
{
    /// IF KING IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < 1; i++)
    {
        if (kingSelected && kings.getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            kings.setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(kings);
        }
        else
        {
            window.draw(kings);
        }

        /// IF KING IS RELEASED, IS PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
            const int centerPoint = 20;
            int snappedX = static_cast<int>((kings.getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
            int snappedY = static_cast<int>((kings.getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
            kings.setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

        /// DRAW KINGS FROM THE BEGINNING ///
        if (!kingReleased && !kingSelected)
        {
            kings.setPosition(static_cast<float>(positionX), static_cast<float>(positionY));
        }
    }
}


/// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE KING ///
void King::whitePieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                              sf::Sprite& king)
{
    /// ------ ALLOWED POSITIONS ------ ///

    /// Move forward
    sf::Vector2f allowedPos(positionX + nextPositionsX[0], positionY - nextPositionsY[0]- 60);

    /// Move backward
    sf::Vector2f allowedPos2(positionX + nextPositionsX[0], positionY - nextPositionsY[0]+ 60);

    /// Move right
    sf::Vector2f allowedPos3(positionX + nextPositionsX[0] + 60, positionY - nextPositionsY[0]);

    /// Move Left
    sf::Vector2f allowedPos4(positionX + nextPositionsX[0] - 60, positionY - nextPositionsY[0]);

    /// Diagonal to the right
    sf::Vector2f allowedPos5(positionX + nextPositionsX[0] + 60, positionY - nextPositionsY[0]- 60);

    /// Diagonal to the left
    sf::Vector2f allowedPos6(positionX + nextPositionsX[0] - 60, positionY - nextPositionsY[0]- 60);

    /// Diagonal backward to the right
    sf::Vector2f allowedPos7(positionX + nextPositionsX[0] + 60, positionY - nextPositionsY[0]+ 60);

    /// Diagonal backward to the left
    sf::Vector2f allowedPos8(positionX + nextPositionsX[0] - 60, positionY - nextPositionsY[0]+ 60);

    /// Move forward
    if(king.getPosition() == allowedPos)
    {
        nextPositionsY[0] += 60;
    }

    /// Move backward
    else if(king.getPosition() == allowedPos2)
    {
        nextPositionsY[0] -= 60;
    }

    /// Move right
    else if(king.getPosition() == allowedPos3)
    {
        nextPositionsX[0] += 60;
    }

    /// Move Left
    else if(king.getPosition() == allowedPos4)
    {
        nextPositionsX[0] -= 60;
    }

    /// Diagonal to the right
    else if(king.getPosition() == allowedPos5)
    {
        nextPositionsX[0] += 60;
        nextPositionsY[0] += 60;
    }

    /// Diagonal to the left
    else if(king.getPosition() == allowedPos6)
    {
        nextPositionsX[0] -= 60;
        nextPositionsY[0] += 60;
    }

    /// Diagonal backward to the right
    else if(king.getPosition() == allowedPos7)
    {
        nextPositionsX[0] += 60;
        nextPositionsY[0] -= 60;
    }

    /// Diagonal backward to the left
    else if(king.getPosition() == allowedPos8)
    {
        nextPositionsX[0] -= 60;
        nextPositionsY[0] -= 60;
    }

    /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
    else if(king.getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
    {
        king.setPosition(latestPosition[0]);
    }
}

/// RULE MOVEMENT FUNCTION FOR WHITE KING ///
void King::whitePieceRule(sf::Event &event, sf::RenderWindow &gameWindow, sf::Sprite& king,
                          bool &piece_selected, bool &piece_released, int posX, int positionY,
                          const sf::Vector2i &mouse2)
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        /// IF A PIECE IS CLICKED ///
        if (king.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
        {
            piece_selected = true;
            piece_released = false;
            latestPosition[0] = king.getPosition();
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && piece_selected)
    {
        piece_selected = false;
        piece_released = true;

        /// CALL FUNCTION TO MOVE THE PIECE WITH ITS BEHAVIOR ///
        whitePieceBehavior(gameWindow, mouse2, posX, positionY,king);
    }
}

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK KING ///
void King::blackPieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                              sf::Sprite& king)
{
    /// ------ ALLOWED POSITIONS ------ ///

    /// Move forward
    sf::Vector2f allowedPos(positionX + nextPositionsX2[0], positionY - nextPositionsY2[0]+ 60);

    /// Move backward
    sf::Vector2f allowedPos2(positionX + nextPositionsX2[0], positionY - nextPositionsY2[0]- 60);

    /// Move right
    sf::Vector2f allowedPos3(positionX + nextPositionsX2[0] - 60, positionY - nextPositionsY2[0]);

    /// Move Left
    sf::Vector2f allowedPos4(positionX + nextPositionsX2[0] + 60, positionY - nextPositionsY2[0]);

    /// Diagonal to the right
    sf::Vector2f allowedPos5(positionX + nextPositionsX2[0] - 60, positionY - nextPositionsY2[0]+ 60);

    /// Diagonal to the left
    sf::Vector2f allowedPos6(positionX + nextPositionsX2[0] + 60, positionY - nextPositionsY2[0]+ 60);

    /// Diagonal backward to the right
    sf::Vector2f allowedPos7(positionX + nextPositionsX2[0] - 60, positionY - nextPositionsY2[0]- 60);

    /// Diagonal backward to the left
    sf::Vector2f allowedPos8(positionX + nextPositionsX2[0] + 60, positionY - nextPositionsY2[0]- 60);

    /// Move forward
    if(king.getPosition() == allowedPos)
    {
        nextPositionsY2[0] -= 60;
    }

    /// Move backward
    else if(king.getPosition() == allowedPos2)
    {
        nextPositionsY2[0] += 60;
    }

    /// Move right
    else if(king.getPosition() == allowedPos3)
    {
        nextPositionsX2[0] -= 60;
    }

    /// Move Left
    else if(king.getPosition() == allowedPos4)
    {
        nextPositionsX2[0] += 60;
    }

    /// Diagonal to the right
    else if(king.getPosition() == allowedPos5)
    {
        nextPositionsX2[0] -= 60;
        nextPositionsY2[0] -= 60;
    }

    /// Diagonal to the left
    else if(king.getPosition() == allowedPos6)
    {
        nextPositionsX2[0] += 60;
        nextPositionsY2[0] -= 60;
    }

    /// Diagonal backward to the right
    else if(king.getPosition() == allowedPos7)
    {
        nextPositionsX2[0] -= 60;
        nextPositionsY2[0] += 60;
    }

    /// Diagonal backward to the left
    else if(king.getPosition() == allowedPos8)
    {
        nextPositionsX2[0] += 60;
        nextPositionsY2[0] += 60;
    }

    /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
    else if(king.getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
    {
        king.setPosition(latestPosition2[0]);
    }
}

/// RULE MOVEMENT FUNCTION FOR BLACK KING ///
void King::blackPieceRule(sf::Event &event, sf::RenderWindow &gameWindow, sf::Sprite& king,
                          bool &piece_selected, bool &piece_released, int posX, int positionY,
                          const sf::Vector2i &mouse2)
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        for (int i = 0; i < 1; i++)
        {
            /// IF A PIECE IS CLICKED ///
            if (king.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                piece_selected = true;
                piece_released = false;
                latestPosition2[i] = king.getPosition();
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && piece_selected)
    {
        piece_selected = false;
        piece_released = true;

        /// CALL FUNCTION TO MOVE THE PIECE WITH ITS BEHAVIOR ///
        blackPieceBehavior(gameWindow, mouse2, posX, positionY,king);
    }
}
