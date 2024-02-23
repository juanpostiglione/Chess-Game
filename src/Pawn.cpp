#include "Pawn.h"

/// FUNCTION TO MOVE PAWNS ///
void Pawn::move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
                vector<sf::Sprite>& pawns, const sf::Vector2i& mouse, int positionX, int positionY) const
{

    /// IF PAWN IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < pawns.size(); i++)
    {
        if (pieceSelected && pawns[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            pawns[i].setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(pawns[i]);
        }

            /// OTHER PAWNS REMAIN VISIBLE ///
        else
        {
            window.draw(pawns[i]);
        }

        /// IF PAWN IS RELEASED, IS PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        int centerPoint = 20;
        int snappedX = static_cast<int>((pawns[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
        int snappedY = static_cast<int>((pawns[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
        pawns[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

        /// SET POSITION PAWNS FROM THE BEGINNING ///
        if (!pieceReleased && !pieceSelected)
        {
            pawns[i].setPosition(static_cast<float>((i * 60) + positionX), static_cast<float>(positionY));
        }
    }
}

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR WHITE PAWN ///
void Pawn::whitePieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                               vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// CREATE POSITIONS ALLOWED IN THE BOARD ///
        sf::Vector2f allowedPos((i * 60) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 60);
        sf::Vector2f allowedPos2((i * 60) + positionX + nextPositionsX[i], positionY - nextPositionsY[i] - 120);
        sf::Vector2f allowedPos3((i * 60) + positionX + nextPositionsX[i] + 60, positionY - nextPositionsY[i] - 60);
        sf::Vector2f allowedPos4((i * 60) + positionX + nextPositionsX[i] - 60, positionY - nextPositionsY[i] - 60);


        /// IF THE PIECE IS POSITIONED IN THE ALLOWED POSITION, COUNTER INCREASE ///
        if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)) && pieces[i].getPosition() == allowedPos ||
                pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)) && pieces[i].getPosition() == allowedPos2)
        {
            counterMove[i] +=1;
        }

        /// THE FIRST MOVEMENT, THE PAWN COULD MOVE ONE OR TWO STEPS ///
        if(counterMove[i] == 1)
        {
            /// One step
            if (pieces[i].getPosition() == allowedPos)
            {
                nextPositionsY[i] += 60;
            }

            /// Two step
            else if (pieces[i].getPosition() == allowedPos2)
            {
                nextPositionsY[i] += 120;
            }

            /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos3)
            {
                nextPositionsY[i] += 60;
                nextPositionsX[i] += 60;
            }
            /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos4)
            {
                nextPositionsY[i] += 60;
                nextPositionsX[i] -= 60;
            }

            else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
            {
                pieces[i].setPosition(latestPosition[i]);
            }
        }

        /// AFTER FIRST MOVE, PAWN MOVES ONLY WITH ONE STEP ///
        else
        {
            /// One step
            if (pieces[i].getPosition() == allowedPos)
            {
                nextPositionsY[i] += 60;
            }
            /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos3)
            {
                nextPositionsY[i] += 60;
                nextPositionsX[i] += 60;
            }
            /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos4)
            {
                nextPositionsY[i] += 60;
                nextPositionsX[i] -= 60;
            }

            /// IF POSITION NOT ALLOWED, RETURN TO IS LATEST POSITION
            else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
            {
                pieces[i].setPosition(latestPosition[i]);
            }
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR WHITE PAWN ///
void Pawn::whitePieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
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
                latestPosition[i] = pieces[i].getPosition();
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

/// FUNCTION FOR MOVEMENT BEHAVIOR FOR BLACK PAWN ///
void Pawn::blackPieceBehavior(sf::RenderWindow &window, const sf::Vector2i &mouse2, int positionX, int positionY,
                               vector<sf::Sprite> &pieces) const
{
    for (int i = 0; i < pieces.size(); i++)
    {
        /// CREATE POSITIONS ALLOWED IN THE BOARD ///
        sf::Vector2f allowedPos((i * 60) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 60);
        sf::Vector2f allowedPos2((i * 60) + positionX + nextPositionsX2[i], positionY - nextPositionsY2[i] + 120);
        sf::Vector2f allowedPos3((i * 60) + positionX + nextPositionsX2[i] - 60, positionY - nextPositionsY2[i] + 60);
        sf::Vector2f allowedPos4((i * 60) + positionX + nextPositionsX2[i] + 60, positionY - nextPositionsY2[i] + 60);


        /// IF THE PIECE IS POSITIONED IN THE ALLOWED POSITION, COUNTER INCREASE ///
        if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)) && pieces[i].getPosition() == allowedPos ||
           pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)) && pieces[i].getPosition() == allowedPos2)
        {
            counterMove2[i] +=1;
        }

        /// THE FIRST MOVEMENT, THE PAWN COULD MOVE ONE OR TWO STEPS ///
        if(counterMove2[i] == 1)
        {
            /// One step
            if (pieces[i].getPosition() == allowedPos)
            {
                nextPositionsY2[i] -= 60;
            }

                /// Two step
            else if (pieces[i].getPosition() == allowedPos2)
            {
                nextPositionsY2[i] -= 120;
            }

                /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos3)
            {
                nextPositionsY2[i] -= 60;
                nextPositionsX2[i] -= 60;
            }
                /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos4)
            {
                nextPositionsY2[i] -= 60;
                nextPositionsX2[i] += 60;
            }

            else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
            {
                pieces[i].setPosition(latestPosition2[i]);
            }
        }

            /// AFTER FIRST MOVE, PAWN MOVES ONLY WITH ONE STEP ///
        else
        {
            /// One step
            if (pieces[i].getPosition() == allowedPos)
            {
                nextPositionsY2[i] += 60;
            }
                /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos3)
            {
                nextPositionsY2[i] -= 60;
                nextPositionsX2[i] -= 60;
            }
                /// Capture diagonally
            else if (pieces[i].getPosition() == allowedPos4)
            {
                nextPositionsY2[i] -= 60;
                nextPositionsX2[i] += 60;
            }

                /// IF POSITION NOT ALLOWED, RETURN TO IS LATEST POSITION
            else if(pieces[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse2)))
            {
                pieces[i].setPosition(latestPosition2[i]);
            }
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR BLACK PAWN ///
void Pawn::blackPieceRule(sf::Event &event, sf::RenderWindow &gameWindow, vector<sf::Sprite> &pieces,
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
