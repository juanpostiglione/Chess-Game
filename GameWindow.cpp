#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include"TextureManager.h"
#include"Board.h"

using namespace std;

/// DEFAULT CONSTRUCTOR ///
GameWindow::GameWindow()
{
   width = 800;
   height = 600;
}

/// FUNCTION TO DISPLAY GAME WINDOW ///
void GameWindow::GameWindowDisplay(Board& chessBoard) const
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

    /// SPRITE FOR BLACK BISHOP 1 ///
    sf::Texture bishop_blackTexture = TextureManager::getTexture("bishop_black");
    sf::Sprite bishop_blackSprite;
    bishop_blackSprite.setTexture(bishop_blackTexture);
    bool bishop1blackSelected = false;
    bool bishop1black_released = false;

    /// SPRITE FOR BLACK BISHOP 2 ///
    sf::Texture bishop2_blackTexture = TextureManager::getTexture("bishop_black");
    sf::Sprite bishop2_blackSprite;
    bishop2_blackSprite.setTexture(bishop2_blackTexture);
    bool bishop2blackSelected = false;
    bool bishop2black_released = false;

    /// SPRITE FOR BLACK KNIGHT ///
    sf::Texture knight_blackTexture = TextureManager::getTexture("knight_black");
    sf::Sprite knight_blackSprite;
    knight_blackSprite.setTexture(knight_blackTexture);
    bool knight1blackSelected = false;
    bool knight1black_released = false;

    /// SPRITE FOR BLACK KNIGHT 2///
    sf::Texture knight2_blackTexture = TextureManager::getTexture("knight_black");
    sf::Sprite knight2_blackSprite;
    knight2_blackSprite.setTexture(knight2_blackTexture);
    bool knight2blackSelected = false;
    bool knight2black_released = false;

    /// SPRITE FOR BLACK ROOK ///
    sf::Texture rook_blackTexture = TextureManager::getTexture("rook_black");
    sf::Sprite rook_blackSprite;
    rook_blackSprite.setTexture(rook_blackTexture);
    bool rook1blackSelected = false;
    bool rook1black_released = false;

    /// SPRITE FOR BLACK ROOK 2 ///
    sf::Texture rook2_blackTexture = TextureManager::getTexture("rook_black");
    sf::Sprite rook2_blackSprite;
    rook2_blackSprite.setTexture(rook2_blackTexture);
    bool rook2blackSelected = false;
    bool rook2black_released = false;

    /// SPRITE FOR BLACK PAWN 1 ///
    sf::Texture pawn1_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn1_blackSprite;
    pawn1_blackSprite.setTexture(pawn1_blackTexture);
    bool pawn1blackSelected = false;
    bool pawn1black_released = false;

    /// SPRITE FOR BLACK PAWN 2 ///
    sf::Texture pawn2_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn2_blackSprite;
    pawn2_blackSprite.setTexture(pawn2_blackTexture);
    bool pawn2blackSelected = false;
    bool pawn2black_released = false;

    /// SPRITE FOR BLACK PAWN 3 ///
    sf::Texture pawn3_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn3_blackSprite;
    pawn3_blackSprite.setTexture(pawn3_blackTexture);
    bool pawn3blackSelected = false;
    bool pawn3black_released = false;

    /// SPRITE FOR BLACK PAWN 4 ///
    sf::Texture pawn4_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn4_blackSprite;
    pawn4_blackSprite.setTexture(pawn4_blackTexture);
    bool pawn4blackSelected = false;
    bool pawn4black_released = false;

    /// SPRITE FOR BLACK PAWN 5 ///
    sf::Texture pawn5_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn5_blackSprite;
    pawn5_blackSprite.setTexture(pawn5_blackTexture);
    bool pawn5blackSelected = false;
    bool pawn5black_released = false;

    /// SPRITE FOR BLACK PAWN 6 ///
    sf::Texture pawn6_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn6_blackSprite;
    pawn6_blackSprite.setTexture(pawn6_blackTexture);
    bool pawn6blackSelected = false;
    bool pawn6black_released = false;

    /// SPRITE FOR BLACK PAWN 7 ///
    sf::Texture pawn7_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn7_blackSprite;
    pawn7_blackSprite.setTexture(pawn7_blackTexture);
    bool pawn7blackSelected = false;
    bool pawn7black_released = false;

    /// SPRITE FOR BLACK PAWN 8 ///
    sf::Texture pawn8_blackTexture = TextureManager::getTexture("pawn_black");
    sf::Sprite pawn8_blackSprite;
    pawn8_blackSprite.setTexture(pawn8_blackTexture);
    bool pawn8blackSelected = false;
    bool pawn8black_released = false;

    ///------- WHITE PIECES SPRITES -------///

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

    /// SPRITE FOR WHITE BISHOP 1 ///
    sf::Texture bishop_whiteTexture = TextureManager::getTexture("bishop_white");
    sf::Sprite bishop_whiteSprite;
    bishop_whiteSprite.setTexture(bishop_whiteTexture);
    bool bishop1whiteSelected = false;
    bool bishop1white_released = false;

    /// SPRITE FOR WHITE BISHOP 2 ///
    sf::Texture bishop2_whiteTexture = TextureManager::getTexture("bishop_white");
    sf::Sprite bishop2_whiteSprite;
    bishop2_whiteSprite.setTexture(bishop2_whiteTexture);
    bool bishop2whiteSelected = false;
    bool bishop2white_released = false;

    /// SPRITE FOR WHITE KNIGHT ///
    sf::Texture knight_whiteTexture = TextureManager::getTexture("knight_white");
    sf::Sprite knight_whiteSprite;
    knight_whiteSprite.setTexture(knight_whiteTexture);
    bool knight1whiteSelected = false;
    bool knight1white_released = false;

    /// SPRITE FOR WHITE KNIGHT 2 ///
    sf::Texture knight2_whiteTexture = TextureManager::getTexture("knight_white");
    sf::Sprite knight2_whiteSprite;
    knight2_whiteSprite.setTexture(knight2_whiteTexture);
    bool knight2whiteSelected = false;
    bool knight2white_released = false;

    /// SPRITE FOR WHITE ROOK 1 ///
    sf::Texture rook_whiteTexture = TextureManager::getTexture("rook_white");
    sf::Sprite rook_whiteSprite;
    rook_whiteSprite.setTexture(rook_whiteTexture);
    bool rook1whiteSelected = false;
    bool rook1white_released = false;

    /// SPRITE FOR WHITE ROOK 2 ///
    sf::Texture rook2_whiteTexture = TextureManager::getTexture("rook_white");
    sf::Sprite rook2_whiteSprite;
    rook2_whiteSprite.setTexture(rook2_whiteTexture);
    bool rook2whiteSelected = false;
    bool rook2white_released = false;

    /// SPRITE FOR WHITE PAWN 1 ///
    sf::Texture pawn1_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn1_whiteSprite;
    pawn1_whiteSprite.setTexture(pawn1_whiteTexture);
    bool pawn1whiteSelected = false;
    bool pawn1white_released = false;

    /// SPRITE FOR WHITE PAWN 2 ///
    sf::Texture pawn2_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn2_whiteSprite;
    pawn2_whiteSprite.setTexture(pawn2_whiteTexture);
    bool pawn2whiteSelected = false;
    bool pawn2white_released = false;

    /// SPRITE FOR WHITE PAWN 3 ///
    sf::Texture pawn3_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn3_whiteSprite;
    pawn3_whiteSprite.setTexture(pawn3_whiteTexture);
    bool pawn3whiteSelected = false;
    bool pawn3white_released = false;

    /// SPRITE FOR WHITE PAWN 4 ///
    sf::Texture pawn4_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn4_whiteSprite;
    pawn4_whiteSprite.setTexture(pawn4_whiteTexture);
    bool pawn4whiteSelected = false;
    bool pawn4white_released = false;

    /// SPRITE FOR WHITE PAWN 5 ///
    sf::Texture pawn5_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn5_whiteSprite;
    pawn5_whiteSprite.setTexture(pawn5_whiteTexture);
    bool pawn5whiteSelected = false;
    bool pawn5white_released = false;

    /// SPRITE FOR WHITE PAWN 6 ///
    sf::Texture pawn6_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn6_whiteSprite;
    pawn6_whiteSprite.setTexture(pawn6_whiteTexture);
    bool pawn6whiteSelected = false;
    bool pawn6white_released = false;

    /// SPRITE FOR WHITE PAWN 7 ///
    sf::Texture pawn7_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn7_whiteSprite;
    pawn7_whiteSprite.setTexture(pawn7_whiteTexture);
    bool pawn7whiteSelected = false;
    bool pawn7white_released = false;

    /// SPRITE FOR WHITE PAWN 8 ///
    sf::Texture pawn8_whiteTexture = TextureManager::getTexture("pawn_white");
    sf::Sprite pawn8_whiteSprite;
    pawn8_whiteSprite.setTexture(pawn8_whiteTexture);
    bool pawn8whiteSelected = false;
    bool pawn8white_released = false;

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

            /// MOVEMENT FOR PAWN BLACK 1 ///
            chessBoard.movementPiece(event2, gameWindow,  pawn1_blackSprite, pawn1blackSelected, pawn1black_released);

            /// MOVEMENT FOR PAWN BLACK 2 ///
            chessBoard.movementPiece(event2, gameWindow, pawn2_blackSprite, pawn2blackSelected, pawn2black_released);

            /// MOVEMENT FOR PAWN BLACK 3 ///
            chessBoard.movementPiece(event2, gameWindow, pawn3_blackSprite, pawn3blackSelected, pawn3black_released);

            /// MOVEMENT FOR PAWN BLACK 4 ///
            chessBoard.movementPiece(event2, gameWindow, pawn4_blackSprite, pawn4blackSelected, pawn4black_released);

            /// MOVEMENT FOR PAWN BLACK 5 ///
            chessBoard.movementPiece(event2, gameWindow, pawn5_blackSprite, pawn5blackSelected, pawn5black_released);

            /// MOVEMENT FOR PAWN BLACK 6 ///
            chessBoard.movementPiece(event2, gameWindow,pawn6_blackSprite, pawn6blackSelected, pawn6black_released);

            /// MOVEMENT FOR PAWN BLACK 7 ///
            chessBoard.movementPiece(event2, gameWindow, pawn7_blackSprite, pawn7blackSelected, pawn7black_released);

            /// MOVEMENT FOR PAWN BLACK 8 ///
            chessBoard.movementPiece(event2, gameWindow, pawn8_blackSprite, pawn8blackSelected, pawn8black_released);

            /// MOVEMENT FOR ROOK BLACK 1 ///
            chessBoard.movementPiece(event2, gameWindow, rook_blackSprite, rook1blackSelected, rook1black_released);

            /// MOVEMENT FOR ROOK BLACK 2 ///
            chessBoard.movementPiece(event2, gameWindow, rook2_blackSprite, rook2blackSelected, rook2black_released);

            /// MOVEMENT FOR KNIGHT BLACK 1 ///
            chessBoard.movementPiece(event2, gameWindow, knight_blackSprite, knight1blackSelected, knight1black_released);

            /// MOVEMENT FOR KNIGHT BLACK 2 ///
            chessBoard.movementPiece(event2, gameWindow, knight2_blackSprite, knight2blackSelected, knight2black_released);

            /// MOVEMENT FOR BISHOP BLACK 1 ///
            chessBoard.movementPiece(event2, gameWindow, bishop_blackSprite, bishop1blackSelected, bishop1black_released);

            /// MOVEMENT FOR BISHOP BLACK 2 ///
            chessBoard.movementPiece(event2, gameWindow, bishop2_blackSprite, bishop2blackSelected, bishop2black_released);

            /// MOVEMENT FOR KING BLACK ///
            chessBoard.movementPiece(event2, gameWindow, king_blackSprite, kingBlackSelected, kingBlack_released);

            /// MOVEMENT FOR QUEEN BLACK ///
            chessBoard.movementPiece(event2, gameWindow, queen_blackSprite, queenBlackSelected, queenBlack_released);

            /// MOVEMENT FOR PAWN WHITE 1 ///
            chessBoard.movementPiece(event2, gameWindow, pawn1_whiteSprite, pawn1whiteSelected, pawn1white_released);

            /// MOVEMENT FOR PAWN WHITE 2 ///
            chessBoard.movementPiece(event2, gameWindow, pawn2_whiteSprite, pawn2whiteSelected, pawn2white_released);

            /// MOVEMENT FOR PAWN WHITE 3 ///
            chessBoard.movementPiece(event2, gameWindow, pawn3_whiteSprite, pawn3whiteSelected, pawn3white_released);

            /// MOVEMENT FOR PAWN WHITE 4 ///
            chessBoard.movementPiece(event2, gameWindow, pawn4_whiteSprite, pawn4whiteSelected, pawn4white_released);

            /// MOVEMENT FOR PAWN WHITE 5 ///
            chessBoard.movementPiece(event2, gameWindow, pawn5_whiteSprite, pawn5whiteSelected, pawn5white_released);

            /// MOVEMENT FOR PAWN WHITE 6 ///
            chessBoard.movementPiece(event2, gameWindow, pawn6_whiteSprite, pawn6whiteSelected, pawn6white_released);

            /// MOVEMENT FOR PAWN WHITE 7 ///
            chessBoard.movementPiece(event2, gameWindow, pawn7_whiteSprite, pawn7whiteSelected, pawn7white_released);

            /// MOVEMENT FOR PAWN WHITE 8 ///
            chessBoard.movementPiece(event2, gameWindow, pawn8_whiteSprite, pawn8whiteSelected, pawn8white_released);

            /// MOVEMENT FOR ROOK WHITE 1 ///
            chessBoard.movementPiece(event2, gameWindow, rook_whiteSprite, rook1whiteSelected, rook1white_released);

            /// MOVEMENT FOR ROOK WHITE 1 ///
            chessBoard.movementPiece(event2, gameWindow, rook2_whiteSprite, rook2whiteSelected, rook2white_released);

            /// MOVEMENT FOR KNIGHT WHITE 1 ///
            chessBoard.movementPiece(event2, gameWindow, knight_whiteSprite, knight1whiteSelected, knight1white_released);

            /// MOVEMENT FOR KNIGHT WHITE 2 ///
            chessBoard.movementPiece(event2, gameWindow, knight2_whiteSprite, knight2whiteSelected, knight2white_released);

            /// MOVEMENT FOR BISHOP WHITE 1 ///
            chessBoard.movementPiece(event2, gameWindow, bishop_whiteSprite, bishop1whiteSelected, bishop1white_released);

            /// MOVEMENT FOR BISHOP WHITE 2 ///
            chessBoard.movementPiece(event2, gameWindow, bishop2_whiteSprite, bishop2whiteSelected, bishop2white_released);

            /// MOVEMENT FOR KING WHITE ///
            chessBoard.movementPiece(event2, gameWindow, king_whiteSprite, kingWhiteSelected, kingWhite_released);

            /// MOVEMENT FOR QUEEN WHITE ///
            chessBoard.movementPiece(event2, gameWindow, queen_whiteSprite, queenWhiteSelected, queenWhite_released);
        }

        /// DRAW BOARD IN GAME WINDOW ///
        chessBoard.drawBoard(gameWindow,greenRectangle, whiteRectangle);


        /// ----------- DRAW BLACK PIECES ----------- ///

        /// DRAW BLACK PAWN 1 ///
        chessBoard.drawPieces(gameWindow,pawn1blackSelected,pawn1black_released, pawn1_blackSprite, sf::Mouse::getPosition(gameWindow), 160, 120);

        /// DRAW BLACK PAWN 2 ///
        chessBoard.drawPieces(gameWindow,pawn2blackSelected,pawn2black_released, pawn2_blackSprite, sf::Mouse::getPosition(gameWindow), 220, 120);

        /// DRAW BLACK PAWN 3 ///
        chessBoard.drawPieces(gameWindow,pawn3blackSelected,pawn3black_released, pawn3_blackSprite, sf::Mouse::getPosition(gameWindow), 280, 120);

        /// DRAW BLACK PAWN 4 ///
        chessBoard.drawPieces(gameWindow,pawn4blackSelected,pawn4black_released, pawn4_blackSprite, sf::Mouse::getPosition(gameWindow), 340, 120);

        /// DRAW BLACK PAWN 5 ///
        chessBoard.drawPieces(gameWindow,pawn5blackSelected,pawn5black_released, pawn5_blackSprite, sf::Mouse::getPosition(gameWindow), 400, 120);

        /// DRAW BLACK PAWN 6 ///
        chessBoard.drawPieces(gameWindow,pawn6blackSelected,pawn6black_released, pawn6_blackSprite, sf::Mouse::getPosition(gameWindow), 460, 120);

        /// DRAW BLACK PAWN 7 ///
        chessBoard.drawPieces(gameWindow,pawn7blackSelected,pawn7black_released,  pawn7_blackSprite, sf::Mouse::getPosition(gameWindow), 520, 120);

        /// DRAW BLACK PAWN 8 ///
        chessBoard.drawPieces(gameWindow,pawn8blackSelected,pawn8black_released,  pawn8_blackSprite, sf::Mouse::getPosition(gameWindow), 580, 120);

        /// DRAW BLACK ROOK 1 ///
        chessBoard.drawPieces(gameWindow,rook1blackSelected,rook1black_released, rook_blackSprite, sf::Mouse::getPosition(gameWindow), 160, 60);

        /// DRAW BLACK ROOK 2 ///
        chessBoard.drawPieces(gameWindow,rook2blackSelected,rook2black_released, rook2_blackSprite, sf::Mouse::getPosition(gameWindow), 580, 60);

        /// DRAW BLACK KNIGHT 1 ///
        chessBoard.drawPieces(gameWindow,knight1blackSelected,knight1black_released, knight_blackSprite, sf::Mouse::getPosition(gameWindow), 220, 60);

        /// DRAW BLACK KNIGHT 2 ///
        chessBoard.drawPieces(gameWindow,knight2blackSelected,knight2black_released, knight2_blackSprite, sf::Mouse::getPosition(gameWindow), 520, 60);

        /// DRAW BLACK BISHOP 1 ///
        chessBoard.drawPieces(gameWindow,bishop1blackSelected,bishop1black_released,  bishop_blackSprite, sf::Mouse::getPosition(gameWindow), 280, 60);

        /// DRAW BLACK BISHOP 2 ///
        chessBoard.drawPieces(gameWindow,bishop2blackSelected,bishop2black_released, bishop2_blackSprite, sf::Mouse::getPosition(gameWindow), 460, 60);

        /// DRAW BLACK KING ///
        chessBoard.drawPieces(gameWindow,kingBlackSelected,kingBlack_released, king_blackSprite, sf::Mouse::getPosition(gameWindow), 400, 60);

        /// DRAW BLACK QUEEN ///
        chessBoard.drawPieces(gameWindow,queenBlackSelected,queenBlack_released,  queen_blackSprite, sf::Mouse::getPosition(gameWindow), 340, 60);

        /// ----------- DRAW WHITE PIECES ----------- ///

        /// DRAW WHITE PAWN 1 ///
        chessBoard.drawPieces(gameWindow,pawn1whiteSelected,pawn1white_released,  pawn1_whiteSprite, sf::Mouse::getPosition(gameWindow), 160, 420);

        /// DRAW WHITE PAWN 2 ///
        chessBoard.drawPieces(gameWindow,pawn2whiteSelected,pawn2white_released,  pawn2_whiteSprite, sf::Mouse::getPosition(gameWindow), 220, 420);

        /// DRAW WHITE PAWN 3 ///
        chessBoard.drawPieces(gameWindow,pawn3whiteSelected,pawn3white_released, pawn3_whiteSprite, sf::Mouse::getPosition(gameWindow), 280, 420);

        /// DRAW WHITE PAWN 4 ///
        chessBoard.drawPieces(gameWindow,pawn4whiteSelected,pawn4white_released, pawn4_whiteSprite, sf::Mouse::getPosition(gameWindow), 340, 420);

        /// DRAW WHITE PAWN 5 ///
        chessBoard.drawPieces(gameWindow,pawn5whiteSelected,pawn5white_released, pawn5_whiteSprite, sf::Mouse::getPosition(gameWindow), 400, 420);

        /// DRAW WHITE PAWN 6 ///
        chessBoard.drawPieces(gameWindow,pawn6whiteSelected,pawn6white_released, pawn6_whiteSprite, sf::Mouse::getPosition(gameWindow), 460, 420);

        /// DRAW WHITE PAWN 7 ///
        chessBoard.drawPieces(gameWindow,pawn7whiteSelected,pawn7white_released, pawn7_whiteSprite, sf::Mouse::getPosition(gameWindow), 520, 420);

        /// DRAW WHITE PAWN 8 ///
        chessBoard.drawPieces(gameWindow,pawn8whiteSelected,pawn8white_released, pawn8_whiteSprite, sf::Mouse::getPosition(gameWindow), 580, 420);

        /// DRAW WHITE ROOK 1 ///
        chessBoard.drawPieces(gameWindow,rook1whiteSelected,rook1white_released, rook_whiteSprite, sf::Mouse::getPosition(gameWindow), 160, 480);

        /// DRAW WHITE ROOK 2 ///
        chessBoard.drawPieces(gameWindow,rook2whiteSelected,rook2white_released, rook2_whiteSprite, sf::Mouse::getPosition(gameWindow), 580, 480);

        /// DRAW WHITE KNIGHT 1 ///
        chessBoard.drawPieces(gameWindow,knight1whiteSelected,knight1white_released, knight_whiteSprite, sf::Mouse::getPosition(gameWindow), 220, 480);

        /// DRAW WHITE KNIGHT 2 ///
        chessBoard.drawPieces(gameWindow,knight2whiteSelected,knight2white_released, knight2_whiteSprite, sf::Mouse::getPosition(gameWindow), 520, 480);

        /// DRAW WHITE BISHOP 1 ///
        chessBoard.drawPieces(gameWindow,bishop1whiteSelected,bishop1white_released, bishop_whiteSprite, sf::Mouse::getPosition(gameWindow), 280, 480);

        /// DRAW WHITE BISHOP 2 ///
        chessBoard.drawPieces(gameWindow,bishop2whiteSelected,bishop2white_released, bishop2_whiteSprite, sf::Mouse::getPosition(gameWindow), 460, 480);

        /// DRAW WHITE KING ///
        chessBoard.drawPieces(gameWindow,kingWhiteSelected,kingWhite_released, king_whiteSprite, sf::Mouse::getPosition(gameWindow), 400, 480);

        /// DRAW WHITE QUEEN ///
        chessBoard.drawPieces(gameWindow,queenWhiteSelected,queenWhite_released, queen_whiteSprite, sf::Mouse::getPosition(gameWindow), 340, 480);

        /// -------- GAME WINDOW DISPLAY -------- ///
        gameWindow.display();
    }
}

