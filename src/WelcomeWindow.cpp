#include<iostream>
#include <SFML/Graphics.hpp>
#include"WelcomeWindow.h"
#include"GameWindow.h"
using namespace std;

/// DEFAULT CONSTRUCTOR ///
WelcomeWindow::WelcomeWindow()
{
    width = 800;
    height = 600;
}

/// FUNCTION TO CENTER TEXT ///
void WelcomeWindow::setText(sf::Text &text, float x, float y)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

/// FUNCTION TO DISPLAY WELCOME WINDOW ///
void WelcomeWindow::welcomeWindowDisplay(Board& chessBoard, Pawn& pawnPieces, Rook& rookPieces, Knight& knightPieces,
                                         Bishop& bishopPieces, King& kingPieces, Queen& queenPieces, WinGame& winGame) const
{
    /// CREATE WELCOME WINDOW ///
    sf::RenderWindow welcomeWindow(sf::VideoMode(width, height), "Chess");
    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        std::cout << "Error" << std::endl;
    }

    /// CREATE TITLE ///
    sf::Text welcomeWindowTitle;
    welcomeWindowTitle.setString("Welcome to Chess");
    welcomeWindowTitle.setFont(font);
    welcomeWindowTitle.setCharacterSize(35);
    welcomeWindowTitle.setFillColor(sf::Color::White);
    welcomeWindowTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
    setText(welcomeWindowTitle, width/2.0f,height/2.0f - 150);

    /// CREATE SUBTITLE ///
    sf::Text welcomeWindowTitle2;
    welcomeWindowTitle2.setString("Press enter to play!");
    welcomeWindowTitle2.setFont(font);
    welcomeWindowTitle2.setCharacterSize(20);
    welcomeWindowTitle2.setFillColor(sf::Color::Black);
    welcomeWindowTitle2.setStyle(sf::Text::Bold);
    setText(welcomeWindowTitle2, width/2.0f,height/2.0f);

    /// CREATE RECTANGLE SHAPE FOR TITLE ///
    sf::RectangleShape rectangle(sf::Vector2f(360,50));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(width/2.0f-180,height/2.0f - 170);

    /// CREATE RECTANGLE SHAPE 1 ///
    sf::RectangleShape rectangle2(sf::Vector2f(50,600));
    rectangle2.setFillColor(sf::Color(118,150,86));
    rectangle2.setPosition(width/2.0f-400,height/2.0f-300);

    /// CREATE RECTANGLE SHAPE 2 ///
    sf::RectangleShape rectangle3(sf::Vector2f(50,600));
    rectangle3.setFillColor(sf::Color(118,150,86));
    rectangle3.setPosition(width/2.0f+350,height/2.0f-300);

    /// CREATE RECTANGLE SHAPE 3 ///
    sf::RectangleShape rectangle4(sf::Vector2f(800,50));
    rectangle4.setFillColor(sf::Color(118,150,86));
    rectangle4.setPosition(width/2.0f-400,height/2.0f-300);

    /// CREATE RECTANGLE SHAPE 4 ///
    sf::RectangleShape rectangle5(sf::Vector2f(800,50));
    rectangle5.setFillColor(sf::Color(118,150,86));
    rectangle5.setPosition(width/2.0f-400,height/2.0f+250);

    /// WHEN WELCOME WINDOW IS OPENED ///
    while(welcomeWindow.isOpen())
    {
        sf::Event event;
        while(welcomeWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                welcomeWindow.close();
            }

            /// IF ENTER IS PRESSED, WELCOME WINDOW IS CLOSED AND GAME WINDOW IS OPENED ///
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Enter)
                {
                    welcomeWindow.close();
                    GameWindow window2;
                    window2.GameWindowDisplay(chessBoard, pawnPieces, rookPieces, knightPieces,
                                              bishopPieces, kingPieces,queenPieces, winGame);
                }
            }

            /// DISPLAY WINDOW ///
            welcomeWindow.clear(sf::Color(238,238,216));
            welcomeWindow.draw(rectangle);
            welcomeWindow.draw(rectangle2);
            welcomeWindow.draw(rectangle3);
            welcomeWindow.draw(rectangle4);
            welcomeWindow.draw(rectangle5);
            welcomeWindow.draw(welcomeWindowTitle);
            welcomeWindow.draw(welcomeWindowTitle2);
            welcomeWindow.display();
        }
    }
}