/*
 * Games Title  : SNAKE
 * Author       : Kwan, Rafael Matthew Susanto (3035742425)
 *                Suntoso, Sean Michael (3035742437)
 * Group        : 77
 * 
 * This cpp file is part of COMP2113 final project SNAKE.
 * 
 * This program containing function required to process the game
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

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> 
#include <algorithm>

#include "leaderboard.h"

using namespace std;

ifstream fin;
ofstream fout;

vector<Player> players;

// add player score to vector players
void addScore(const Player& p)
{
    players.push_back(p);
    return;
}

// open leaderboard.txt if exist. 
// If not, it will return. 
// If yes, it will get the name and previous players
// scores and store it to vector players
void openLeaderboard()
{
    fin.open("leaderboard.txt");
    if (fin.fail()) {
        return;
    }

    string x;
    while (getline(fin, x)) {
        string playerName = "", playerScore = "";
        int i;

        // detecting "/?" that separate players name and score
        // and break when it find "/?"
        for (i = 0; i < x.length(); i++) {
            if (x[i] == '/' && x[i+1] == '?' ) {
                break;
            }
        }
        
        // get player name by using the i obtain before
        playerName = x.substr(0, i);

        // using previous i, add 2 ("/?") is 2 character 
        // get the score digit by digit until end of x.                
        for (i = i + 2; i < x.length(); i++) {
            playerScore += x[i];
        }
        
        // change string to integer 
        int int_playerScore = stoi(playerScore);

        // add players and score to vector players
        Player p(playerName, int_playerScore);
        addScore(p);
    }
}


// store score obtain previously and new score recorded 
// by iterating vector players and write to leaderboard.txt
void storeScore()
{
    fout.open("leaderboard.txt");

    for (vector<Player>::iterator iter = players.begin() ; iter != players.end(); ++iter) {
        fout << iter->playerName << "/?" << iter->score << endl;
    }

    return;
}

// sort vector players according to the score in an descending order
// and according to lexicographical order if players have the same score
void sortingPlayer()
{
    sort(players.begin(), players.end(), cmp_player_score);

    return;
}

void printLeaderBoard()
{
    bool highestscore = true;
    cout << "######################" << endl;
    cout << '#' << setw(21) << '#' << endl;
    cout << "#      GAMEOVER!     #" << endl;
    cout << '#' << setw(21) << '#' << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << '#' << setw(21) << '#' << endl;
    for (int i = 0; i < players.size() - 1; ++i) {
        if (players.back().score < players[i].score) {
            highestscore = false;
        }
    }
    if (highestscore) {
        if (players.back().playerName == "Player"){
            cout << "#      you beat      #" << endl;
            cout << "#    the HIGHSCORE   #" << endl;
        }
        else if ((players.back().playerName).length() > 7) {
            cout << "#     " << (players.back().playerName).substr(0, 8) << "       #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
        else if ((players.back().playerName).length() == 7) {
            cout << "#      " << players.back().playerName << "       #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
        else if ((players.back().playerName).length() == 6) {
            cout << "#      " << players.back().playerName << "        #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
        else if ((players.back().playerName).length() == 5) {
            cout << "#       " << players.back().playerName << "        #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
        else if ((players.back().playerName).length() == 4) {
            cout << "#       " << players.back().playerName << "         #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
        else if ((players.back().playerName).length() == 3) {
            cout << "#        " << players.back().playerName << "         #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
        else if ((players.back().playerName).length() == 2) {
            cout << "#        " << players.back().playerName << "          #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
        else if ((players.back().playerName).length() == 1) {
            cout << "#         " << players.back().playerName << "          #" << endl;
            cout << "# beat the HIGHSCORE #" << endl;
        }
    } else {
        cout << "#   you didn't beat  #" << endl;
        cout << "#    the HIGHSCORE   #" << endl;
    }
    cout << '#' << setw(21) << '#' << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#   TOP 10 RICHEST   #" << endl;
    cout << "#    LEADERBOARD     #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~#" << endl;
    sortingPlayer();
    for (int i = 0; i < players.size() && i < 10; ++i) {      // top 10 leaderboard to fit the interface
        int interfacefit = 0;
        if ((players[i].playerName).length() < 9) {
            interfacefit = (players[i].playerName).length();
        }
        else {
            interfacefit = 8;
        }
        cout << "# " << (players[i].playerName).substr(0, 8) << setfill('.')
                << setw(18 - interfacefit) << players[i].score << " #" << endl;
    }
    cout << "######################" << endl;

    return;
}

// print the final message to thank player and ask him/her
// to hit Ctrl + C
void endMenu() {
  cout << endl;
  cout << "Thanks for playing!" << endl;
  cout << "Press Ctrl + C to exit" << endl; 

  // pause the program until player hit Ctrl + C
  cin.get();
}

// close leaderboard.txt
void closeLeaderboard()
{
    fin.close();
    fout.close();

    return;
}

bool cmp_player_score(const Player & a, const Player & b)
{
    if (a.score > b.score) {                // compare score
        return true;
    }
    else if (a.score == b.score) {
        if (a.playerName < b.playerName) {  // lexicographical order
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

