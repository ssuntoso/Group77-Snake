#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int height = 20;
const int width = 20;
const char border = 178;

class position {
public:
  int x;
  int y;
  int fruitx;
  int fruity;
};

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void Draw()
{
  system("cls");
  for (int i = 0; i < width; i++) {
    cout << border;
  }
  cout << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0) {
        cout << border;
      }
      if (i == position.x && j == position.y) {
        cout << "O";
      }
      if (j == width - 1) {
        cout << border;
      }
    }
  }
}
  
