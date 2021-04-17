#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include "gameplayLogic.h"

using namespace std;

const int height = 20;
const int width = 20;
const char barrier = '#';
const char fruit = '$';
bool gameOver;

int tail_x[400], tail_y[400];

int totalTail;

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
                cout << "#     ~~~~~~~~      #" << endl;
            }
            else if (i == 7) {
                cout << "#     SNAKE-77      #" << endl;
            }
            else if (i == 8) {
                cout << "#     ~~~~~~~~      #" << endl;
            }
            else if (i == 10) {
                cout << "#    PRESS ENTER    #" << endl;
            }
            else if (i == 11) {
                cout << "#    TO CONTINUE    #" << endl;
            }
            else if (i == 18) {
                cout << "#  W A S D to Move  #" << endl;
            }
            else {
                cout << "# by Rafael & Sean  #" << endl;
            }
    }
    for (int i = 0; i < width + 1; i++) {
        cout << barrier;
    }
}

// a function to setup the game
void startPosition()
{
  srand(time(NULL));                // randomized seed
  gameOver = false;
  current.x = width / 2;
  current.y = height / 2;
  current.fruitx = rand() % (width - 1);
  current.fruity = rand() % (height - 1);
  current.score = 0;
}

// a function to draw the interface
void userInterface()
{
  system("clear");
  for (int i = 0; i < width + 1; i++) {
    cout << barrier;
  }
  cout << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0) {
        cout << barrier;
      }
      else if (i == current.y && j == current.x) {
        cout << "O";
      }
      else if (i == current.fruity && j == current.fruitx) {
        cout << fruit;
      }
      else {
            bool print = false;
            for (int k = 0; k < totalTail + 1; k++) {
                if (tail_x[k] == j && tail_y[k] == i)
                {
                    cout << "o";
                    print = true;
                }
            }
            if (!print)
                cout << " ";
			}

      if (j == width - 1) {
        cout << barrier;
      }
    }
    cout << endl;
  }
  for (int k = 0; k < width + 1; k++) {
    cout << barrier;
  }
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
		current.fruitx = rand() % (width - 1);
		current.fruity = rand() % (height - 1);
		totalTail++;
	}
}

void endMenu() {
  cout << endl;
  cout << "Do you want to play again? [y/n]" << endl;
  cin >> askUser;
	    
  if (askUser == 'y'){
    gameOver = false;
  } else if (askUser == 'n') {
    cout << "Thanks for playing!" << endl;
    usleep(3000000);
    stopPlaying = true;
  } else {
    cout << "Thanks for playing!" << endl;
    usleep(3000000);
    stopPlaying = true;
  }
}

bool bool_game_over() {
  return gameOver;
}

int finalscore() {
  return current.score;
}

bool bool_stop_playing() {
  return stopPlaying;
}