#include <SFML/Graphics.hpp>
#include "GameWindow.h"
class Board {

    int columnsOfSquares;
    int rowsOfSquares;

public:
    /// DEFAULT CONSTRUCTOR ///
    Board();

    /// FUNCTION TO DRAW THE BOARD ///
    void drawBoard(sf::RenderWindow& window, sf::RectangleShape& greenRectangle, sf::RectangleShape& whiteRectangle);
};
