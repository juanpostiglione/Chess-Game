#include<iostream>
#include <SFML/Graphics.hpp>
#include"WelcomeWindow.h"
#include"GameWindow.h"
using namespace std;

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

void WelcomeWindow::welcomeWindowDisplay(Board& chessBoard)
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
    welcomeWindowTitle2.setString("Enter your name:");
    welcomeWindowTitle2.setFont(font);
    welcomeWindowTitle2.setCharacterSize(20);
    welcomeWindowTitle2.setFillColor(sf::Color::Black);
    welcomeWindowTitle2.setStyle(sf::Text::Bold);
    setText(welcomeWindowTitle2, width/2.0f,height/2.0f - 75);

    /// CREATE USER INPUT ///
    sf::Text userInput;
    userInput.setString("|");
    userInput.setFont(font);
    userInput.setCharacterSize(18);
    userInput.setFillColor(sf::Color::Black);
    userInput.setStyle(sf::Text::Bold);
    setText(userInput, width/2.0f,height/2.0f - 50);

    /// CREATE RECTANGLE SHAPE ///
    sf::RectangleShape rectangle(sf::Vector2f(360,50));
    rectangle.setFillColor(sf::Color(118,150,86));
    rectangle.setPosition(width/2.0f-180,height/2.0f - 170);

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

            /// USER INPUT TEXT ///
            char someChar = static_cast<char>(event.text.unicode);
            if(event.type == sf::Event::TextEntered)
            {
                if(event.text.unicode < 128)
                {
                    if(isalpha(someChar) && playerName.size() < 10)
                    {
                        playerName+= someChar;
                        userInput.setString(playerName + "|");
                        setText(userInput,width/2.0f,height/2.0f - 50);
                    }
                }
            }

            /// ERASE USER INPUT TEXT WHEN PRESSING BACKSPACE ///
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Backspace)
                {
                    if(!playerName.empty())
                    {
                        playerName.pop_back();
                        userInput.setString(playerName + "|");
                        setText(userInput,width/2.0f,height/2.0f - 50);
                    }
                }
            }

            /// IF ENTER IS PRESSED, WELCOME WINDOW IS CLOSED AND GAME WINDOW IS OPENED ///
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Enter)
                {
                    if(!playerName.empty())
                    {
                        welcomeWindow.close();
                        GameWindow window2;
                        window2.GameWindowDisplay(chessBoard);
                    }
                }
            }

            /// DISPLAY WINDOW ///
            welcomeWindow.clear(sf::Color(238,238,216));
            welcomeWindow.draw(rectangle);
            welcomeWindow.draw(welcomeWindowTitle);
            welcomeWindow.draw(welcomeWindowTitle2);
            welcomeWindow.draw(userInput);
            welcomeWindow.display();
        }
    }
}
