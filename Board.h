#include <SFML/Graphics.hpp>
#include "GameWindow.h"
class Board {

    int columnsOfSquares;
    int rowsOfSquares;

public:
    /// DEFAULT CONSTRUCTOR ///
    Board();
    
    /// CONSTRUCTOR FOR COLUMNS AND ROWS FOR THE BOARD ///
    Board(int columnOfSquares, int rowsOfSquares);

    /// FUNCTION TO DRAW THE BOARD ///
    void drawBoard(sf::RenderWindow& window, sf::RectangleShape& greenRectangle, sf::RectangleShape& whiteRectangle);

    /// FUNCTION TO DRAW THE PIECES ///
    void drawPieces(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,sf::Sprite& piece, const sf::Vector2i &mouse, int positionX, int positionY);

    /// FUNCTION FOR THE MOVEMENT OF PIECES ///
    void movementPiece(sf::Event& event, sf::RenderWindow& gameWindow, sf::Sprite& pieceSprite, bool& piece_selected, bool& piece_released);
};
