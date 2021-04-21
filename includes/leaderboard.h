/*
Game Title: SNAKE-77
Group     : 77
Author    : Kwan, Rafael Matthew Susanto (3035742425)
            Suntoso, Sean Michael (3035742437)
  
This header file is a part of the COMP2113 course project SNAKE-77.

required separated files for this header file:
- Makefile
 
This header file containing function required to process the game
score leaderboard and store it in a file and function required
after the game. Correlated with leaderboard.cpp
*/

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <string>

using namespace std;

struct Player {
  string playerName;
  int score;
  Player(string playerName, int score) {
    this->playerName = playerName;
    this->score = score;
  };
};

// add score to vector
void addScore(const Player& p);

// open leaderboard.txt and obtain previous players and score
void openLeaderboard();

// store score obtain previously and new score recorded 
// and write to leaderboard.txt
void storeScore();


void printLeaderBoard();

// print the final message to thank player and ask him/her
// to hit Ctrl + C
void endMenu();

// close leaderboard.txt
void closeLeaderboard();


bool cmp_player_score(const Player & a, const Player & b);

// sort players according to the score in an descending order
// and according to lexicographical order if players have the same score
void sortingPlayer();

#endif