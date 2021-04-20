// This program is the logic of the game

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include "gameplayLogic.h"

using namespace std;

const int height = 22;
const int width = 22;
const char barrier = '#';
const char fruit = '$';
bool gameOver;

int tail_x[400], tail_y[400];

int totalTail = 1;

position current;

int stopPlaying = false;

char askUser;

// function to call menu
void menu()
{
  for (int i = 0; i < width + 1; i++) {
      cout << barrier;
  }
  cout << endl;
  for (int i = 0; i < height; i++) {
    if ((i < 6 || i > 11 || i == 9) && i < 18) {
      for (int j = 0; j < width + 1; j++) {
        if (j == 0) {
          cout << barrier;
        }
        else if (j == width) {
          cout << barrier << endl;
        }
        else {
          cout << ' ';
        }
      }
    }
    else if (i == 6) {
      cout << "#      ~~~~~~~~       #" << endl;
    }
    else if (i == 7) {
      cout << "#      SNAKE-77       #" << endl;
    }
    else if (i == 8) {
      cout << "#      ~~~~~~~~       #" << endl;
    }
    else if (i == 10) {
      cout << "#     PRESS ENTER     #" << endl;
    }
    else if (i == 11) {
      cout << "#     TO CONTINUE     #" << endl;
    }
    else if (i == height - 2) {
      cout << "#   W A S D to Move   #" << endl;
    }
    else if (i == height - 1){
      cout << "#  by Rafael & Sean   #" << endl;
    }
  }
  for (int i = 0; i < width + 1; i++) {
    cout << barrier;
  }

  return;
}

// function to call loading
void loading()
{
  for (int i = 0; i < width + 1; i++) {
      cout << barrier;
  }
  cout << endl;
  for (int i = 0; i < height; i++) {
    if ((i < 6 || i > 13 || i == 9) && i < 18) {
      for (int j = 0; j < width + 1; j++) {
        if (j == 0) {
          cout << barrier;
        }
        else if (j == width) {
          cout << barrier << endl;
        }
        else {
          cout << ' ';
        }
      }
    }
    else if (i == 6) {
      cout << "#     ~~~~~~~~~~      #" << endl;
    }
    else if (i == 7) {
      cout << "#     LOADING...      #" << endl;
    }
    else if (i == 8) {
      cout << "#     ~~~~~~~~~~      #" << endl;
    }
    else if (i == 10) {
      cout << "#        press        #" << endl;
    }
    else if (i == 11) {
      cout << "#   w a s d in half   #" << endl;
    }
    else if (i == 12) {
      cout << "#      a second       #" << endl;
    }
    else if (i == 13) {
      cout << "#     then enter      #" << endl;
    }
    else if (i == height - 2) {
      cout << "#    GRAB THE $$$     #" << endl;
    }
    else if (i == height - 1) {
      cout << "#       <><><>        #" << endl;
    }
  }
  for (int i = 0; i < width + 1; i++) {
    cout << barrier;
  }

  cout << endl;

  return;
}

void setFruitPosition()
{
  current.fruitx = 1 + (rand() % width);
  current.fruity = 1 + (rand() % height);
  if (current.fruitx > (width - 2)){
    current.fruitx = width - 2;
  } 
  if (current.fruity > (height - 2)){
    current.fruity = height - 2;
  }
} 

// a function to setup the game
void startPosition()
{
  srand(time(NULL));                // randomized seed
  gameOver = false;
  current.x = width / 2;
  current.y = height / 2;
  setFruitPosition();
  current.score = 0;
}

// a function to draw the interface
void userInterface()
{
  system("clear");
  for (int i = 0; i < width; i++) {
    cout << barrier;
  }
  cout << endl;
  for (int i = 0; i < height; i++) {
    if (i == 0){
      cout << "#### Grab the $!! ####";
    }
    if (i == height - 1){
      cout << "####" << " Score:" << setw(6) << current.score << " " << "####";
    } else {
      for (int j = 0; j < width; j++) { 
        if (j == 0 && i != 0) {
          cout << barrier;
        }
        else if (i == current.y && j == current.x && i != 0 && j != width-1) {
          cout << "O";
        }
        else if (i == current.fruity && j == current.fruitx) {
          cout << fruit;
        }
        else {
          bool print = false;
          for (int k = 0; k < totalTail; k++) {
            if (tail_x[k] == j && tail_y[k] == i && i != 0 && j != width-1)
            {
              cout << "o";
              print = true;
            }
          }
          if (!print)
              cout << " ";
        }

        if (j == width - 2 && i != 0) {
          cout << barrier;
        }
      }
    }
    cout << endl;
  }
  for (int k = 0; k < width; k++) {
    cout << barrier;
  }
  cout << endl;
  cout << endl;
  cout << "Score: " << current.score << endl;
}

void userInput(char z)
{
  if( z == 'a' || z == 'A'){
    current.x--;
  }
  if( z == 'd' || z == 'D' ){
    current.x++;
  }
  if( z == 's' || z == 'S' ){
    current.y++;
  }
  if( z == 'w' || z == 'W'){
    current.y--;
  }
  if( z == 'q' || z == 'Q'){
    gameOver = true;
  }
}

void gameplay()
{
  int prev_x = tail_x[0];
	int prev_y = tail_y[0];
	int prev_2x, prev_2y;
	tail_x[0] = current.x;
	tail_y[0] = current.y;
	for (int i = 1; i < totalTail; i++)
	{
		prev_2x = tail_x[i];
		prev_2y = tail_y[i];
		tail_x[i] = prev_x;
		tail_y[i] = prev_y;
		prev_x = prev_2x;
		prev_y = prev_2y;
	}

  if (current.x >= width){
    current.x = 0;
  } else if (current.x < 0) {
    current.x = width - 1;
  }
	if (current.y >= height){
    current.y = 0;
  } else if (current.y < 0){
    current.y = height - 1;
  }

	for (int i = 1; i < totalTail; i++){
		if (tail_x[i] == current.x && tail_y[i] == current.y){
			gameOver = true;
    }
  }

  if (current.x == current.fruitx && current.y == current.fruity)
	{
		current.score += 10;
		setFruitPosition();
		totalTail++;
	}
}

void endMenu() {
  cout << endl;
  cout << "Thanks for playing!" << endl;
  cout << "Press Ctrl + C to exit" << endl; 
}

bool bool_game_over() {
  return gameOver;
}

int finalScore() {
  return current.score;
}