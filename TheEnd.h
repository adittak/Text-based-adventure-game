#ifndef THEEND_H
#define THEEND_H
#include "Blackjack.h"

#include <string>
#include <vector>
using namespace std;

class TheEnd{
  public:
    void FinalLevel(string name);
    void Endof_Match(vector<int> results);
    void ASCII_Art();
    void ASCII_Art2();

  private:
    Blackjack bJack;
};

#endif