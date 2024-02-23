#include "Bishop.h"

/// FUNCTION TO DRAW AND MOVE BISHOP ///
void Bishop::move(sf::RenderWindow& window, bool bishopSelected, bool bishopReleased,
                vector<sf::Sprite>& bishops, const sf::Vector2i& mouse, int positionX, int positionY) const
{
    /// IF BISHOP IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < bishops.size(); i++)
    {
        if (bishopSelected &&bishops[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            bishops[i].setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(bishops[i]);
        }
        else
        {
            window.draw(bishops[i]);
        }

        /// IF BISHOP IS RELEASED, IS PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        const int centerPoint = 20;
        int snappedX = static_cast<int>((bishops[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
        int snappedY = static_cast<int>((bishops[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
        bishops[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

        /// DRAW BISHOPS FROM THE BEGINNING ///
        if (!bishopReleased && !bishopSelected)
        {
            bishops[i].setPosition(static_cast<float>((i * 180) + positionX), static_cast<float>(positionY));
        }
    }
}

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE BISHOP ///
void Bishop::whitePieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                              vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// ----- ALLOWED POSITIONS TO MOVE ----- ///

        /// Move forward to the left
        sf::Vector2f allowedPosF((i * 180) + positionX + nextPositionsX[i] - 60, positionY - nextPositionsY[i] - 60);
        sf::Vector2f allowedPosF2((i * 180) + positionX + nextPositionsX[i] - 120, positionY - nextPositionsY[i] - 120);
        sf::Vector2f allowedPosF3((i * 180) + positionX + nextPositionsX[i] - 180, positionY - nextPositionsY[i] - 180);
        sf::Vector2f allowedPosF4((i * 180) + positionX + nextPositionsX[i] - 240, positionY - nextPositionsY[i] - 240);
        sf::Vector2f allowedPosF5((i * 180) + positionX + nextPositionsX[i] - 300, positionY - nextPositionsY[i] - 300);
        sf::Vector2f allowedPosF6((i * 180) + positionX + nextPositionsX[i] - 360, positionY - nextPositionsY[i] - 360);
        sf::Vector2f allowedPosF7((i * 180) + positionX + nextPositionsX[i] - 420, positionY - nextPositionsY[i] - 420);
        /// Move backward to the left
        sf::Vector2f allowedPosB1((i * 180) + positionX + nextPositionsX[i] - 60, positionY - nextPositionsY[i] + 60);
        sf::Vector2f allowedPosB2((i * 180) + positionX + nextPositionsX[i] - 120 , positionY - nextPositionsY[i] + 120);
        sf::Vector2f allowedPosB3((i * 180) + positionX + nextPositionsX[i] -180, positionY - nextPositionsY[i] + 180);
        sf::Vector2f allowedPosB4((i * 180) + positionX + nextPositionsX[i] - 240, positionY - nextPositionsY[i] + 240);
        sf::Vector2f allowedPosB5((i * 180) + positionX + nextPositionsX[i] - 300, positionY - nextPositionsY[i] + 300);
        sf::Vector2f allowedPosB6((i * 420) + positionX + nextPositionsX[i] - 360, positionY - nextPositionsY[i] + 360);
        sf::Vector2f allowedPosB7((i * 420) + positionX + nextPositionsX[i] - 420, positionY - nextPositionsY[i] + 420);
        /// Move forward to the right
        sf::Vector2f allowedPosL1((i * 180) + positionX + nextPositionsX[i] + 60 , positionY - nextPositionsY[i] - 60);
        sf::Vector2f allowedPosL2((i * 180) + positionX + nextPositionsX[i] + 120 , positionY - nextPositionsY[i] - 120);
        sf::Vector2f allowedPosL3((i * 180) + positionX + nextPositionsX[i] + 180 , positionY - nextPositionsY[i] - 180);
        sf::Vector2f allowedPosL4((i * 180) + positionX + nextPositionsX[i] + 240 , positionY - nextPositionsY[i] - 240);
        sf::Vector2f allowedPosL5((i * 180) + positionX + nextPositionsX[i] + 300 , positionY - nextPositionsY[i] - 300);
        sf::Vector2f allowedPosL6((i * 180) + positionX + nextPositionsX[i] + 360 , positionY - nextPositionsY[i] - 360);
        sf::Vector2f allowedPosL7((i * 180) + positionX + nextPositionsX[i] + 420 , positionY - nextPositionsY[i] - 420);
        /// Move backward the right
        sf::Vector2f allowedPosR1((i * 180) + positionX + nextPositionsX[i] + 60 , positionY - nextPositionsY[i] + 60);
        sf::Vector2f allowedPosR2((i * 180) + positionX + nextPositionsX[i] + 120 , positionY - nextPositionsY[i] + 120);
        sf::Vector2f allowedPosR3((i * 180) + positionX + nextPositionsX[i] + 180 , positionY - nextPositionsY[i] + 180);
        sf::Vector2f allowedPosR4((i * 180) + positionX + nextPositionsX[i] + 240 , positionY - nextPositionsY[i] + 240);
        sf::Vector2f allowedPosR5((i * 180) + positionX + nextPositionsX[i] + 300 , positionY - nextPositionsY[i] + 300);
        sf::Vector2f allowedPosR6((i * 180) + positionX + nextPositionsX[i] + 360 , positionY - nextPositionsY[i] + 360);
        sf::Vector2f allowedPosR7((i * 180) + positionX + nextPositionsX[i] + 420 , positionY - nextPositionsY[i] + 420);


        /// IF BISHOP IS IN ALLOWED POSITION, UPDATE THE NEXT POSITION ///

        /// Forward to the left
        if (pieces[i].getPosition() == allowedPosF)
        {
            nextPositionsY[i] += 60;
            nextPositionsX[i] -= 60;
        }
        else if (pieces[i].getPosition() == allowedPosF2)
        {
            nextPositionsY[i] += 120;
            nextPositionsX[i] -= 120;
        }
        else if (pieces[i].getPosition() == allowedPosF3)
        {
            nextPositionsY[i] += 180;
            nextPositionsX[i] -= 180;
        }
        else if (pieces[i].getPosition() == allowedPosF4)
        {
            nextPositionsY[i] += 240;
            nextPositionsX[i] -= 240;
        }
        else if (pieces[i].getPosition() == allowedPosF5)
        {
            nextPositionsY[i] += 300;
            nextPositionsX[i] -= 300;
        }
        else if (pieces[i].getPosition() == allowedPosF6)
        {
            nextPositionsY[i] += 360;
            nextPositionsX[i] -= 360;
        }
        else if (pieces[i].getPosition() == allowedPosF7)
        {
            nextPositionsY[i] += 420;
            nextPositionsX[i] -= 420;
        }

        /// Backward to the left
        else if(pieces[i].getPosition() == allowedPosB1)
        {
            nextPositionsY[i] -= 60;
            nextPositionsX[i] -= 60;
        }
        else if(pieces[i].getPosition() == allowedPosB2)
        {
            nextPositionsY[i] -= 120;
            nextPositionsX[i] -= 120;
        }
        else if(pieces[i].getPosition() == allowedPosB3)
        {
            nextPositionsY[i] -= 180;
            nextPositionsX[i] -= 180;
        }
        else if(pieces[i].getPosition() == allowedPosB4)
        {
            nextPositionsY[i] -= 240;
            nextPositionsX[i] -= 240;
        }
        else if(pieces[i].getPosition() == allowedPosB5)
        {
            nextPositionsY[i] -= 300;
            nextPositionsX[i] -= 300;
        }
        else if(pieces[i].getPosition() == allowedPosB6)
        {
            nextPositionsY[i] -= 360;
            nextPositionsX[i] -= 360;
        }
        else if(pieces[i].getPosition() == allowedPosB7)
        {
            nextPositionsY[i] -= 420;
            nextPositionsX[i] -= 420;
        }

        /// Forward to the right
        else if(pieces[i].getPosition() == allowedPosL1)
        {
            nextPositionsX[i] += 60;
            nextPositionsY[i] += 60;
        }
        else if(pieces[i].getPosition() == allowedPosL2)
        {
            nextPositionsX[i] += 120;
            nextPositionsY[i] += 120;
        }
        else if(pieces[i].getPosition() == allowedPosL3)
        {
            nextPositionsX[i] += 180;
            nextPositionsY[i] += 180;
        }
        else if(pieces[i].getPosition() == allowedPosL4)
        {
            nextPositionsX[i] += 240;
            nextPositionsY[i] += 180;
        }
        else if(pieces[i].getPosition() == allowedPosL5)
        {
            nextPositionsX[i] += 300;
            nextPositionsY[i] += 300;
        }
        else if(pieces[i].getPosition() == allowedPosL6)
        {
            nextPositionsX[i] += 360;
            nextPositionsY[i] += 360;
        }
        else if(pieces[i].getPosition() == allowedPosL7)
        {
            nextPositionsX[i] += 420;
            nextPositionsY[i] += 420;
        }

        /// Backward to the right
        else if(pieces[i].getPosition() == allowedPosR1)
        {
            nextPositionsX[i] += 60;
            nextPositionsY[i] -= 60;
        }
        else if(pieces[i].getPosition() == allowedPosR2)
        {
            nextPositionsX[i] += 120;
            nextPositionsY[i] -= 120;
        }
        else if(pieces[i].getPosition() == allowedPosR3)
        {
            nextPositionsX[i] += 180;
            nextPositionsY[i] -= 180;
        }
        else if(pieces[i].getPosition() == allowedPosR4)
        {
            nextPositionsX[i] += 240;
            nextPositionsY[i] -= 240;
        }
        else if(pieces[i].getPosition() == allowedPosR5)
        {
            nextPositionsX[i] += 300;
            nextPositionsY[i] -= 300;
        }
        else if(pieces[i].getPosition() == allowedPosR6)
        {
            nextPositionsX[i] += 360;
            nextPositionsY[i] -= 360;
        }
        else if(pieces[i].getPosition() == allowedPosR7)
        {
            nextPositionsX[i] += 420;
            nextPositionsY[i] -= 420;
        }

        /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
        else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
        {
            pieces[i].setPosition(latestPosition[i]);
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR WHITE BISHOP ///
void Bishop::whitePieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
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

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK BISHOP ///
void Bishop::blackPieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                              vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// ----- ALLOWED POSITIONS TO MOVE ----- ///

        /// Move forward to the left
        sf::Vector2f allowedPosF((i * 180) + positionX + nextPositionsX2[i] + 60, positionY - nextPositionsY2[i] + 60);
        sf::Vector2f allowedPosF2((i * 180) + positionX + nextPositionsX2[i] + 120, positionY - nextPositionsY2[i] + 120);
        sf::Vector2f allowedPosF3((i * 180) + positionX + nextPositionsX2[i] + 180, positionY - nextPositionsY2[i] + 180);
        sf::Vector2f allowedPosF4((i * 180) + positionX + nextPositionsX2[i] + 240, positionY - nextPositionsY2[i] + 240);
        sf::Vector2f allowedPosF5((i * 180) + positionX + nextPositionsX2[i] + 300, positionY - nextPositionsY2[i] + 300);
        sf::Vector2f allowedPosF6((i * 180) + positionX + nextPositionsX2[i] + 360, positionY - nextPositionsY2[i] + 360);
        sf::Vector2f allowedPosF7((i * 180) + positionX + nextPositionsX2[i] + 420, positionY - nextPositionsY2[i] + 420);
        /// Move backward to the left
        sf::Vector2f allowedPosB1((i * 180) + positionX + nextPositionsX2[i] + 60, positionY - nextPositionsY2[i] - 60);
        sf::Vector2f allowedPosB2((i * 180) + positionX + nextPositionsX2[i] + 120 , positionY - nextPositionsY2[i] - 120);
        sf::Vector2f allowedPosB3((i * 180) + positionX + nextPositionsX2[i] + 180, positionY - nextPositionsY2[i] - 180);
        sf::Vector2f allowedPosB4((i * 180) + positionX + nextPositionsX2[i] + 240, positionY - nextPositionsY2[i] - 240);
        sf::Vector2f allowedPosB5((i * 180) + positionX + nextPositionsX2[i] + 300, positionY - nextPositionsY2[i] - 300);
        sf::Vector2f allowedPosB6((i * 420) + positionX + nextPositionsX2[i] + 360, positionY - nextPositionsY2[i] - 360);
        sf::Vector2f allowedPosB7((i * 420) + positionX + nextPositionsX2[i] + 420, positionY - nextPositionsY2[i] - 420);
        /// Move forward to the right
        sf::Vector2f allowedPosL1((i * 180) + positionX + nextPositionsX2[i] - 60 , positionY - nextPositionsY2[i] + 60);
        sf::Vector2f allowedPosL2((i * 180) + positionX + nextPositionsX2[i] - 120 , positionY - nextPositionsY2[i] + 120);
        sf::Vector2f allowedPosL3((i * 180) + positionX + nextPositionsX2[i] - 180 , positionY - nextPositionsY2[i] + 180);
        sf::Vector2f allowedPosL4((i * 180) + positionX + nextPositionsX2[i] - 240 , positionY - nextPositionsY2[i] + 240);
        sf::Vector2f allowedPosL5((i * 180) + positionX + nextPositionsX2[i] - 300 , positionY - nextPositionsY2[i] + 300);
        sf::Vector2f allowedPosL6((i * 180) + positionX + nextPositionsX2[i] - 360 , positionY - nextPositionsY2[i] + 360);
        sf::Vector2f allowedPosL7((i * 180) + positionX + nextPositionsX2[i] - 420 , positionY - nextPositionsY2[i] + 420);
        /// Move backward the right
        sf::Vector2f allowedPosR1((i * 180) + positionX + nextPositionsX2[i] - 60 , positionY - nextPositionsY2[i] - 60);
        sf::Vector2f allowedPosR2((i * 180) + positionX + nextPositionsX2[i] - 120 , positionY - nextPositionsY2[i] - 120);
        sf::Vector2f allowedPosR3((i * 180) + positionX + nextPositionsX2[i] - 180 , positionY - nextPositionsY2[i] - 180);
        sf::Vector2f allowedPosR4((i * 180) + positionX + nextPositionsX2[i] - 240 , positionY - nextPositionsY2[i] - 240);
        sf::Vector2f allowedPosR5((i * 180) + positionX + nextPositionsX2[i] - 300 , positionY - nextPositionsY2[i] - 300);
        sf::Vector2f allowedPosR6((i * 180) + positionX + nextPositionsX2[i] - 360 , positionY - nextPositionsY2[i] - 360);
        sf::Vector2f allowedPosR7((i * 180) + positionX + nextPositionsX2[i] - 420 , positionY - nextPositionsY2[i] - 420);


        /// IF BISHOP IS IN ALLOWED POSITION, UPDATE THE NEXT POSITION ///

        /// Forward to the left
        if (pieces[i].getPosition() == allowedPosF)
        {
            nextPositionsY2[i] -= 60;
            nextPositionsX2[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPosF2)
        {
            nextPositionsY2[i] -= 120;
            nextPositionsX2[i] += 120;
        }
        else if (pieces[i].getPosition() == allowedPosF3)
        {
            nextPositionsY2[i] -= 180;
            nextPositionsX2[i] += 180;
        }
        else if (pieces[i].getPosition() == allowedPosF4)
        {
            nextPositionsY2[i] -= 240;
            nextPositionsX2[i] += 240;
        }
        else if (pieces[i].getPosition() == allowedPosF5)
        {
            nextPositionsY2[i] -= 300;
            nextPositionsX2[i] += 300;
        }
        else if (pieces[i].getPosition() == allowedPosF6)
        {
            nextPositionsY2[i] -= 360;
            nextPositionsX2[i] += 360;
        }
        else if (pieces[i].getPosition() == allowedPosF7)
        {
            nextPositionsY2[i] -= 420;
            nextPositionsX2[i] += 420;
        }

        /// Backward to the left
        else if(pieces[i].getPosition() == allowedPosB1)
        {
            nextPositionsY2[i] += 60;
            nextPositionsX2[i] += 60;
        }
        else if(pieces[i].getPosition() == allowedPosB2)
        {
            nextPositionsY2[i] += 120;
            nextPositionsX2[i] += 120;
        }
        else if(pieces[i].getPosition() == allowedPosB3)
        {
            nextPositionsY2[i] += 180;
            nextPositionsX2[i] += 180;
        }
        else if(pieces[i].getPosition() == allowedPosB4)
        {
            nextPositionsY2[i] += 240;
            nextPositionsX2[i] += 240;
        }
        else if(pieces[i].getPosition() == allowedPosB5)
        {
            nextPositionsY2[i] += 300;
            nextPositionsX2[i] += 300;
        }
        else if(pieces[i].getPosition() == allowedPosB6)
        {
            nextPositionsY2[i] += 360;
            nextPositionsX2[i] += 360;
        }
        else if(pieces[i].getPosition() == allowedPosB7)
        {
            nextPositionsY2[i] += 420;
            nextPositionsX2[i] += 420;
        }

        /// Forward to the right
        else if(pieces[i].getPosition() == allowedPosL1)
        {
            nextPositionsX2[i] -= 60;
            nextPositionsY2[i] -= 60;
        }
        else if(pieces[i].getPosition() == allowedPosL2)
        {
            nextPositionsX2[i] -= 120;
            nextPositionsY2[i] -= 120;
        }
        else if(pieces[i].getPosition() == allowedPosL3)
        {
            nextPositionsX2[i] -= 180;
            nextPositionsY2[i] -= 180;
        }
        else if(pieces[i].getPosition() == allowedPosL4)
        {
            nextPositionsX2[i] -= 240;
            nextPositionsY2[i] -= 180;
        }
        else if(pieces[i].getPosition() == allowedPosL5)
        {
            nextPositionsX2[i] -= 300;
            nextPositionsY2[i] -= 300;
        }
        else if(pieces[i].getPosition() == allowedPosL6)
        {
            nextPositionsX2[i] -= 360;
            nextPositionsY2[i] -= 360;
        }
        else if(pieces[i].getPosition() == allowedPosL7)
        {
            nextPositionsX2[i] -= 420;
            nextPositionsY2[i] -= 420;
        }

        /// Backward to the right
        else if(pieces[i].getPosition() == allowedPosR1)
        {
            nextPositionsX2[i] -= 60;
            nextPositionsY2[i] += 60;
        }
        else if(pieces[i].getPosition() == allowedPosR2)
        {
            nextPositionsX2[i] -= 120;
            nextPositionsY2[i] += 120;
        }
        else if(pieces[i].getPosition() == allowedPosR3)
        {
            nextPositionsX2[i] -= 180;
            nextPositionsY2[i] += 180;
        }
        else if(pieces[i].getPosition() == allowedPosR4)
        {
            nextPositionsX2[i] -= 240;
            nextPositionsY2[i] += 240;
        }
        else if(pieces[i].getPosition() == allowedPosR5)
        {
            nextPositionsX2[i] -= 300;
            nextPositionsY2[i] -= 300;
        }
        else if(pieces[i].getPosition() == allowedPosR6)
        {
            nextPositionsX2[i] += 360;
            nextPositionsY2[i] += 360;
        }
        else if(pieces[i].getPosition() == allowedPosR7)
        {
            nextPositionsX2[i] -= 420;
            nextPositionsY2[i] += 420;
        }

        /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
        else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
        {
            pieces[i].setPosition(latestPosition2[i]);
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR BLACK BISHOP ///
void Bishop::blackPieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
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

