#include "Blackjack.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//This is the constructor
Blackjack::Blackjack() {
   playerCards = 0;
   dealerCards = 0;
   playerScore = 0;
   dealerScore = 0;
   yesNO = "sup";
}

/* Blackjack::Blackjack(string yesorNO){
   cin >> yesorNO;

   for(int i = 0; i < yesorNO.length(); i++){
     yesorNO[i] = tolower(yesorNO[i]);
   }

   yesNO = yesorNO;

}*/

string Blackjack::GetResponse(string yesorNO){
  int i;

  while(true){
    for (i = 0; i < yesorNO.length(); i++){
      yesorNO[i] = tolower(yesorNO[i]);
    }
    if (yesorNO == "yes" || yesorNO == "no") {
        break; // Exit the loop if the input is "yes" or "no"
    } else {
        cout << "Invalid input. Please enter 'yes' or 'no': ";
        cin >> yesorNO;
        cout << endl;
    }
  }
  return yesorNO;
}

void Blackjack::Know_howPlay(){
  cout << "\nRat_King: Alright kid lets play some Blackjack. But before we do, do you know how to play Blackjack?\n" << endl;
  cout << "Type Yes or No >> "; 
  cin >> yesNO;
  string response = GetResponse(yesNO); //This function check if player input ither "yes" or "no" regaurdless of capital letters

  cout << endl << endl;

  cout <<"Rat_King: Thats great, lets get started. \n" << endl;

  GamePlay(response);

}

void Blackjack::GamePlay(string yes_no){
  // Seed the random number generator with the current time bc you need luck to win Blackjack
  srand(time(0)); 
  int numRounds = 3; //Best of 3 rounds wins. the for-loops checks that

  if (yes_no == "yes"){
    //player would have a chance to win
    for (int round = 1; round <= numRounds; round++){
      cout << "\nRound " << round <<":"<< endl;
      playerCards = PlayerGame();

      cout << "Your cards total: " << playerCards << endl;
      cout<<"Do you want to hit (h) or stand (s)? >> "; cin >> yes_no;
      //allow the player to hit or stand. just like in Blackjack irl
      while (yes_no != "s"){ //this loop will stop when player stand
        playerCards += PlayerGame();
        cout << "\nYour cards total: " << playerCards << endl;
        if(playerCards > 21){
          break; //If player is over 21 the loop will break & player will lose
        }
        cout<<"Do you want to hit (h) or stand (s)? >> "; 
        cin >> yes_no; 
      }

      dealerCards = rand() % 17 + 5; //dealer will grab a random number between 5 and 21
      cout << "\nRat_King cards total: " << dealerCards << endl;

      if (playerCards > 21){ //Automatically lose when over 21
        cout << "\nYou Busted!" << endl;
        dealerScore++;
      }
      else if ((playerCards < 21 && playerCards > dealerCards) || (playerCards == 21) || dealerCards > 21){
        cout << "\nYou Win!" << endl;
        playerScore++;
      }
      else if (playerCards < dealerCards || dealerCards == 21){
        cout << "\nYou Lose!" << endl;
        dealerScore++;
      }
      else if (playerCards == dealerCards){
        cout <<"Its a Tie!" << endl; 
        //would add extra round if player and program have same score 
        numRounds++;
      }
    }
    cout <<"\nYour score: " << playerScore << endl;
    cout <<"Rat_King's score: " << dealerScore << endl;
  }//end of if (yes)
  else if (yes_no == "no"){
    //Player will lose granteed
    //It is the same code as the if statement above but with a different outcome
    for (int round = 1; round <= numRounds; round++){
      cout << "\nRound " << round <<":"<< endl;
      playerCards = PlayerGame();

      cout << "Your cards total: " << playerCards << endl;
      cout<<"Do you want to hit (h) or stand (s)? >> "; cin >> yes_no;

      while (yes_no != "s"){
        playerCards += PlayerGame();
        cout << "\nYour cards total: " << playerCards << endl;
        if(playerCards > 21){
          break;
        }
        cout<<"Do you want to hit (h) or stand (s)? >> "; 
        cin >> yes_no; 
      }
    //the if statment below allows the program to win depening on           the outcome of the player
      if(playerCards < 21){ 
        dealerCards = playerCards + (rand() % 4 + 1);
        if (dealerCards > 21){
          dealerCards = 21;
        }
      }
      cout << "\nRat_King cards total: " << dealerCards << endl;

      //Removed the if player win conditon
      if (playerCards > 21){
        cout << "\nYou Busted!" << endl;
        dealerScore++;
      }
      else if (playerCards < dealerCards || dealerCards == 21){
        cout << "\nYou Lose!" << endl;
        dealerScore++;
      }
      else if (playerCards == dealerCards){
        cout <<"Its a Tie!" << endl;
        numRounds++;
      }
    }
    cout <<"\nYour score: " << playerScore << endl;
    cout <<"Rat_King's score: " << dealerScore << endl;
  }
}

vector<int> Blackjack::Result(){
  vector<int> whoWins = {playerScore, dealerScore};

  return whoWins;
}

int Blackjack::PlayerGame(){
  int card = rand() % 14 + 1;

  return card;
}


  