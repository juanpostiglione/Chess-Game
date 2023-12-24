#include "Piece.h"
#include <SFML/Graphics.hpp>

/// FUNCTION TO DRAW PAWNS ///
void Pawn::draw(sf::RenderWindow& window, bool pawnSelected, bool pawnReleased,
          vector<sf::Sprite>& pawns, const sf::Vector2i& mouse, int positionX, int positionY) const
{
    /// IF PAWN IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < pawns.size(); i++)
    {
        if (pawnSelected && pawns[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            pawns[i].setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(pawns[i]);
        }
        /// OTHER PAWNS REMAIN VISIBLE ///
        else
        {
            window.draw(pawns[i]);
        }

        /// IF PAWN IS RELEASED, IS STILL VISIBLE && PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        if (pawnReleased)
        {
            const int centerPoint = 20;
            int snappedX = static_cast<int>((pawns[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
            int snappedY = static_cast<int>((pawns[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
            pawns[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

            window.draw(pawns[i]);
        }

        /// DRAW PAWNS FROM THE BEGINNING ///
        if (!pawnReleased && !pawnSelected)
        {
            pawns[i].setPosition((i * 60) + positionX, positionY);
            window.draw(pawns[i]);
        }
    }
}

/// FUNCTION TO MOVE PAWNS ///
void Pawn::move(sf::Event& event, sf::RenderWindow& gameWindow,
          vector<sf::Sprite>& pawns, bool& pawn_selected, bool& pawn_released) const
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        for (int i = 0; i < pawns.size(); i++)
        {
            /// IF A PIECE IS CLICKED ///
            if (pawns[i].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                pawn_selected = true;
                pawn_released = false;
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && pawn_selected)
    {
        pawn_selected = false;
        pawn_released = true;
    }
}

/// FUNCTION TO DRAW ROOKS ///
void Rook::draw(sf::RenderWindow& window, bool rookSelected, bool rookReleased,
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

        /// IF ROOK IS RELEASED, IS STILL VISIBLE && PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        if (rookReleased)
        {
            const int centerPoint = 20;
            int snappedX = static_cast<int>((rooks[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
            int snappedY = static_cast<int>((rooks[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
            rooks[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

            window.draw(rooks[i]);
        }

        /// DRAW ROOKS FROM THE BEGINNING ///
        if (!rookReleased && !rookSelected)
        {
            rooks[i].setPosition((i * 420) + positionX, positionY);
            window.draw(rooks[i]);
        }
    }
}

/// FUNCTION TO MOVE ROOKS ///
void Rook::move(sf::Event& event, sf::RenderWindow& gameWindow,
                vector<sf::Sprite>& rooks, bool& rook_selected, bool& rook_released) const
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        for (int i = 0; i < rooks.size(); i++)
        {
            /// IF A PIECE IS CLICKED ///
            if (rooks[i].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                rook_selected = true;
                rook_released = false;
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && rook_selected)
    {
        rook_selected = false;
        rook_released = true;
    }
}

/// FUNCTION TO DRAW KNIGHTS ///
void Knight::draw(sf::RenderWindow& window, bool knightSelected, bool knightReleased,
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

        /// IF KNIGHT IS RELEASED, IS STILL VISIBLE && PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        if (knightReleased)
        {
            const int centerPoint = 20;
            int snappedX = static_cast<int>((knights[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
            int snappedY = static_cast<int>((knights[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
            knights[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

            window.draw(knights[i]);
        }

        /// DRAW KNIGHTS FROM THE BEGINNING ///
        if (!knightReleased && !knightSelected)
        {
            knights[i].setPosition((i * 300) + positionX, positionY);
            window.draw(knights[i]);
        }
    }
}

/// FUNCTION TO MOVE KNIGHTS ///
void Knight::move(sf::Event& event, sf::RenderWindow& gameWindow,
                vector<sf::Sprite>& knights, bool& knight_selected, bool& knight_released) const
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        for (int i = 0; i < knights.size(); i++)
        {
            /// IF A PIECE IS CLICKED ///
            if (knights[i].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                knight_selected = true;
                knight_released = false;
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && knight_selected)
    {
        knight_selected = false;
        knight_released = true;
    }
}

/// FUNCTION TO DRAW BISHOPS ///
void Bishop::draw(sf::RenderWindow& window, bool bishopSelected, bool bishopReleased,
                  vector<sf::Sprite>& bishops, const sf::Vector2i& mouse, int positionX, int positionY) const
{
    /// IF BISHOPS IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    for (int i = 0; i < bishops.size(); i++)
    {
        if (bishopSelected && bishops[i].getGlobalBounds().contains(window.mapPixelToCoords(mouse)))
        {
            bishops[i].setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            window.draw(bishops[i]);
        }
        else
        {
            window.draw(bishops[i]);
        }

        /// IF BISHOP IS RELEASED, IS STILL VISIBLE && PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        if (bishopReleased)
        {
            const int centerPoint = 20;
            int snappedX = static_cast<int>((bishops[i].getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
            int snappedY = static_cast<int>((bishops[i].getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
            bishops[i].setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

            window.draw(bishops[i]);
        }

        /// DRAW BISHOPS FROM THE BEGINNING ///
        if (!bishopReleased && !bishopSelected)
        {
            bishops[i].setPosition((i * 180) + positionX, positionY);
            window.draw(bishops[i]);
        }
    }
}

/// FUNCTION TO MOVE KNIGHTS ///
void Bishop::move(sf::Event& event, sf::RenderWindow& gameWindow,
                  vector<sf::Sprite>& bishops, bool& bishop_selected, bool& bishop_released) const
{
    /// WHEN SOMETHING IS CLICKED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        for (int i = 0; i < bishops.size(); i++)
        {
            /// IF A PIECE IS CLICKED ///
            if (bishops[i].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                bishop_selected = true;
                bishop_released = false;
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && bishop_selected)
    {
        bishop_selected = false;
        bishop_released = true;
    }
}

/// FUNCTION TO DRAW KINGS ///
void King::draw(sf::RenderWindow& window, bool kingSelected, bool kingReleased,
                  sf::Sprite& kings, const sf::Vector2i& mouse, int positionX, int positionY) const
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

        /// IF KING IS RELEASED, IS STILL VISIBLE && PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        if (kingReleased)
        {
            const int centerPoint = 20;
            int snappedX = static_cast<int>((kings.getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
            int snappedY = static_cast<int>((kings.getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
            kings.setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

            window.draw(kings);
        }

        /// DRAW KINGS FROM THE BEGINNING ///
        if (!kingReleased && !kingSelected)
        {
            kings.setPosition((i * 180) + positionX, positionY);
            window.draw(kings);
        }
    }
}

/// FUNCTION TO MOVE KNIGHTS ///
void King::move(sf::Event& event, sf::RenderWindow& gameWindow,
                  sf::Sprite& kings, bool& king_selected, bool& king_released) const
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
            if (kings.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                king_selected = true;
                king_released = false;
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && king_selected)
    {
        king_selected = false;
        king_released = true;
    }
}

/// FUNCTION TO DRAW QUEEN ///
void Queen::draw(sf::RenderWindow& window, bool queenSelected, bool queenReleased,
                sf::Sprite& queens, const sf::Vector2i& mouse, int positionX, int positionY) const
{
    /// IF QUEEN IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
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

        /// IF QUEEN IS RELEASED, IS STILL VISIBLE && PLACED AUTOMATICALLY IN THE CENTER OF A SQUARE ///
        if (queenReleased)
        {
            const int centerPoint = 20;
            int snappedX = static_cast<int>((queens.getPosition().x + 0.5 * centerPoint) / centerPoint) * centerPoint;
            int snappedY = static_cast<int>((queens.getPosition().y + 0.5 * centerPoint) / centerPoint) * centerPoint;
            queens.setPosition(static_cast<float>(snappedX), static_cast<float>(snappedY));

            window.draw(queens);
        }

        /// DRAW QUEENS FROM THE BEGINNING ///
        if (!queenReleased && !queenSelected)
        {
            queens.setPosition((i * 180) + positionX, positionY);
            window.draw(queens);
        }
    }
}

/// FUNCTION TO MOVE QUEENS ///
void Queen::move(sf::Event& event, sf::RenderWindow& gameWindow,
                sf::Sprite& queens, bool& queen_selected, bool& queen_released) const
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
            if (queens.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
            {
                queen_selected = true;
                queen_released = false;
            }
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased && queen_selected)
    {
        queen_selected = false;
        queen_released = true;
    }
}
