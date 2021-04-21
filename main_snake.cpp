/*
 * Game Title: SNAKE-77
 * Group     : 77
 * Author    : Kwan, Rafael Matthew Susanto (3035742425)
 *             Suntoso, Sean Michael (3035742437)
 *   
 * This cpp file is the main part of COMP2113 course project SNAKE-77.
 * 
 * required separated files for this cpp file:
 * - ./includes/gameplayLogic.cpp
 * - ./includes/gameplayLogic.h 
 * - ./includes/leaderboard.cpp
 * - ./includes/leaderboard.h
 * - Makefile
 *  
 * use command $ make all to compile
 * use command $ make clean to reset and clean the game
 * 
 * SNAKE-77 is an arcade single-player game with goal to grow the snake
 * until the snake touches its own tails. To grow the snake,
 * player need to grab the $ that set randomly in a 20 x 20 playing arena
 * by pressing w a s d and enter to control the movement of the snake
 * or press q to exit ongoing game. When players manage to grab the $,
 * 10$ will be added to their account and the snake will grow 1 tail.
 * 
 * If the arcade gameplay is over, the game will print the outro and 
 * leaderboard that display top 10 richest players. To exit the game,
 * player need to hit Ctrl + C.   
 * 
 * Enjoy the game.
 */

#include <iostream>
#include <iomanip>
#include <string>     // string manipulation
#include <ctime>      // random seed
#include <thread>     // time limit
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm>  // to sort

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

  cin >> z;     // get movement input from user
  oldz = z;     // store movement

  userInput(z); // to move the snake


  while (true) {
    // print gameplay interface
    userInterface();

    // thread for countdown
    thread t1([&](){
      cin >> nextz;     // get new movement input
      userInput(nextz); // move the snake
      oldz = nextz;     // store movement
    });
    this_thread::sleep_for(chrono::milliseconds(500));
    t1.detach();        // after half a second if there is no input, it will this block

    if (!nextz) {       // if the new movement input is 0
	    userInput(oldz);  // move the snake using the previous stored movement
    }

    gameplay();         // gameplay logic function

    nextz = 0;          // reset new movement input

    if (bool_game_over()){
      break;            // if gameOver is true, break the loop
    }
  }

  system("clear");      // refresh screen

  // construct a player p with the current name and the final score
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
