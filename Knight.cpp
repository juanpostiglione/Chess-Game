#include "Knight.h"

/// FUNCTION TO DRAW AND MOVE KNIGHTS ///
void Knight::move(sf::RenderWindow& window, bool knightSelected, bool knightReleased,
                  vector<sf::Sprite>& knights, const sf::Vector2i& mouse, int positionX, int positionY) const
{
    /// IF KNIGHT IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < knights.size(); i++)
    {
        if (knightSelected && knights[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            knights[i].setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(knights[i]);
        }
        else
        {
            window.draw(knights[i]);
        }

        /// IF KNIGHT IS RELEASED, PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        int centerPoint = 20;
        int snappedX = static_cast<int>((knights[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
        int snappedY = static_cast<int>((knights[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
        knights[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));


        /// DRAW KNIGHTS FROM THE BEGINNING ///
        if (!knightReleased && !knightSelected)
        {
            knights[i].setPosition(static_cast<float>((i * 300) + positionX), static_cast<float>(positionY));
        }
    }
}

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE KNIGHT ///
void Knight::whitePieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                              vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// ----- ALLOWED POSITIONS TO MOVE ----- ///

        /// Move forward in L
        sf::Vector2f allowedPos((i * 300) + positionX + nextPositionsX[i] + 60 , positionY - nextPositionsY[i] - 120);
        sf::Vector2f allowedPos2((i * 300) + positionX + nextPositionsX[i] - 60 , positionY - nextPositionsY[i] - 120);

        sf::Vector2f allowedPos5((i * 300) + positionX + nextPositionsX[i] + 120 , positionY - nextPositionsY[i] - 60);
        sf::Vector2f allowedPos6((i * 300) + positionX + nextPositionsX[i] - 120 , positionY - nextPositionsY[i] - 60);

        /// Move Backward in L
        sf::Vector2f allowedPos3((i * 300) + positionX + nextPositionsX[i] - 60 , positionY - nextPositionsY[i] + 120);
        sf::Vector2f allowedPos4((i * 300) + positionX + nextPositionsX[i] + 60 , positionY - nextPositionsY[i] + 120);

        sf::Vector2f allowedPos7((i * 300) + positionX + nextPositionsX[i] - 120 , positionY - nextPositionsY[i] + 60);
        sf::Vector2f allowedPos8((i * 300) + positionX + nextPositionsX[i] + 120 , positionY - nextPositionsY[i] + 60);

        /// IF KNIGHT IS IN ALLOWED POSITION, UPDATE THE NEXT POSITION ///
        if (pieces[i].getPosition() == allowedPos)
        {
            nextPositionsY[i] += 120;
            nextPositionsX[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPos2)
        {
            nextPositionsY[i] += 120;
            nextPositionsX[i] -= 60;
        }
        else if (pieces[i].getPosition() == allowedPos3)
        {
            nextPositionsY[i] -= 120;
            nextPositionsX[i] -= 60;
        }
        else if (pieces[i].getPosition() == allowedPos4)
        {
            nextPositionsY[i] -= 120;
            nextPositionsX[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPos5)
        {
            nextPositionsX[i] += 120;
            nextPositionsY[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPos6)
        {
            nextPositionsX[i] -= 120;
            nextPositionsY[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPos7)
        {
            nextPositionsX[i] -= 120;
            nextPositionsY[i] -= 60;
        }
        else if (pieces[i].getPosition() == allowedPos8)
        {
            nextPositionsX[i] += 120;
            nextPositionsY[i] -= 60;
        }

        /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
        else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
        {
            pieces[i].setPosition(latestPosition[i]);
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR WHITE KNIGHT ///
void Knight::whitePieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
                          bool &piece_selected, bool &piece_released, int posX, int positionY,
                          const sf::Vector2i &mouse2) const
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        for (int i = 0; i < pieces.size(); i++)
        {
            /// IF A PIECE IS CLICKED ///
            if (pieces[i].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                piece_selected = true;
                piece_released = false;
                latestPosition[i] = pieces[i].getPosition(); /// Stored the latest position
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && piece_selected)
    {
        piece_selected = false;
        piece_released = true;

        /// CALL FUNCTION TO MOVE THE PIECE WITH ITS BEHAVIOR ///
        whitePieceBehavior(gameWindow, mouse2, posX, positionY,pieces);
    }
}

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK KNIGHT ///
void Knight::blackPieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                              vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// ----- ALLOWED POSITIONS TO MOVE ----- ///

        /// Move forward in L
        sf::Vector2f allowedPos((i * 300) + positionX + nextPositionsX2[i] - 60 , positionY - nextPositionsY2[i] + 120);
        sf::Vector2f allowedPos2((i * 300) + positionX + nextPositionsX2[i] + 60 , positionY - nextPositionsY2[i] + 120);

        sf::Vector2f allowedPos5((i * 300) + positionX + nextPositionsX2[i] - 120 , positionY - nextPositionsY2[i] + 60);
        sf::Vector2f allowedPos6((i * 300) + positionX + nextPositionsX2[i] + 120 , positionY - nextPositionsY2[i] + 60);

        /// Move Backward in L
        sf::Vector2f allowedPos3((i * 300) + positionX + nextPositionsX2[i] + 60 , positionY - nextPositionsY2[i] - 120);
        sf::Vector2f allowedPos4((i * 300) + positionX + nextPositionsX2[i] - 60 , positionY - nextPositionsY2[i] - 120);

        sf::Vector2f allowedPos7((i * 300) + positionX + nextPositionsX2[i] + 120 , positionY - nextPositionsY2[i] - 60);
        sf::Vector2f allowedPos8((i * 300) + positionX + nextPositionsX2[i] - 120 , positionY - nextPositionsY2[i] - 60);

        /// IF KNIGHT IS IN ALLOWED POSITION, UPDATE THE NEXT POSITION ///
        if (pieces[i].getPosition() == allowedPos)
        {
            nextPositionsY2[i] -= 120;
            nextPositionsX2[i] -= 60;
        }
        else if (pieces[i].getPosition() == allowedPos2)
        {
            nextPositionsY2[i] -= 120;
            nextPositionsX2[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPos3)
        {
            nextPositionsY2[i] += 120;
            nextPositionsX2[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPos4)
        {
            nextPositionsY2[i] += 120;
            nextPositionsX2[i] -= 60;
        }
        else if (pieces[i].getPosition() == allowedPos5)
        {
            nextPositionsY2[i] -= 60;
            nextPositionsX2[i] -= 120;
        }
        else if (pieces[i].getPosition() == allowedPos6)
        {
            nextPositionsY2[i] -= 60;
            nextPositionsX2[i] += 120;
        }
        else if (pieces[i].getPosition() == allowedPos7)
        {
            nextPositionsY2[i] += 60;
            nextPositionsX2[i] += 120;
        }

        else if (pieces[i].getPosition() == allowedPos8)
        {
            nextPositionsY2[i] += 60;
            nextPositionsX2[i] -= 120;
        }

        /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
        else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
        {
            pieces[i].setPosition(latestPosition2[i]);
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR BLACK KNIGHT ///
void Knight::blackPieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
                          bool &piece_selected, bool &piece_released, int posX, int positionY,
                          const sf::Vector2i &mouse2) const
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        for (int i = 0; i < pieces.size(); i++)
        {
            /// IF A PIECE IS CLICKED ///
            if (pieces[i].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                piece_selected = true;
                piece_released = false;
                latestPosition2[i] = pieces[i].getPosition();
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && piece_selected)
    {
        piece_selected = false;
        piece_released = true;

        /// CALL FUNCTION TO MOVE THE PIECE WITH ITS BEHAVIOR ///
        blackPieceBehavior(gameWindow, mouse2, posX, positionY,pieces);
    }
}
