#include "Blackjack.h"
#include "Map.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
  string playerName;
  string playerResponse;
  bool validName = false;

  // user enters thier name
  cout << "Welcome player to your adventure game! \n" << endl;
  cout << "Enter your name Here --> ";
  getline(cin, playerName);

  // checks if the name doesn't have a space, if it does then it will repeat the
  // loop
  while (!validName) {

    for (int i = 0; i < playerName.length(); i++) {
      if (isspace(playerName.at(i))) {
        cout << "Invalid. Try again, don't use spaces--> ";
        getline(cin, playerName);
        validName = false;
        break;
      } else {
        validName = true;
      }
    }
  }

  cout << endl;

  Map Place;

  cout << "Hello " << playerName << "! Ready to start?" << endl;
  cout << "(lower case answers only) >> ";
  cin >> playerResponse;

  if (playerResponse == "yes" || playerResponse == "yea" ||
      playerResponse == "sure" || playerResponse == "no") {  //force the user to play the game despite the choice is "no". (Just for fun)  
    
    cout << endl << "Great lets get started!\n" << endl;
  }
  Place.Apartment(playerName);

  // The end or you could say the epilogue

  cout << "\nYou and Will are out of Park Place. You guys said your goodbyes "
          "and head to your homes"
       << endl;
  cout << "\nWill: OH hey, let me hold the gun and give it back to the manger "
          "tomorrow."
       << endl;
  cout << "\nYou hand the gun to Will and head to your apartment. You place "
          "the ring on your mom's table and head to your room to play "
          "Subnautica on the PS5."
       << endl;

  cout << "\nEnter anything to continue >> ";
  cin >> playerResponse;
  cout << endl;

  cout << "Mom comes home and puts on the ring. It doesn't fit. You are in big trouble."
       << endl;

  cout << "\n                            THE END";

  return 0;
}