#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm>

#include "includes/leaderboard.h"
#include "includes/gameplayLogic.h"

using namespace std;

int main()
{
  openLeaderboard();

  menu();
  getchar();

  // loop the game until user exit after game end
  
  string currentPlayer;
  system("clear");
  cout << "Input your name: ";
  getline(cin, currentPlayer);
  cout << endl;
  system("clear");
  
  loading();
  
  usleep(2000000);
  char z, oldz, nextz;
  startPosition();    // set position on board
  userInterface();
  cin >> z;
  oldz = z;
  userInput(z);

  while (true){
    userInterface();
    thread t1([&](){
      cin >> nextz;
      userInput(nextz);
      oldz = nextz;
    });
    this_thread::sleep_for(chrono::milliseconds(500));
    t1.detach();
    if (!nextz) {
	    userInput(oldz);
    }
    gameplay();
    nextz = 0;
    if (bool_game_over()){
      break;
    }
  }
	
  // gameover screen
  system("clear");
  Player p(currentPlayer, finalScore());
  addScore(p);

  printLeaderBoard();
  storeScore();
  closeLeaderboard();
  endMenu();
  cin.get();

  return 0;
}
