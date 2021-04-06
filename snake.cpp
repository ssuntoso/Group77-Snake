#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
using namespace std;

const int height = 20;
const int width = 20;
const char barrier = 'H';
const char fruit = '*';
bool gameOver;

int nTail;

class position {
public:
  int x;
  int y;
  int fruitx;
  int fruity;
  int score;
};
position current;

// a function to setup the game
void startPosition()
{
  srand(time(NULL));                // randomized seed
  gameOver = false;
  current.x = width / 2;
  current.y = height / 2;
  current.fruitx = rand() % width;
  current.fruity = rand() % height;
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
      else if (j == width - 1) {
        cout << barrier;
      }
      else {
            cout << " ";
      }
    }
    cout << endl;
  }
  for (int k = 0; k < width; k++) {
    cout << barrier;
  }
  cout << endl;
  cout << endl;
  cout << endl;
}

void userInput(char z)
{
  if( z == 'a' ){
    current.x--;
  }
  if( z == 'd' ){
    current.x++;
  }
  if( z == 's' ){
    current.y++;
  }
  if( z == 'w' ){
    current.y--;
  }
  if( z == 'x' ){
    gameOver = true;
  }
}

void gameplay()
{
  if (current.x == current.fruitx && current.y == current.fruity)
	{
		current.score += 10;
		current.fruitx = rand() % width;
		current.fruity = rand() % height;
		nTail++;
	}
}

int main()
{
  char z;

  startPosition();    // set position on board
  while (gameOver == false)
  {
    userInterface();
    gameplay();
    cin >> z;
    userInput(z);
    //usleep(5000);
  }
  
}
