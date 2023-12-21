#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include"TextureManager.h"
#include"Board.h"
#include"Piece.h"

using namespace std;

/// DEFAULT CONSTRUCTOR ///
GameWindow::GameWindow()
{
   width = 800;
   height = 600;
}

/// FUNCTION TO DISPLAY GAME WINDOW ///
void GameWindow::GameWindowDisplay(Board& chessBoard, Pawn& pawnPieces, Rook& rookPieces, Knight& knightPieces, Bishop& bishopPieces, King& kingPieces, Queen& queenPieces) const
{
    /// CREATE GAME WINDOW ///
    sf::RenderWindow gameWindow(sf::VideoMode(width,height), "Chess");

    /// GREEN SQUARES ///
    sf::RectangleShape greenRectangle(sf::Vector2f(60,60));
    greenRectangle.setFillColor(sf::Color(118,150,86));

    /// WHITE SQUARES ///
    sf::RectangleShape whiteRectangle(sf::Vector2f(60,60));
    whiteRectangle.setFillColor(sf::Color(238,238,216));

    ///------- BLACK PIECES SPRITES -------///

    /// SPRITE FOR BLACK PAWN ///
    vector<sf::Sprite> blackPawns;
    sf::Texture pawn_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn_blackSprite;
    pawn_blackSprite.setTexture(pawn_blackTexture);
    bool pawnBlackSelected = false;
    bool pawnBlack_released = false;

    for(int i = 0; i < 8; i++)
    {
        blackPawns.push_back(pawn_blackSprite);
    }

    /// SPRITE FOR BLACK BISHOP ///
    vector<sf::Sprite> blackBishops;
    sf::Texture bishop_blackTexture = TextureManager::getTexture("bishop_black");
    sf::Sprite bishop_blackSprite;
    bishop_blackSprite.setTexture(bishop_blackTexture);
    bool bishopBlackSelected = false;
    bool bishopBlack_released = false;

    for(int i = 0; i < 2; i++)
    {
        blackBishops.push_back(bishop_blackSprite);
    }

    /// SPRITE FOR BLACK ROOK ///
    vector<sf::Sprite> blackRooks;
    sf::Texture rook_blackTexture = TextureManager::getTexture("rook_black");
    sf::Sprite rook_blackSprite;
    rook_blackSprite.setTexture(rook_blackTexture);
    bool rookBlackSelected = false;
    bool rookBlack_released = false;

    for(int i = 0; i < 2; i++)
    {
        blackRooks.push_back(rook_blackSprite);
    }

    /// SPRITE FOR BLACK KNIGHT ///
    vector<sf::Sprite> blackKnights;
    sf::Texture knight_blackTexture = TextureManager::getTexture("knight_black");
    sf::Sprite knight_blackSprite;
    knight_blackSprite.setTexture(knight_blackTexture);
    bool knightBlackSelected = false;
    bool knightBlack_released = false;

    for(int i = 0; i < 2; i++)
    {
        blackKnights.push_back(knight_blackSprite);
    }

    /// SPRITE FOR QUEEN ///
    sf::Texture queen_blackTexture = TextureManager::getTexture("queen_black");
    sf::Sprite queen_blackSprite;
    queen_blackSprite.setTexture(queen_blackTexture);
    bool queenBlackSelected = false;
    bool queenBlack_released = false;

    /// SPRITE FOR KING ///
    sf::Texture king_blackTexture = TextureManager::getTexture("king_black");
    sf::Sprite king_blackSprite;
    king_blackSprite.setTexture(king_blackTexture);
    bool kingBlackSelected = false;
    bool kingBlack_released = false;

    ///------- WHITE PIECES SPRITES -------///

    /// SPRITE FOR WHITE BISHOP  ///
    vector<sf::Sprite> whiteBishops;
    sf::Texture bishop_whiteTexture = TextureManager::getTexture("bishop_white");
    sf::Sprite bishop_whiteSprite;
    bishop_whiteSprite.setTexture(bishop_whiteTexture);
    bool bishopWhiteSelected = false;
    bool bishopWhite_released = false;

    for(int i = 0; i < 2; i++)
    {
        whiteBishops.push_back(bishop_whiteSprite);
    }

    /// SPRITE FOR WHITE KNIGHT ///
    vector<sf::Sprite> whiteKnights;
    sf::Texture knight_whiteTexture = TextureManager::getTexture("knight_white");
    sf::Sprite knight_whiteSprite;
    knight_whiteSprite.setTexture(knight_whiteTexture);
    bool knightWhiteSelected = false;
    bool knightWhite_released = false;

    for(int i = 0; i < 2; i++)
    {
        whiteKnights.push_back(knight_whiteSprite);
    }

    /// SPRITE FOR WHITE ROOK  ///
    vector<sf::Sprite> whiteRooks;
    sf::Texture rook_whiteTexture = TextureManager::getTexture("rook_white");
    sf::Sprite rook_whiteSprite;
    rook_whiteSprite.setTexture(rook_whiteTexture);
    bool rookWhiteSelected = false;
    bool rookWhite_released = false;

    for(int i = 0; i < 2; i++)
    {
        whiteRooks.push_back(rook_whiteSprite);
    }

    /// SPRITE FOR WHITE PAWN ///
    vector<sf::Sprite> whitePawns;
    sf::Texture pawn_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn_whiteSprite;
    pawn_whiteSprite.setTexture(pawn_whiteTexture);
    bool pawnWhiteSelected = false;
    bool pawnWhite_released = false;

    for(int i = 0; i < 8; i++)
    {
        whitePawns.push_back(pawn_whiteSprite);
    }

    /// SPRITE FOR QUEEN ///
    sf::Texture queen_whiteTexture = TextureManager::getTexture("queen_white");
    sf::Sprite queen_whiteSprite;
    queen_whiteSprite.setTexture(queen_whiteTexture);
    bool queenWhiteSelected = false;
    bool queenWhite_released = false;

    /// SPRITE FOR KING ///
    sf::Texture king_whiteTexture = TextureManager::getTexture("king_white");
    sf::Sprite king_whiteSprite;
    king_whiteSprite.setTexture(king_whiteTexture);
    bool kingWhiteSelected = false;
    bool kingWhite_released = false;

    /// WHEN GAME WINDOW IS OPENED ///
    while(gameWindow.isOpen())
    {
        gameWindow.clear(sf::Color(160,160,160));
        sf::Event event2;
        while(gameWindow.pollEvent(event2))
        {
            if(event2.type == sf::Event::Closed)
            {
                gameWindow.close();
            }

            /// --------- MOVEMENT FOR PIECES --------- ///

            /// --------- BLACK PIECES --------- ///

            /// MOVEMENT FOR BLACK PAWNS ///
            for(int i = 0; i < blackPawns.size(); i++)
            {
                pawnPieces.move(event2, gameWindow, blackPawns, pawnBlackSelected, pawnBlack_released);
            }

            /// MOVEMENT FOR BLACK ROOKS ///
            for(int i = 0; i < blackRooks.size(); i++)
            {
                rookPieces.move(event2, gameWindow, blackRooks, rookBlackSelected, rookBlack_released);
            }

            /// MOVEMENT FOR BLACK KNIGHTS ///
            for(int i = 0; i < blackKnights.size(); i++)
            {
                knightPieces.move(event2, gameWindow, blackKnights, knightBlackSelected, knightBlack_released);
            }

            /// MOVEMENT FOR BLACK BISHOPS ///
            for(int i = 0; i < blackBishops.size(); i++)
            {
                bishopPieces.move(event2, gameWindow, blackBishops, bishopBlackSelected, bishopBlack_released);
            }

            /// MOVEMENT FOR KING BLACK ///
            kingPieces.move(event2, gameWindow, king_blackSprite, kingBlackSelected, kingBlack_released);

            /// MOVEMENT FOR QUEEN BLACK ///
            queenPieces.move(event2, gameWindow, queen_blackSprite, queenBlackSelected, queenBlack_released);

            /// --------- WHITE PIECES --------- ///

            /// MOVEMENT FOR WHITE PAWNS ///
            for(int i = 0; i < whitePawns.size(); i++)
            {
                pawnPieces.move(event2, gameWindow, whitePawns, pawnWhiteSelected, pawnWhite_released);
            }

            /// MOVEMENT FOR WHITE ROOKS ///
            for(int i = 0; i < whiteRooks.size(); i++)
            {
                rookPieces.move(event2, gameWindow, whiteRooks, rookWhiteSelected, rookWhite_released);
            }

            /// MOVEMENT FOR WHITE KNIGHTS ///
            for(int i = 0; i < whiteKnights.size(); i++)
            {
                knightPieces.move(event2, gameWindow, whiteKnights, knightWhiteSelected, knightWhite_released);
            }

            /// MOVEMENT FOR WHITE BISHOPS ///
            for(int i = 0; i < whiteBishops.size(); i++)
            {
                bishopPieces.move(event2, gameWindow, whiteBishops, bishopWhiteSelected, bishopWhite_released);
            }

            /// MOVEMENT FOR KING WHITE ///
            kingPieces.move(event2, gameWindow, king_whiteSprite, kingWhiteSelected, kingWhite_released);

            /// MOVEMENT FOR QUEEN WHITE ///
            queenPieces.move(event2, gameWindow, queen_whiteSprite, queenWhiteSelected, queenWhite_released);
        }

        /// DRAW BOARD IN GAME WINDOW ///
        chessBoard.drawBoard(gameWindow,greenRectangle, whiteRectangle);

        /// ----------- DRAW BLACK PIECES ----------- ///

        /// DRAW BLACK PAWNS ///
        for(int p = 0; p < blackPawns.size(); p++)
        {
            pawnPieces.draw(gameWindow,pawnBlackSelected,pawnBlack_released, blackPawns, sf::Mouse::getPosition(gameWindow), 160, 120);
        }

        /// DRAW BLACK ROOKS ///
        for(int p = 0; p < blackRooks.size(); p++)
        {
            rookPieces.draw(gameWindow,rookBlackSelected,rookBlack_released, blackRooks, sf::Mouse::getPosition(gameWindow), 160, 60);
        }

        /// DRAW BLACK KNIGHTS ///
        for(int p = 0; p < blackKnights.size(); p++)
        {
            knightPieces.draw(gameWindow,knightBlackSelected,knightBlack_released, blackKnights, sf::Mouse::getPosition(gameWindow), 220, 60);
        }

        /// DRAW BLACK BISHOPS ///
        for(int p = 0; p < blackBishops.size(); p++)
        {
            bishopPieces.draw(gameWindow,bishopBlackSelected,bishopBlack_released, blackBishops, sf::Mouse::getPosition(gameWindow), 280, 60);
        }

        /// DRAW BLACK KING ///
        kingPieces.draw(gameWindow,kingBlackSelected,kingBlack_released, king_blackSprite, sf::Mouse::getPosition(gameWindow), 400, 60);

        /// DRAW BLACK QUEEN ///
        queenPieces.draw(gameWindow,queenBlackSelected,queenBlack_released,  queen_blackSprite, sf::Mouse::getPosition(gameWindow), 340, 60);

        /// ----------- DRAW WHITE PIECES ----------- ///

        /// DRAW WHITE PAWNS ///
        for(int p = 0; p < whitePawns.size(); p++)
        {
            pawnPieces.draw(gameWindow,pawnWhiteSelected,pawnWhite_released, whitePawns, sf::Mouse::getPosition(gameWindow), 160, 420);
        }

        /// DRAW WHITE ROOKS ///
        for(int p = 0; p < whiteRooks.size(); p++)
        {
            rookPieces.draw(gameWindow,rookWhiteSelected,rookWhite_released, whiteRooks, sf::Mouse::getPosition(gameWindow), 160, 480);
        }

        /// DRAW WHITE KNIGHTS ///
        for(int p = 0; p < whiteKnights.size(); p++)
        {
            knightPieces.draw(gameWindow,knightWhiteSelected,knightWhite_released, whiteKnights, sf::Mouse::getPosition(gameWindow), 220, 480);
        }

        /// DRAW WHITE KNIGHTS ///
        for(int p = 0; p < whiteBishops.size(); p++)
        {
            bishopPieces.draw(gameWindow,bishopWhiteSelected,bishopWhite_released, whiteBishops, sf::Mouse::getPosition(gameWindow), 280, 480);
        }

        /// DRAW WHITE KING ///
        kingPieces.draw(gameWindow,kingWhiteSelected,kingWhite_released, king_whiteSprite, sf::Mouse::getPosition(gameWindow), 400, 480);

        /// DRAW WHITE QUEEN ///
        queenPieces.draw(gameWindow,queenWhiteSelected,queenWhite_released, queen_whiteSprite, sf::Mouse::getPosition(gameWindow), 340, 480);

        /// -------- GAME WINDOW DISPLAY -------- ///
        gameWindow.display();
    }
}
