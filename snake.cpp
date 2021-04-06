#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
using namespace std;

const int height = 20;
const int width = 20;
const char barrier = 178;
const char fruit = 229;
bool gameOver;

char oldz;

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

/*
void gameplay()
{
  return 0;
}
*/


void delay(int seconds)
{
    // Converting time into milli_seconds
    int milliSeconds = 1000 * seconds;
  
    // Storing start time
    clock_t startTime = clock();
  
    // looping till required time is not achieved
    while (clock() < startTime + milliSeconds){
      ;
    }
}

int main()
{
  char z;

  startPosition();
  while (gameOver == false)
  {
    z = false;

    userInterface();

    clock_t startTime = clock();
    cout << oldz;

    while (clock() < startTime + 50){
      cin >> z;
      if(z != oldz){
        oldz = z;
        break;
      }
    }
    // gameplay();
    userInput(oldz);
    //usleep(5000);
  }
  
}
