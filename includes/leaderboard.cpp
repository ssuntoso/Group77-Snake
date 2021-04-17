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

void addScore(const Player& p){
    players.push_back(p);
    return;
}

void openLeaderboard(){
    fin.open("leaderboard.txt");
    if(fin.fail()){
        return;
    }

    string x;
    while(getline(fin, x)){
        string playerName = "", playerScore = "";
        int i;

        for (i = 0; i < x.length(); i++){
            if(x[i] == '/' && x[i+1] == '?' ){
                break;
            }
        }
        
        playerName = x.substr(0, i);
        for(i = i + 2; i < x.length(); i++){
            playerScore += x[i];
        }

        int int_playerScore = stoi(playerScore);

        Player p(playerName, int_playerScore);
        addScore(p);
    }
}

void storeScore() {
    fout.open("leaderboard.txt");

    for (vector<Player>::iterator iter = players.begin() ; iter != players.end(); ++iter){
        fout << iter->playerName << "/?" << iter->score << endl;
    }

    return;
}

void printLeaderBoard() {
    cout << endl;
    cout << setw(17) << "LEADERBOARD" << endl;
    for (int i = 0; i < players.size(); ++i) {
        cout << players[i].playerName << setfill('.') << setw(25 - (players[i].playerName).length()) << players[i].score << endl;
    }
} 

void closeLeaderboard(){
    fin.close();
    fout.close();
}

bool cmp_player_score(const Player & a, const Player & b) {
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

void sortingPlayer(){
    sort(players.begin(), players.end(), cmp_player_score);
}
