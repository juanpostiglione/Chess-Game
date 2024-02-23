#include <SFML/Graphics.hpp>
class Board {

    /// BOARD DIMENSIONS ///
    int columnsOfSquares;
    int rowsOfSquares;

public:
    /// DEFAULT CONSTRUCTOR ///
    Board();

    /// FUNCTION TO DRAW THE BOARD ///
    void drawBoard(sf::RenderWindow& window, sf::RectangleShape& greenRectangle, sf::RectangleShape& whiteRectangle);
};



