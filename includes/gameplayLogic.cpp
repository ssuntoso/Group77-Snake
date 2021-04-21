/*
Game Title: SNAKE-77
Group     : 77
Author    : Kwan, Rafael Matthew Susanto (3035742425)
            Suntoso, Sean Michael (3035742437)
  
This cpp file is a part of the COMP2113 course project SNAKE-77.

required separated files for this cpp file:
- ./includes/gameplayLogic.h
- Makefile
 
This program is the logic of the game, containing functions
that print the interface of the menu, loading screen,
arena, random fruit, and dynamic snake.
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

// the constant height and width throughout all the interfaces
// used to limit the game arena
const int height = 22;
const int width = 22;

// the constant barrier and fruit character to be used in the gameplay
const char barrier = '#';
const char fruit = '$';

// intitialize bool value to stop the while loop of the game
bool gameOver;

// initialize arrays of int for the snake tails' positions
int tail_x[400], tail_y[400];

// number of tail set to one since the first tail will print before the snake head
int totalTail = 1;

// initiate current position
position current;

int stopPlaying = false;

char askUser;

// function to print the menu interface
void menu()
{
  for (int i = 0; i < width + 1; i++) {   // print the top barrier
      cout << barrier;
  }
  cout << endl;

  // loop until the end of height and width to print the middle section
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

  for (int i = 0; i < width + 1; i++) {   // print the bottom barrier
    cout << barrier;
  }

  return;
}

// function to print loading screen
void loading()
{
  for (int i = 0; i < width + 1; i++) {   // print the top barrier
      cout << barrier;
  }
  cout << endl;

  // loop until the end of height and width to print the middle section
  // a small 'how to play' description
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
  for (int i = 0; i < width + 1; i++) {   // print the bottom barrier
    cout << barrier;
  }

  cout << endl;

  return;
}

// function to randomized food position
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

// function to set up the starting point
void startPosition()
{
  srand(time(NULL));        // randomized seed
  gameOver = false;
  current.x = width / 2;    // middle of the widthh
  current.y = height / 2;   // middle of the heigth

  setFruitPosition();       // random food position
  current.score = 0;        // inititate score
}

// function to print the arena, snake head, tails, and fruits
void userInterface()
{
  system("clear");                      // refresh screen

  for (int i = 0; i < width; i++) {     // print the top barrier
    cout << barrier;
  }
  cout << endl;

  // loop until the end of height and width to print the middle section
  for (int i = 0; i < height; i++) {
    if (i == 0){
      cout << "#### Grab the $$$ ####";
    }
    if (i == height - 1){
      cout << "### " << "Account:"  << setw(5) << current.score << "$ ###";   // score indication
    }
    else {
      for (int j = 0; j < width; j++) { 
        if (j == 0 && i != 0) {         // print the left barrier
          cout << barrier;
        }
        else if (i == current.y && j == current.x && i != 0 && j != width-1) {
          cout << "O";                  // print snake head
        }
        else if (i == current.fruity && j == current.fruitx) {
          cout << fruit;                // print fruit
        }
        else {
          bool print = false;           // intialize bool value to whether print tail or space
          for (int k = 0; k < totalTail; k++) {
            if (tail_x[k] == j && tail_y[k] == i && i != 0 && j != width-1)
            {
              cout << "o";              // print tails
              print = true;
            }
          }
          if (!print)
              cout << " ";              // print spaces
        }

        if (j == width - 2 && i != 0) { // print the right barrier
          cout << barrier;
        }
      }
    }
    cout << endl;
  }
  for (int k = 0; k < width; k++) {     // print the bottom barrier
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
    current.x = 1;                  // on the right, it will reset x to the left side
  } 
  else if (current.x < 1) {       
    current.x = width - 2;          // on the left, it will reset x to the right side
  }
  if (current.y >= height - 1){
    current.y = 1;                  // on the bottom, it will reset y to the top
  }
  else if (current.y < 1){
    current.y = height - 2;         // on the top, it will reset y to the bottom
  }

  int prev_x = tail_x[0];           // store previous tail
	int prev_y = tail_y[0];
	int prev_2x, prev_2y;
	tail_x[0] = current.x;            // tail position follow current position (snake head)
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

// function to return the gameOver value
bool bool_game_over() {
  return gameOver;
}

// function to return the final score
int finalScore() {
  return current.score;
}