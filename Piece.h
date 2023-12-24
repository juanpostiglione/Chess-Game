#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/// BASE CLASS OF PIECES ///
class Piece{
public:
    /// FUNCTION TO DRAW THE PIECE ///
    virtual void draw(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
              vector<sf::Sprite>& piece, const sf::Vector2i& mouse, int positionX, int positionY) const = 0;

    /// FUNCTION TO MOVE THE PIECE ///
    virtual void move(sf::Event& event, sf::RenderWindow& gameWindow,
                      vector<sf::Sprite>& pieces, bool& piece_selected, bool& piece_released) const = 0;


};

/// CLASS FOR PAWN ///
class Pawn : public Piece /// Inherit from Piece Class
{
public:

    /// DRAW PAWNS ///
    void draw(sf::RenderWindow& window, bool pawnSelected, bool pawnReleased,
              vector<sf::Sprite>& pawns, const sf::Vector2i& mouse, int positionX, int positionY) const;

    /// MOVE PAWNS ///
    void move(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& pawns, bool& pawn_selected, bool& pawn_released) const;

};

/// CLAS FOR ROOK ///
class Rook : public Piece /// Inherit from Piece Class
{
public:

    /// DRAW ROOKS ///
    void draw(sf::RenderWindow& window, bool rookSelected, bool rookReleased,
              vector<sf::Sprite>& rooks, const sf::Vector2i& mouse, int positionX, int positionY) const;

    /// MOVE ROOKS ///
    void move(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& rooks, bool& rook_selected, bool& rook_released) const;
};

/// CLASS FOR KNIGHT ///
class Knight : public Piece /// Inherit from Piece Class
{
public:

    /// DRAW KNIGHTS ///
    void draw(sf::RenderWindow& window, bool knightSelected, bool knightReleased,
              vector<sf::Sprite>& knights, const sf::Vector2i& mouse, int positionX, int positionY) const;

    /// MOVE KNIGHTS ///
    void move(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& knights, bool& knights_selected, bool& knights_released) const;
};

/// CLASS FOR BISHOP ///
class Bishop : public Piece /// Inherit from Piece Class
{
public:

    /// DRAW BISHOPS ///
    void draw(sf::RenderWindow& window, bool bishopSelected, bool bishopReleased,
              vector<sf::Sprite>& bishops, const sf::Vector2i& mouse, int positionX, int positionY) const;

    /// MOVE BISHOPS ///
    void move(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& bishops, bool& bishop_selected, bool& bishop_released) const;
};

/// CLASS FOR KING ///
class King
{
public:

    /// DRAW KINGS ///
    void draw(sf::RenderWindow& window, bool kingSelected, bool kingReleased,
              sf::Sprite& kings, const sf::Vector2i& mouse, int positionX, int positionY) const;

    /// MOVE KINGS ///
    void move(sf::Event& event, sf::RenderWindow& gameWindow,
              sf::Sprite& kings, bool& king_selected, bool& king_released) const;

};

/// CLASS FOR QUEEN ///
class Queen
{
public:

    /// DRAW QUEENS ///
    void draw(sf::RenderWindow& window, bool queenSelected, bool queenReleased,
              sf::Sprite& queens, const sf::Vector2i& mouse, int positionX, int positionY) const;

    /// MOVE QUEENS ///
    void move(sf::Event& event, sf::RenderWindow& gameWindow,
              sf::Sprite& queens, bool& queen_selected, bool& queen_released) const;

};
