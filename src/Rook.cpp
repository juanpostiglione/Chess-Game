#include "Rook.h"

/// FUNCTION TO DRAW AND MOVE ROOKS ///
void Rook::move(sf::RenderWindow& window, bool rookSelected, bool rookReleased,
                vector<sf::Sprite>& rooks, const sf::Vector2i& mouse, int positionX, int positionY) const
{
    /// IF ROOK IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < rooks.size(); i++)
    {
        if (rookSelected && rooks[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            rooks[i].setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(rooks[i]);
        }
        else
        {
            window.draw(rooks[i]);
        }

        /// IF ROOK IS RELEASED, IS PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        const int centerPoint = 20;
        int snappedX = static_cast<int>((rooks[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
        int snappedY = static_cast<int>((rooks[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
        rooks[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

        /// DRAW ROOKS FROM THE BEGINNING ///
        if (!rookReleased && !rookSelected)
        {
            rooks[i].setPosition(static_cast<float>((i * 420) + positionX), static_cast<float>(positionY));
        }
    }
}

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE ROOK ///
void Rook::whitePieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                                vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// ----- ALLOWED POSITIONS TO MOVE ----- ///

        /// Move forward
        sf::Vector2f allowedPosF((i * 420) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 60);
        sf::Vector2f allowedPosF2((i * 420) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 120);
        sf::Vector2f allowedPosF3((i * 420) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 180);
        sf::Vector2f allowedPosF4((i * 420) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 240);
        sf::Vector2f allowedPosF5((i * 420) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 300);
        sf::Vector2f allowedPosF6((i * 420) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 360);
        sf::Vector2f allowedPosF7((i * 420) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 420);
        /// Move backward
        sf::Vector2f allowedPosB1((i * 420) + positionX + nextPositionsX[i] , positionY - nextPositionsY[i] + 60);
        sf::Vector2f allowedPosB2((i * 420) + positionX + nextPositionsX[i] , positionY - nextPositionsY[i] + 120);
        sf::Vector2f allowedPosB3((i * 420) + positionX + nextPositionsX[i] , positionY - nextPositionsY[i] + 180);
        sf::Vector2f allowedPosB4((i * 420) + positionX + nextPositionsX[i] , positionY - nextPositionsY[i] + 240);
        sf::Vector2f allowedPosB5((i * 420) + positionX + nextPositionsX[i] , positionY - nextPositionsY[i] + 300);
        sf::Vector2f allowedPosB6((i * 420) + positionX + nextPositionsX[i] , positionY - nextPositionsY[i] + 360);
        sf::Vector2f allowedPosB7((i * 420) + positionX + nextPositionsX[i] , positionY - nextPositionsY[i] + 420);
        /// Move to the left
        sf::Vector2f allowedPosL1((i * 420) + positionX + nextPositionsX[i] - 60 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosL2((i * 420) + positionX + nextPositionsX[i] - 120 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosL3((i * 420) + positionX + nextPositionsX[i] - 180 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosL4((i * 420) + positionX + nextPositionsX[i] - 240 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosL5((i * 420) + positionX + nextPositionsX[i] - 300 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosL6((i * 420) + positionX + nextPositionsX[i] - 360 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosL7((i * 420) + positionX + nextPositionsX[i] - 420 , positionY - nextPositionsY[i]);
        /// Move to the right
        sf::Vector2f allowedPosR1((i * 420) + positionX + nextPositionsX[i] + 60 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosR2((i * 420) + positionX + nextPositionsX[i] + 120 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosR3((i * 420) + positionX + nextPositionsX[i] + 180 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosR4((i * 420) + positionX + nextPositionsX[i] + 240 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosR5((i * 420) + positionX + nextPositionsX[i] + 300 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosR6((i * 420) + positionX + nextPositionsX[i] + 360 , positionY - nextPositionsY[i]);
        sf::Vector2f allowedPosR7((i * 420) + positionX + nextPositionsX[i] + 420 , positionY - nextPositionsY[i]);


        /// IF ROOK IS IN ALLOWED POSITION, UPDATE THE NEXT POSITION ///

        /// Forward
        if (pieces[i].getPosition() == allowedPosF)
        {
            nextPositionsY[i] += 60;
        }
        else if (pieces[i].getPosition() == allowedPosF2)
        {
            nextPositionsY[i] += 120;
        }
        else if (pieces[i].getPosition() == allowedPosF3)
        {
            nextPositionsY[i] += 180;
        }
        else if (pieces[i].getPosition() == allowedPosF4)
        {
            nextPositionsY[i] += 240;
        }
        else if (pieces[i].getPosition() == allowedPosF5)
        {
            nextPositionsY[i] += 300;
        }
        else if (pieces[i].getPosition() == allowedPosF6)
        {
            nextPositionsY[i] += 360;
        }
        else if (pieces[i].getPosition() == allowedPosF7)
        {
            nextPositionsY[i] += 420;
        }

        /// Right
        else if(pieces[i].getPosition() == allowedPosR1)
        {
            nextPositionsX[i] += 60;
        }
        else if(pieces[i].getPosition() == allowedPosR2)
        {
            nextPositionsX[i] += 120;
        }
        else if(pieces[i].getPosition() == allowedPosR3)
        {
            nextPositionsX[i] += 180;
        }
        else if(pieces[i].getPosition() == allowedPosR4)
        {
            nextPositionsX[i] += 240;
        }
        else if(pieces[i].getPosition() == allowedPosR5)
        {
            nextPositionsX[i] += 300;
        }
        else if(pieces[i].getPosition() == allowedPosR6)
        {
            nextPositionsX[i] += 360;
        }
        else if(pieces[i].getPosition() == allowedPosR7)
        {
            nextPositionsX[i] += 420;
        }

        /// Left
        else if(pieces[i].getPosition() == allowedPosL1)
        {
            nextPositionsX[i] -= 60;
        }
        else if(pieces[i].getPosition() == allowedPosL2)
        {
            nextPositionsX[i] -= 120;
        }
        else if(pieces[i].getPosition() == allowedPosL3)
        {
            nextPositionsX[i] -= 180;
        }
        else if(pieces[i].getPosition() == allowedPosL4)
        {
            nextPositionsX[i] -= 240;
        }
        else if(pieces[i].getPosition() == allowedPosL5)
        {
            nextPositionsX[i] -= 300;
        }
        else if(pieces[i].getPosition() == allowedPosL6)
        {
            nextPositionsX[i] -= 360;
        }
        else if(pieces[i].getPosition() == allowedPosL7)
        {
            nextPositionsX[i] -= 420;
        }

        /// Backward
        else if(pieces[i].getPosition() == allowedPosB1)
        {
            nextPositionsY[i] -= 60;
        }
        else if(pieces[i].getPosition() == allowedPosB2)
        {
            nextPositionsY[i] -= 120;
        }
        else if(pieces[i].getPosition() == allowedPosB3)
        {
            nextPositionsY[i] -= 180;
        }
        else if(pieces[i].getPosition() == allowedPosB4)
        {
            nextPositionsY[i] -= 240;
        }
        else if(pieces[i].getPosition() == allowedPosB5)
        {
            nextPositionsY[i] -= 300;
        }
        else if(pieces[i].getPosition() == allowedPosB6)
        {
            nextPositionsY[i] -= 360;
        }
        else if(pieces[i].getPosition() == allowedPosB7)
        {
            nextPositionsY[i] -= 420;
        }

        /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
        else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
        {
            pieces[i].setPosition(latestPosition[i]);
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR WHITE ROOK ///
void Rook::whitePieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
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

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK ROOK ///
void Rook::blackPieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                                vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// ----- ALLOWED POSITIONS TO MOVE ----- ///

        /// Move forward
        sf::Vector2f allowedPosF((i * 420) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 60);
        sf::Vector2f allowedPosF2((i * 420) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 120);
        sf::Vector2f allowedPosF3((i * 420) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 180);
        sf::Vector2f allowedPosF4((i * 420) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 240);
        sf::Vector2f allowedPosF5((i * 420) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 300);
        sf::Vector2f allowedPosF6((i * 420) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 360);
        sf::Vector2f allowedPosF7((i * 420) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 420);
        /// Move backward
        sf::Vector2f allowedPosB1((i * 420) + positionX + nextPositionsX2[i] , positionY - nextPositionsY2[i] - 60);
        sf::Vector2f allowedPosB2((i * 420) + positionX + nextPositionsX2[i] , positionY - nextPositionsY2[i] - 120);
        sf::Vector2f allowedPosB3((i * 420) + positionX + nextPositionsX2[i] , positionY - nextPositionsY2[i] - 180);
        sf::Vector2f allowedPosB4((i * 420) + positionX + nextPositionsX2[i] , positionY - nextPositionsY2[i] - 240);
        sf::Vector2f allowedPosB5((i * 420) + positionX + nextPositionsX2[i] , positionY - nextPositionsY2[i] - 300);
        sf::Vector2f allowedPosB6((i * 420) + positionX + nextPositionsX2[i] , positionY - nextPositionsY2[i] - 360);
        sf::Vector2f allowedPosB7((i * 420) + positionX + nextPositionsX2[i] , positionY - nextPositionsY2[i] - 420);
        /// Move to the right
        sf::Vector2f allowedPosL1((i * 420) + positionX + nextPositionsX2[i] + 60 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosL2((i * 420) + positionX + nextPositionsX2[i] + 120 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosL3((i * 420) + positionX + nextPositionsX2[i] + 180 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosL4((i * 420) + positionX + nextPositionsX2[i] + 240 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosL5((i * 420) + positionX + nextPositionsX2[i] + 300 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosL6((i * 420) + positionX + nextPositionsX2[i] + 360 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosL7((i * 420) + positionX + nextPositionsX2[i] + 420 , positionY - nextPositionsY2[i]);
        /// Move to the left
        sf::Vector2f allowedPosR1((i * 420) + positionX + nextPositionsX2[i] - 60 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosR2((i * 420) + positionX + nextPositionsX2[i] - 120 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosR3((i * 420) + positionX + nextPositionsX2[i] - 180 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosR4((i * 420) + positionX + nextPositionsX2[i] - 240 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosR5((i * 420) + positionX + nextPositionsX2[i] - 300 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosR6((i * 420) + positionX + nextPositionsX2[i] - 360 , positionY - nextPositionsY2[i]);
        sf::Vector2f allowedPosR7((i * 420) + positionX + nextPositionsX2[i] - 420 , positionY - nextPositionsY2[i]);


        /// IF ROOK IS IN ALLOWED POSITION, UPDATE THE NEXT POSITION ///
        /// Forward
        if (pieces[i].getPosition() == allowedPosF)
        {
            nextPositionsY2[i] -= 60;
        }
        else if (pieces[i].getPosition() == allowedPosF2)
        {
            nextPositionsY2[i] -= 120;
        }
        else if (pieces[i].getPosition() == allowedPosF3)
        {
            nextPositionsY2[i] -= 180;
        }
        else if (pieces[i].getPosition() == allowedPosF4)
        {
            nextPositionsY2[i] -= 240;
        }
        else if (pieces[i].getPosition() == allowedPosF5)
        {
            nextPositionsY2[i] -= 300;
        }
        else if (pieces[i].getPosition() == allowedPosF6)
        {
            nextPositionsY2[i] -= 360;
        }
        else if (pieces[i].getPosition() == allowedPosF7)
        {
            nextPositionsY2[i] -= 420;
        }

        /// Right
        else if(pieces[i].getPosition() == allowedPosR1)
        {
            nextPositionsX2[i] -= 60;
        }
        else if(pieces[i].getPosition() == allowedPosR2)
        {
            nextPositionsX2[i] -= 120;
        }
        else if(pieces[i].getPosition() == allowedPosR3)
        {
            nextPositionsX2[i] -= 180;
        }
        else if(pieces[i].getPosition() == allowedPosR4)
        {
            nextPositionsX2[i] -= 240;
        }
        else if(pieces[i].getPosition() == allowedPosR5)
        {
            nextPositionsX2[i] -= 300;
        }
        else if(pieces[i].getPosition() == allowedPosR6)
        {
            nextPositionsX2[i] -= 360;
        }
        else if(pieces[i].getPosition() == allowedPosR7)
        {
            nextPositionsX2[i] -= 420;
        }

        /// Left
        else if(pieces[i].getPosition() == allowedPosL1)
        {
            nextPositionsX2[i] += 60;
        }
        else if(pieces[i].getPosition() == allowedPosL2)
        {
            nextPositionsX2[i] += 120;
        }
        else if(pieces[i].getPosition() == allowedPosL3)
        {
            nextPositionsX2[i] += 180;
        }
        else if(pieces[i].getPosition() == allowedPosL4)
        {
            nextPositionsX2[i] += 240;
        }
        else if(pieces[i].getPosition() == allowedPosL5)
        {
            nextPositionsX2[i] += 300;
        }
        else if(pieces[i].getPosition() == allowedPosL6)
        {
            nextPositionsX2[i] += 360;
        }
        else if(pieces[i].getPosition() == allowedPosL7)
        {
            nextPositionsX2[i] += 420;
        }

        /// Backward
        else if(pieces[i].getPosition() == allowedPosB1)
        {
            nextPositionsY2[i] += 60;
        }
        else if(pieces[i].getPosition() == allowedPosB2)
        {
            nextPositionsY2[i] += 120;
        }
        else if(pieces[i].getPosition() == allowedPosB3)
        {
            nextPositionsY2[i] += 180;
        }
        else if(pieces[i].getPosition() == allowedPosB4)
        {
            nextPositionsY2[i] += 240;
        }
        else if(pieces[i].getPosition() == allowedPosB5)
        {
            nextPositionsY2[i] += 300;
        }
        else if(pieces[i].getPosition() == allowedPosB6)
        {
            nextPositionsY2[i] += 360;
        }
        else if(pieces[i].getPosition() == allowedPosB7)
        {
            nextPositionsY2[i] += 420;
        }

        /// IF IS NOT IN ALLOWED POSITION, RETURN TO ITS LATEST POSITION ///
        else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
        {
            pieces[i].setPosition(latestPosition2[i]);
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR BLACK ROOK ///
void Rook::blackPieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
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

