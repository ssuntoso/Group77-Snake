#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
using namespace std;

const int height = 20;
const int width = 20;
const char barrier = 178;
bool gameOver;

class position {
public:
  int x;
  int y;
  int fruitx;
  int fruity;
  int score;
};
position current;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// a function to setup the game
void startPosition()
{
  srand(time(NULL));                // randomized seed
  gameOver = false;
  dir = STOP;
  current.x = width / 2;
  current.y = height / 2;
  current.fruitx = rand() % width;
  current.fruity = rand() % height;
  current.score = 0;
}

// a function to draw the interface
void userInterface()
{
  system("cls");
  for (int i = 0; i < width; i++) {
    cout << barrier;
  }
  cout << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0) {
        cout << barrier;
      }
      else if (i == current.x && j == current.y) {
        cout << "O";
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
}

int main()
{
  startPosition();
  userInterface();
}
