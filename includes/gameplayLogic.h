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

void startPosition();

void userInterface();

void userInput(char z);

void gameplay();

void endMenu();

bool bool_game_over();

int finalScore();

#endif