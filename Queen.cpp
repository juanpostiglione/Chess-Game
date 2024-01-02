#include "Queen.h"

/// FUNCTION TO DRAW QUEENS ///
void Queen::move(sf::RenderWindow& window, bool queenSelected, bool queenReleased,
                sf::Sprite& queens, const sf::Vector2i& mouse, int positionX, int positionY)
{
    /// IF KING IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < 1; i++)
    {
        if (queenSelected && queens.getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            queens.setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(queens);
        }
        else
        {
            window.draw(queens);
        }

        /// IF KING IS RELEASED, IS PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        const int centerPoint = 20;
        int snappedX = static_cast<int>((queens.getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
        int snappedY = static_cast<int>((queens.getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
        queens.setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

        /// DRAW KINGS FROM THE BEGINNING ///
        if (!queenReleased && !queenSelected)
        {
            queens.setPosition(static_cast<float>(positionX), static_cast<float>(positionY));
        }
    }
}

/// RULE MOVEMENT FUNCTION FOR WHITE QUEEN ///
void Queen::whitePieceRule(sf::Event &event, sf::RenderWindow &gameWindow, sf::Sprite& queen,
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
        if (queen.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
        {
            piece_selected = true;
            piece_released = false;
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && piece_selected)
    {
        piece_selected = false;
        piece_released = true;

    }
}

/// RULE MOVEMENT FUNCTION FOR BLACK QUEEN ///
void Queen::blackPieceRule(sf::Event &event, sf::RenderWindow &gameWindow, sf::Sprite& queen,
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
            if (queen.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                piece_selected = true;
                piece_released = false;
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && piece_selected)
    {
        piece_selected = false;
        piece_released = true;
    }
}
