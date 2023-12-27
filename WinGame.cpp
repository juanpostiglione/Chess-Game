#include "WinGame.h"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

/// DEFAULT CONSTRUCTOR ///
WinGame::WinGame()
{
   width = 400;
   height = 300;
}

/// FUNCTION TO CENTER TEXT ///
void WinGame::setText(sf::Text &text, float x, float y)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

/// FUNCTION TO CAPTURE PIECES VECTORS EXCEPT KING AND QUEEN ///
void WinGame::capturePiece(sf::Event& event, sf::RenderWindow& gameWindow,
                           vector<sf::Sprite>& piece, vector<vector<sf::Sprite>>& chosenPiece, sf::Mouse::Button mouseButton, int positionX, int positionY)
{
    /// IF A PIECE IS PRESSED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// IF RIGHT CLICK IS USED ///
        if(event.mouseButton.button == mouseButton)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            /// FOR EACH PIECE IN THE VECTOR OF PIECES ///
            for (int i = 0; i < chosenPiece.size(); ++i)
            {
                for (int j = 0; j < chosenPiece[i].size(); j++)
                {
                    /// IF A PIECE IS CLICKED AND USED TO CAPTURE ANOTHER ONE ///
                    if (chosenPiece[i][j].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                    {
                        /// FOR EACH PIECE IN THE VECTOR OF PIECES OF THE OPPOSITE COLOR ///
                        for(int p = 0; p < piece.size(); p++)
                        {
                            /// IF PIECE IS CLICKED OR CAPTURED ///
                            if(piece[p].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                            {
                                /// PIECE GET OUT OF THE BOARD ///
                                piece[p].setPosition((p * 20) + positionX  , positionY);

                                /// MAKE THE PIECE SMALLER ///
                                piece[p].setScale(0.5,0.5);
                            }
                        }
                    }
                }
            }
        }
    }
}

void WinGame::capturePiece2(sf::Event& event, sf::RenderWindow& gameWindow,
                     sf::Sprite& sprite, vector<sf::Sprite>& chosenPiece, sf::Mouse::Button mouseButton1, sf::Mouse::Button mouseButton2,
                            int positionX1, int positionY1, int positionX2, int positionY2)
{
    /// IF A PIECE IS PRESSED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// IF LEFT OR RIGHT CLICK IS USED ///
        if(event.mouseButton.button == mouseButton1)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            /// FOR EACH PIECE IN THE VECTOR OF PIECES ///
            for (int i = 0; i < chosenPiece.size(); ++i)
            {
                /// IF A PIECE IS CLICKED AND USED TO CAPTURE ANOTHER ONE ///
                if (chosenPiece[i].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                {
                    /// FOR EACH PIECE OF THE OPPOSITE COLOR ///
                    for(int j = 0; j < 1; j++)
                    {
                        /// IF PIECE IS CLICKED OR CAPTURED ///
                        if(sprite.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                        {
                            /// PIECE GET OUT OF THE BOARD ///
                            sprite.setPosition((j * 20) + positionX1  , positionY1);

                            /// MAKE THE PIECE SMALLER ///
                            sprite.setScale(0.5,0.5);
                        }
                    }
                }
            }
        }
    }

    /// IF A PIECE IS PRESSED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// IF LEFT OR RIGHT CLICK IS USED ///
        if(event.mouseButton.button == mouseButton2)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            /// FOR EACH PIECE  ///
            for (int i = 0; i < 1; ++i)
            {
                /// IF A PIECE IS CLICKED AND USED TO CAPTURE ANOTHER ONE ///
                if (sprite.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                {
                    /// FOR EACH PIECE IN THE VECTOR OF THE OPPOSITE COLOR ///
                    for(int j = 0; j < chosenPiece.size(); j++)
                    {
                        /// IF PIECE IS CLICKED OR CAPTURED ///
                        if(chosenPiece[j].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                        {
                            /// PIECE GET OUT OF THE BOARD ///
                            chosenPiece[j].setPosition((j * 20) + positionX2  , positionY2);

                            /// MAKE THE PIECE SMALLER ///
                            chosenPiece[j].setScale(0.5,0.5);
                        }
                    }
                }
            }
        }
    }
}

void WinGame::capturePiece3(sf::Event& event, sf::RenderWindow& gameWindow,
                     sf::Sprite& sprite, sf::Sprite& chosenPiece)
{
    /// IF A PIECE IS PRESSED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// IF LEFT CLICK IS USED ///
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            /// FOR EACH PIECE ///
            for (int i = 0; i < 1; ++i)
            {
                /// IF A PIECE IS CLICKED AND USED TO CAPTURE ANOTHER ONE ///
                if (chosenPiece.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                {
                    /// FOR EACH PIECE OF THE OPPOSITE COLOR ///
                    for(int j = 0; j < 1; j++)
                    {
                        /// IF PIECE IS CLICKED OR CAPTURED ///
                        if(sprite.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                        {
                            /// PIECE GET OUT OF THE BOARD ///
                            sprite.setPosition((j * 20) + 480  , 550);

                            /// MAKE THE PIECE SMALLER ///
                            sprite.setScale(0.5,0.5);
                        }
                    }
                }
            }
        }
    }

    /// IF A PIECE IS PRESSED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// IF RIGHT CLICK IS USED ///
        if(event.mouseButton.button == sf::Mouse::Right)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            /// FOR EACH PIECE ///
            for (int i = 0; i < 1; ++i)
            {
                /// IF A PIECE IS CLICKED AND USED TO CAPTURE ANOTHER ONE ///
                if (sprite.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                {
                    /// FOR EACH PIECE OF THE OPPOSITE COLOR ///
                    for(int j = 0; j < 1; j++)
                    {
                        /// IF PIECE IS CLICKED OR CAPTURED ///
                        if(chosenPiece.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                        {
                            /// PIECE GET OUT OF THE BOARD ///
                            chosenPiece.setPosition((j * 20) + 480  , 0);

                            /// MAKE THE PIECE SMALLER ///
                            chosenPiece.setScale(0.5,0.5);
                        }
                    }
                }
            }
        }
    }
}

void WinGame::isKingOutOfBoard(sf::Event &event, sf::RenderWindow &gameWindow, sf::Sprite& kingSprite,
                             vector<vector<sf::Sprite>>& pieces, sf::Mouse::Button mouseButton)
{
    /// IF CLICK IS PRESSED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// IF RIGHT OR LEFT CLICK IS USED ///
        if(event.mouseButton.button == mouseButton)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            /// FOR EACH PIECE IN THE VECTOR ///
            for (int i = 0; i < pieces.size(); ++i)
            {
                for(int j = 0; j < pieces[i].size();j++)
                {
                    /// IF A PIECE IS CLICKED AND USED TO CAPTURE ANOTHER ONE ///
                    if (pieces[i][j].getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                    {
                        /// FOR EACH PIECE ///
                        for(int p = 0; p < 1; p++)
                        {
                            /// IF PIECE IS CLICKED OR CAPTURED ///
                            if(kingSprite.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                            {
                                /// PLAYER WINS AND WIN WINDOW DISPLAY ///
                                winWindow(mouseButton);
                            }
                        }
                    }
                }
            }
        }
    }
}

void WinGame::isKingOutOfBoard2(sf::Event &event, sf::RenderWindow &gameWindow, sf::Sprite &sprite,
                                sf::Sprite& chosenPiece, sf::Mouse::Button mouseButton)
{
    /// IF CLICK IS PRESSED ///
    if (event.type == sf::Event::MouseButtonPressed)
    {
        /// IF RIGHT OR LEFT CLICK IS USED ///
        if(event.mouseButton.button == mouseButton)
        {
            /// VECTOR FOR MOUSE ///
            sf::Vector2i mouse = sf::Mouse::getPosition(gameWindow);

            /// FOR EACH PIECE ///
            for (int i = 0; i < 1; ++i)
            {
                /// IF A PIECE IS CLICKED AND USED TO CAPTURE ANOTHER ONE ///
                if (chosenPiece.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                {
                    /// FOR EACH PIECE ///
                    for(int j = 0; j < 1; j++)
                    {
                        /// IF PIECE IS CLICKED OR CAPTURED ///
                        if(sprite.getGlobalBounds().contains(gameWindow.mapPixelToCoords(mouse)))
                        {
                            /// PLAYER WINS AND WIN WINDOW DISPLAY ///
                            winWindow(mouseButton);
                        }
                    }
                }
            }
        }
    }
}

/// FUNCTION TO DISPLAY WIN WINDOW ///
void WinGame::winWindow(sf::Mouse::Button mouseButton)
{
    /// CREATE WIN WINDOW ///
    sf::RenderWindow winWindow(sf::VideoMode(width, height), "Win");
    sf::Font font;

    /// LOAD FONT ///
    if (!font.loadFromFile("font.ttf"))
    {
        std::cout << "Error" << std::endl;
    }

    while(winWindow.isOpen())
    {
        sf::Event event3;
        while(winWindow.pollEvent(event3))
        {
            if(event3.type == sf::Event::Closed)
            {
                winWindow.close();
            }

            /// IF BLACK PIECES WIN ///
            if(mouseButton == sf::Mouse::Right)
            {
                /// WIN MESSAGE FOR BLACK PIECES ///
                sf::Text winMessage;
                winMessage.setString("You Win!");
                winMessage.setFont(font);
                winMessage.setCharacterSize(30);
                winMessage.setFillColor(sf::Color::White);
                winMessage.setStyle(sf::Text::Bold);
                setText(winMessage, width/2.0f,height/2.0f);

                winWindow.clear(sf::Color::Black);
                winWindow.draw(winMessage);
                winWindow.display();
            }

            /// IF WHITE PIECES WIN ///
            else if(mouseButton == sf::Mouse::Left)
            {
                /// WIN MESSAGE FOR WHITE PIECES ///
                sf::Text winMessage;
                winMessage.setString("You Win!");
                winMessage.setFont(font);
                winMessage.setCharacterSize(30);
                winMessage.setFillColor(sf::Color::Black);
                winMessage.setStyle(sf::Text::Bold);
                setText(winMessage, width/2.0f,height/2.0f);

                winWindow.clear(sf::Color::White);
                winWindow.draw(winMessage);
                winWindow.display();
            }
        }
    }
}

