#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

#include "includes/leaderboard.h"
#include "includes/gameplayLogic.h"

using namespace std;

int main()
{
    int stopPlaying = false;
    char askUser = 'n';

    openLeaderboard();

    menu();
    getchar();
    while (stopPlaying == false){
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
	
    while (!gameOver){
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

    Player p(currentPlayer, current.score);
    addScore(p);

    // sort according to score
    sortingPlayer();

    printLeaderBoard();
	    
    cout << endl;
    cout << "Do you want to play again? [y/n]" << endl;
    cin >> askUser;
	    
    if (askUser == 'y'){
      gameOver = false;
      continue;
    } 
    else if (askUser == 'n') {
      cout << "Thanks for playing!" << endl;
      usleep(3000000);
      stopPlaying = true;
      break;
    }
    else {
      cout << "Thanks for playing!" << endl;
      usleep(3000000);
      stopPlaying = true;
      break;
    }
  }

  storeScore();
	
  closeLeaderboard();
	
  return 0;
}
