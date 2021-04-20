/*
 * Games Title  : SNAKE
 * Author       : Kwan, Rafael Matthew Susanto (3035742425)
 *                Suntoso, Sean Michael (3035742437)
 * Group        : 77
 * 
 * This header file is part of COMP2113 final project SNAKE.
 * 
 * This program is a header file contain the logic required 
 * during the game.
 * 
 * requiered files  : 
 * ./includes/gameplayLogic.cpp
 * ./includes/gameplayLogic.h 
 * ./includes/leaderboard.cpp
 * ./includes/leaderboard.h
 * Makefile
 */

#ifndef GAMEPLAYLOGIC_H
#define GAMEPLAYLOGIC_H

#include <iostream>

using namespace std;

class position {
public:
  int x;
  int y;
  int fruitx;
  int fruity;
  int score;
};

void menu();

void loading();

void setFruitPosition();

void startPosition();

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