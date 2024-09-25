#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include <vector>
using namespace std;

class Blackjack {
  public:
    Blackjack();
    //Blackjack(string yesorNO);
    string GetResponse(string yesorNO);
    void Know_howPlay();
    void GamePlay(string yes_no);
    int PlayerGame();
    void chanceToWin();
    vector<int> Result();

  private:
    int playerCards;
    int dealerCards;
    int playerScore;
    int dealerScore;
    string yesNO;
};

#endif