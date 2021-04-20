/*
 * Games Title  : SNAKE
 * Author       : Kwan, Rafael Matthew Susanto (3035742425)
 *                Suntoso, Sean Michael (3035742437)
 * Group        : 77
 * 
 * This header file is part of COMP2113 final project SNAKE.
 * 
 * This header file containing function required to process the game
 * score leaderboard and store it in a file and function required
 * after the game.
 * 
 * requiered files  : 
 * ./includes/gameplayLogic.cpp
 * ./includes/gameplayLogic.h 
 * ./includes/leaderboard.cpp
 * ./includes/leaderboard.h
 * Makefile
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