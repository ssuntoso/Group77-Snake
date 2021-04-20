/*
 * Games Title  : SNAKE
 * Author       : Kwan, Rafael Matthew Susanto (3035742425)
 *                Suntoso, Sean Michael (3035742437)
 * Group        : 77
 * 
 * This cpp file is part of COMP2113 final project SNAKE.
 * 
 * This program is the logic of the game. containing function
 * required during the game.
 * 
 * requiered files  : 
 * ./includes/gameplayLogic.cpp
 * ./includes/gameplayLogic.h 
 * ./includes/leaderboard.cpp
 * ./includes/leaderboard.h
 * Makefile
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>

#include <unistd.h>
#include <stdio.h>

#include "gameplayLogic.h"

using namespace std;

// height and width set to 22 since it is also 
// include the barrier at left, right, top and bottom
const int height = 22;        
const int width = 22;

const char barrier = '#';
const char fruit = '$';
bool gameOver;

int tail_x[400], tail_y[400];

// set to one since the first tail will print under the snake head
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
      cout << "#### Grab the $$$ ####";
    }
    if (i == height - 1){
      cout << "### " << "Account:"  << setw(5) << current.score << "$ ###";
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
}


// control the snake from user input by 
// add or subtract current x and y by 1
// and change the state to gameover if 
// player input `q`.
void userInput(char z)
{
  if( z == 'a' || z == 'A'){    // go left -> subtract x by 1
    current.x--;
  }
  if( z == 'd' || z == 'D' ){   // go right -> add x by 1
    current.x++;
  }
  if( z == 's' || z == 'S' ){   // go down -> subtract y by 1
    current.y++;
  }
  if( z == 'w' || z == 'W'){    // go up -> add x by 1
    current.y--;
  }
  if( z == 'q' || z == 'Q'){     // end the game
    gameOver = true;
  }
}


// this function check snake head x and y possition 
// and display according to the rules
void gameplay()
{
  // if the snake reach the end of the playing area
  if (current.x >= width - 1){      
    current.x = 1;                  // on the right, it will reset x to 1
  } 
  else if (current.x < 1) {       
    current.x = width - 2;          // on the left, it will reset x to the right side
  }
  if (current.y >= height - 1){
    current.y = 1;                  // on the bottom, it will reset y to 1
  }
  else if (current.y < 1){
    current.y = height - 2;         // on the top, it will reset y to bottom
  }

  int prev_x = tail_x[0];
	int prev_y = tail_y[0];
	int prev_2x, prev_2y;
	tail_x[0] = current.x;
	tail_y[0] = current.y;
  
  // print snake tail according to totalTail
  // print it following the snake head by obtaining 
  // the previous x and y of the snake head location
  // and store it in tail_x and tail_y array
	for (int i = 1; i < totalTail; i++) {
		prev_2x = tail_x[i];
		prev_2y = tail_y[i];
		tail_x[i] = prev_x;
		tail_y[i] = prev_y;
		prev_x = prev_2x;
		prev_y = prev_2y;
	}

  // this condition will check if the snake head hit its body
  // by compare snake head location with location inside the 
  // tail_x and tail_y array. if so, the gameOver variable set
  // to true and end the game.
	for (int i = 1; i < totalTail; i++){
		if (tail_x[i] == current.x && tail_y[i] == current.y){
			gameOver = true;
    }
  }

  // check the snake head location and compare it to the fruit($)
  // location. if it is the same, it mean that the snake grabbed 
  // the $
  if (current.x == current.fruitx && current.y == current.fruity)
	{
		current.score += 10;    // add 10$ to current score
		setFruitPosition();     // set $ to different location on the play area
		totalTail++;            // grow the tail by add 1
	}
}

bool bool_game_over() {
  return gameOver;
}

int finalScore() {
  return current.score;
}