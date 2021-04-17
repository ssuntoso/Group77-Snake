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

void addScore(const Player& p);

void openLeaderboard();

void storeScore();

void printLeaderBoard();

void closeLeaderboard();

bool cmp_player_score(const Player & a, const Player & b);

void sortingPlayer();

#endif