#include "Board.h"
#include <SFML/Graphics.hpp>

Board::Board()
{
    columnsOfSquares = 4;
    rowsOfSquares = 4;
}

Board::Board(int columnsOfSquares, int rowsOfSquares)
{
    this->columnsOfSquares = columnsOfSquares;
    this->rowsOfSquares = rowsOfSquares;
}

/// FUNCTION TO DRAW THE BOARD ///
void Board::drawBoard(sf::RenderWindow& window, sf::RectangleShape& greenRectangle,
               sf::RectangleShape& whiteRectangle)
{
    /// SET THE COLUMNS AND ROWS ///
    Board(4,4);

    /// CREATE THE BOARD ///
    for(int i = 0; i < columnsOfSquares; i++)
    {
        for(int j = 0; j < rowsOfSquares;j++)
        {
            /// POSITION OF SQUARES IN THE BOARD ///
            greenRectangle.setPosition((i * 120 )+160, (j * 120)+120);
            window.draw(greenRectangle);

            whiteRectangle.setPosition((i * 120 )+220, (j * 120)+120);
            window.draw(whiteRectangle);

            whiteRectangle.setPosition((i * 120 )+160, (j * 120)+60);
            window.draw(whiteRectangle);

            greenRectangle.setPosition((i * 120 )+220, (j * 120)+60);
            window.draw(greenRectangle);
        }
    }
}

/// FUNCTION TO DRAW THE PIECES ///
void Board::drawPieces(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
                       sf::Sprite& piece, const sf::Vector2i &mouse, int positionX, int positionY)
{

    /// IF BLACK PAWN 1 IS SELECTED, IT CAN BE SEEN WHILE IS BEING MOVED ///
    if (pieceSelected)
    {
        piece.setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
        window.draw(piece);
    }

    /// IF BLACK PAWN 1 IS RELEASED, IS STILL VISIBLE ///
    else if (pieceReleased)
    {
        window.draw(piece);
    }

    /// DRAW PAWN BLACK 1 FROM THE BEGINNING ///
    if(!pieceReleased && !pieceSelected)
    {
        for(int i = 0; i < 1; i++)
        {
            for(int j = 0; j < 1; j++)
            {
                piece.setPosition((i * 120 )+ positionX, (j * 120)+ positionY);
                window.draw(piece);
            }
        }
    }
}

/// FUNCTION FOR MOVEMENT OF PIECES ///
void Board::movementPiece(sf::Event& event, sf::RenderWindow& gameWindow,
                          sf::Sprite& pieceSprite, bool& piece_selected, bool& piece_released)
{
    /// WHEN SOMETHING IS CLICKED ///
    if(event.type == sf::Event::MouseButtonPressed)
    {
        /// VECTOR FOR MOUSE ///
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(gameWindow);

        /// IF A PIECE IS CLICKED ///
        if (pieceSprite.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
        {
            piece_selected = true;
            piece_released = false;
        }
    }

    /// IF CLICK IS RELEASED ///
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (piece_selected == true)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            pieceSprite.setPosition(static_cast<float>(mouse.x - 30), static_cast<float>(mouse.y - 30));
            piece_selected = false;
            piece_released = true;
        }
    }
}
