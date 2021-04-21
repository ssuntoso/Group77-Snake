/*
Game Title: SNAKE-77
Group     : 77
Author    : Kwan, Rafael Matthew Susanto (3035742425)
            Suntoso, Sean Michael (3035742437)
  
This header file is a part of the COMP2113 course project SNAKE-77.

required separated files for this header file:
- Makefile
 
This header file declare the functions for the logic of the game
that will be passed to the correlated cpp file, gameplayLogic.cpp
*/

#ifndef GAMEPLAYLOGIC_H
#define GAMEPLAYLOGIC_H

#include <iostream>

using namespace std;

// initialize user-defined datatype to be used throughout the game
class position {
public:
  int x;
  int y;
  int fruitx;
  int fruity;
  int score;
};

// menu interface
void menu();

// loading screen interface
void loading();

// randomized fruit positions
void setFruitPosition();

// the starting point for some of the declared variables
void startPosition();

// print the arena, snake, and fruit
void userInterface();

// move snake or end the game
void userInput(char z);

// contain logic in moving and growing snake, count 
// score, and end game if snake eat its own body. 
void gameplay();

// obtain gameOver current stage
bool bool_game_over();

// obtain the current or final score
int finalScore();

#endif