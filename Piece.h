#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/// BASE CLASS OF PIECES ///
class Piece{
public:
    /// FUNCTION TO MOVE AND DRAW THE PIECE ///
    virtual void move(sf::RenderWindow& window, bool pieceSelected, bool pieceReleased,
              vector<sf::Sprite>& piece, const sf::Vector2i& mouse, int positionX, int positionY) const = 0;

    /// FUNCTION TO SET THE STATE OF THE PIECE ///
    virtual void pieceState(sf::Event& event, sf::RenderWindow& gameWindow,
                      vector<sf::Sprite>& pieces, bool& piece_selected, bool& piece_released) const = 0;

};

/// CLASS FOR PAWN ///
class Pawn : public Piece /// Inherit from Piece Class
{
public:
    
    void move(sf::RenderWindow& window, bool pawnSelected, bool pawnReleased,
              vector<sf::Sprite>& pawns, const sf::Vector2i& mouse, int positionX, int positionY) const override;
    
    void pieceState(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& pawns, bool& pawn_selected, bool& pawn_released) const override;

};

/// CLAS FOR ROOK ///
class Rook : public Piece /// Inherit from Piece Class
{
public:
    
    void move(sf::RenderWindow& window, bool rookSelected, bool rookReleased,
              vector<sf::Sprite>& rooks, const sf::Vector2i& mouse, int positionX, int positionY) const override;
    
    void pieceState(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& rooks, bool& rook_selected, bool& rook_released) const override;
};

/// CLASS FOR KNIGHT ///
class Knight : public Piece /// Inherit from Piece Class
{
public:
    
    void move(sf::RenderWindow& window, bool knightSelected, bool knightReleased,
              vector<sf::Sprite>& knights, const sf::Vector2i& mouse, int positionX, int positionY) const override;
    
    void pieceState(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& knights, bool& knights_selected, bool& knights_released) const override;
};

/// CLASS FOR BISHOP ///
class Bishop : public Piece /// Inherit from Piece Class
{
public:
    
    void move(sf::RenderWindow& window, bool bishopSelected, bool bishopReleased,
              vector<sf::Sprite>& bishops, const sf::Vector2i& mouse, int positionX, int positionY) const override;
    
    void pieceState(sf::Event& event, sf::RenderWindow& gameWindow,
              vector<sf::Sprite>& bishops, bool& bishop_selected, bool& bishop_released) const override;
};

/// CLASS FOR KING ///
class King
{
public:
    
    void move(sf::RenderWindow& window, bool kingSelected, bool kingReleased,
              sf::Sprite& kings, const sf::Vector2i& mouse, int positionX, int positionY) const;
    
    void pieceState(sf::Event& event, sf::RenderWindow& gameWindow,
              sf::Sprite& kings, bool& king_selected, bool& king_released) const;

};

/// CLASS FOR QUEEN ///
class Queen
{
public:
    
    void move(sf::RenderWindow& window, bool queenSelected, bool queenReleased,
              sf::Sprite& queens, const sf::Vector2i& mouse, int positionX, int positionY) const;
    
    void pieceState(sf::Event& event, sf::RenderWindow& gameWindow,
              sf::Sprite& queens, bool& queen_selected, bool& queen_released) const;

};
