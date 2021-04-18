// This program is for leaderboard functions

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

void addScore(const Player& p)
{
    players.push_back(p);
    return;
}

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

        for (i = 0; i < x.length(); i++) {
            if (x[i] == '/' && x[i+1] == '?' ) {
                break;
            }
        }
        
        playerName = x.substr(0, i);
        for (i = i + 2; i < x.length(); i++) {
            playerScore += x[i];
        }

        int int_playerScore = stoi(playerScore);

        Player p(playerName, int_playerScore);
        addScore(p);
    }
}

void storeScore()
{
    fout.open("leaderboard.txt");

    for (vector<Player>::iterator iter = players.begin() ; iter != players.end(); ++iter) {
        fout << iter->playerName << "/?" << iter->score << endl;
    }

    return;
}

void sortingPlayer()
{
    sort(players.begin(), players.end(), cmp_player_score);

    return;
}

void printLeaderBoard()
{
    bool highestscore = true;
    cout << "#####################" << endl;
    cout << "#     GAMEOVER!     #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~#" << endl;
    for (int i = 0; i < players.size() - 1; ++i) {
        if (players.back().score < players[i].score) {
            highestscore = false;
        }
    }
    if (highestscore) {
        if ((players.back().playerName).length() > 4) {
            cout << "#       " << (players.back().playerName).substr(0, 5) << "       #" << endl;
            cout << "# beat the HIGHSCORE#" << endl;
        }
        else if ((players.back().playerName).length() == 4) {
            cout << "#       " << players.back().playerName << "        #" << endl;
            cout << "# beat the HIGHSCORE#" << endl;
        }
        else if ((players.back().playerName).length() == 3) {
            cout << "#       " << players.back().playerName << "         #" << endl;
            cout << "# beat the HIGHSCORE#" << endl;
        }
        else if ((players.back().playerName).length() == 2) {
            cout << "#       " << players.back().playerName << "          #" << endl;
            cout << "# beat the HIGHSCORE#" << endl;
        }
        else if ((players.back().playerName).length() == 1) {
            cout << "#       " << players.back().playerName << "           #" << endl;
            cout << "# beat the HIGHSCORE#" << endl;
        }
        else {
            cout << "#     you beat      #" << endl;
            cout << "#   the HIGHSCORE   #" << endl;
        }
    } else {
        cout << "#  you didn't beat  #" << endl;
        cout << "#   the HIGHSCORE   #" << endl;
    }
    cout << "#~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#    LEADERBOARD    #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~#" << endl;
    sortingPlayer();
    for (int i = 0; i < 13; ++i) {      // top 13 leaderboard to fit the interface
        cout << '#' << (players[i].playerName).substr(0, 5) << setfill('.')
                << setw(19 - (((players[i].playerName).length() < 6)? (players[i].playerName).length() : 5))
                << players[i].score << '#' << endl;
    }
    cout << "#####################" << endl;

    return;
}

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

