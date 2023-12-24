# CHESS GAME PROJECT

# DESCRIPTION:
This project consists in recreate a classic chess game using SFML and C++. Chess is one of the oldest and most popular board games. It is played by two opponents on a checkered board using specially created pieces of contrasting colors, most often white and black. The goal of the game is to capture the opponent's king.

# INSTRUCTIONS (IMPORTANT):
- When capture a piece, each color has a different behavior: (Doing the wrong behavior could lead to capture the wrong piece)

Player with Black Pieces: Capture a piece using RIGHT click.
Player with White Pieces: Capture a piece using LEFT click.

- To move the pieces, each piece needs to be clicked and dragged to a position, and then release it to place it.

# PNG FILES USED FOR THE GAME:
## PIECES FOR DOWNLOAD:
![pawn_black](https://github.com/juanpostiglione/Chess-Game/assets/128395993/163b578b-e4a2-4f13-97c0-89b3e9b83afd)
![pawn_white](https://github.com/juanpostiglione/Chess-Game/assets/128395993/55cf58c7-50b0-4c0e-97cd-7a7912dd0b7e)
![rook_black](https://github.com/juanpostiglione/Chess-Game/assets/128395993/dbebe6a1-1d2a-4125-8de2-341a5fae598f)
![rook_white](https://github.com/juanpostiglione/Chess-Game/assets/128395993/5dc0aaa8-7376-4e03-915b-9523ae686420)
![knight_black](https://github.com/juanpostiglione/Chess-Game/assets/128395993/62a169bd-5846-4419-8660-1c7d1bc0e611)
![knight_white](https://github.com/juanpostiglione/Chess-Game/assets/128395993/94257edd-f187-437f-9a94-4fd819fa46b7)
![bishop_black](https://github.com/juanpostiglione/Chess-Game/assets/128395993/a8821932-cdab-4310-b62b-7fd786c067e5)
![bishop_white](https://github.com/juanpostiglione/Chess-Game/assets/128395993/f7438bba-6ec0-49e8-84dc-eecf10367f58)
![king_black](https://github.com/juanpostiglione/Chess-Game/assets/128395993/d3a6aba2-e4b9-4595-8763-7e754dd2691f)
![king_white](https://github.com/juanpostiglione/Chess-Game/assets/128395993/5e2c5b61-c600-4715-a249-6bea8e29bda6)
![queen_black](https://github.com/juanpostiglione/Chess-Game/assets/128395993/21480464-aedb-46c6-91b8-cbaf97912025)
![queen_white](https://github.com/juanpostiglione/Chess-Game/assets/128395993/812dafc6-3dd8-4711-aa22-ccee3d855c48)

# PROJECT STRUCTURE:
The project is divided in different classes with useful functions for each objective in the project. Comments are everywhere in the code structure to explain the use for each function. There is important information below for part of the project structure.

## Welcome Window
This class is used to create the first window for the game, where the user can enter his/her name and start playing.

## Game Window
This class is used to create the second window for the game where the player is going to play. Inside this class, there are functions from the Board class, Piece class and WinGame class, used to implement the logic of the game.

## Board Class
This class is used to create the board of the game.

## Piece Class
This class is used to create a base class for Piece, with sub-classes for each piece of the game where each class have a function to be drawn, and a function to be moved. Inheritance is applied.

## WinGame Class
This class is used to create functions for the capture behavior of the pieces. Also, it contains a function to display the Win Window when a player wins.

## Texture Manager
This class is used to load the textures for the png files.

## CMAKELISTS.TXT
One of the files contains the CMakeLists.txt used of this SFML project, for MAC M1 and M2.















