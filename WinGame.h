#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class WinGame {
private:

    /// WIN WINDOW DIMENSIONS ///
    int width;
    int height;
public:

    /// DEFAULT CONSTRUCTOR ///
    WinGame();

    /// FUNCTION TO CAPTURE PIECES VECTORS EXCEPT KING AND QUEEN ///
    void capturePiece(sf::Event& event, sf::RenderWindow& gameWindow,
                  vector<sf::Sprite>& piece, vector<sf::Sprite>& chosePiece);

    /// FUNCTION TO THAT ALLOWS PIECES VECTORS TO CAPTURE KINGS AND QUEENS
    void capturePiece2(sf::Event& event, sf::RenderWindow& gameWindow,
                   sf::Sprite& sprite, vector<sf::Sprite>& chosePiece, sf::Mouse::Button mouseButton1, sf::Mouse::Button mouseButton2);

    /// FUNCTIONS THAT ALLOWS BLACK KINGS AND BLACK QUEENS BE CAPTURED BY WHITE KINGS AND WHITE QUEENS AND VICE VERSA ///
    void capturePiece3(sf::Event& event, sf::RenderWindow& gameWindow,
                   sf::Sprite& sprite, sf::Sprite& chosePiece);

    /// FUNCTION TO DETERMINE IF A KING WAS SENT OUT OF THE BOARD BY ANY PIECE EXCEPT ANOTHER KING OR A QUEEN
    void isKingOutOfBoard(sf::Event& event, sf::RenderWindow& gameWindow,sf::Sprite& sprite,vector<sf::Sprite>& pieces, sf::Mouse::Button mouseButton);

    /// FUNCTION TO DETERMINE IF KING WAS SENT OUT OF THE BOARD BY ANOTHER KING AND A QUEEN
    void isKingOutOfBoard2(sf::Event& event, sf::RenderWindow& gameWindow,sf::Sprite& sprite,sf::Sprite& chosenPiece, sf::Mouse::Button mouseButton);

    /// FUNCTION TO DISPLAY WIN WINDOW ///
    void winWindow(sf::Mouse::Button mouseButton);

    /// SET TEXT TO THE CENTER ///
    void setText(sf::Text &text, float x, float y);

};
