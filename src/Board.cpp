#include "Board.h"
#include <SFML/Graphics.hpp>

/// DEFAULT CONSTRUCTOR ///
Board::Board()
{
    columnsOfSquares = 4;
    rowsOfSquares = 4;
}

/// FUNCTION TO DRAW THE BOARD ///
void Board::drawBoard(sf::RenderWindow& window, sf::RectangleShape& greenRectangle,
               sf::RectangleShape& whiteRectangle)
{
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






