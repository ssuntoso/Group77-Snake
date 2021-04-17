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
  while (bool_stop_playing() == false){
    string currentPlayer = "";
    system("clear");
    cout << "Please, input your name!" << endl;
    getline(cin, currentPlayer);
    getchar();
    system("clear");
    cout << endl;
    cout << endl;
    cout << setw(17) << "Thank you!" << endl;
    cout << setw(18) << "Please wait" << endl;
    cout << setw(21) << "while we are preparing" << endl;
    cout << setw(17) << "your board" << endl;
    usleep(1000000);

    char z, oldz, nextz;
    startPosition();    // set position on board
    userInterface();
    cin >> z;
    oldz = z;
    userInput(z);
	
    while (bool_game_over() == false){
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
    }
	    
    system("clear");
    cout << endl;
    cout << setw(16) << "GAMEOVER" << endl;
    cout << currentPlayer << endl;

    Player p(currentPlayer, finalScore());
    addScore(p);

    // sort according to score
    sortingPlayer();

    printLeaderBoard();
	    
    endMenu();
  }

  storeScore();
	
  closeLeaderboard();
	
  return 0;
}
