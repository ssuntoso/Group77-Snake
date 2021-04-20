/*
 * Games Title  : SNAKE
 * Author       : Kwan, Rafael Matthew Susanto (3035742425)
 *                Suntoso, Sean Michael (3035742437)
 * Group        : 77
 * 
 * This main file is part of COMP2113 final project SNAKE.
 * 
 * requiered files  : 
 * ./includes/gameplayLogic.cpp
 * ./includes/gameplayLogic.h 
 * ./includes/leaderboard.cpp
 * ./includes/leaderboard.h
 * Makefile
 * 
 * use command $ make all to compile
 * use command $ make clean to reset and clean the game
 * 
 * SNAKE is a single-playe game with goal to grow the snake
 * as long as the snake not bite its own body. To grow the 
 * snake, player need to grab the $ that set randomly in the
 * play (20 x 20) area by using a w s d and enter to control 
 * the snake and q to exit. When player manage to grab the $,
 * he/she will get 10$ and the snake will grow longer.
 * 
 * If the snake eat its own body, the game will end and the 
 * leaderboard will display top 10 players. To exit the game,
 * player need to hit Ctrl + C.   
 * 
 * Enjoy ^_^
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm>

#include <unistd.h>
#include <stdio.h>

#include "includes/leaderboard.h"
#include "includes/gameplayLogic.h"

using namespace std;

int main()
{
  // check the laederboard file and 
  // open it if leaderboard.txt exist
  openLeaderboard();

  // display the main welcome screen
  menu();

  // to pause program in the welcome screen 
  // until the player hit enter
  getchar();
  
  // asking for player name
  string currentPlayer;
  system("clear");        
  cout << "Input your name: ";
  getline(cin, currentPlayer);

  // if player not input his/her name, he/she 
  // will recognize as "Player"
  if (currentPlayer.empty()) {
    currentPlayer = "Player";
  }
  cout << endl;
  system("clear");      
  
  //display the loading screen
  loading();

  // pause the program for 2 seconds 
  usleep(2000000);

  char z, oldz, nextz;

  // set position on board
  startPosition();    

  // display the game area
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

  system("clear"); 
  Player p(currentPlayer, finalScore());

  // add score to the vector players
  addScore(p);                

  // display the leaderboard and game over screen
  printLeaderBoard();

  //store score in leaderboard.txt and close the file
  storeScore();
  closeLeaderboard();

  // display thank you message in the end menu
  endMenu();

  return 0;
}
