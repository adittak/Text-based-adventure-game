#include "TheEnd.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

string choices;
string playerLabel;

 void TheEnd::FinalLevel(string name){
   playerLabel = name;
   cout <<"-------------";

   cout <<"\nYou come across three paths. One is going left, one goes straigth forward, and the last one goes right. Which way do you want to go? (L, F, R)" <<endl;
   cout <<"Type L, F, or R: "; cin >> choices;
   
   while(true){
    if(choices == "L"){
      cout <<"\nYou chose to go left. But you ended up with a dead-end. It smells like expired milk mixed with sulfer. You went back to the intersection." <<endl;
      cout <<"Type L, F, or R: "; cin >> choices;
    }
    else if (choices == "F"){
      cout <<"\nYou chose to go forward. But there is a sleeping giant alligator. You and Will walked away slowly. " <<endl;
      
      ASCII_Art(); //Function of ASCII Art
      cout <<"Type L, F, or R: "; cin >> choices;
    }
     else if(choices == "R"){
       cout<<"\nYou chose to go right. A couple of rats pass by you and Will. at the end of the path you see a giant rat with a hat and trench coat, sitting on a chair smoking a cigar." <<endl;
       break;
     }
   }

   cout <<"\nWill: That must be the Rat_King." <<endl;
   cout <<"\nYou approched the Rat_King and saw your mother's ring on a shelf. You ask the Rat_King if you could have that ring back." <<endl;
   cout <<"Rat_King: Of cource you can have that ring back. Over a game of Blackjack. What do you have to offer?" <<endl;
   cout <<"\nWill: We got nothing to offer." <<endl;
   cout<<"\n(Smiling evily) Rat_King: Alright we will play best 2 out 3 games. If you manage to beat me I will give you the ring. But If I win then you guys have to work for me for the whole summer. 40 hrs a week, no pay!" <<endl;
   cout <<"\nYou and Will look at eachother and nod." <<endl;

   cout <<"\nRat_King: Do we have a deal? (Y/N)" <<endl;
   cout <<"Type Y or N: "; cin >> choices;
   
   while(choices != "Y"){
    if(choices == "N"){
       cout <<"\nIt's too late to turn back now." <<endl;
       cout <<"Type Y or N: "; cin >> choices;
     }
     else{
       cout <<"\nCapital Y or N." <<endl;
        cout <<"Type Y or N: "; cin >> choices;
     }
   }

   bJack.Know_howPlay();
   
  //Player at index 0 
  //Rat_King at index 1
   Endof_Match(bJack.Result());
 }

void TheEnd::Endof_Match(vector<int> results){
  //The score of Player at index 0 
  //The Score of Rat_King at index 1
  cout <<"\nEnter anything to continue >> "; cin >> choices;
   cout <<endl;
  
  if (results.at(0) > results.at(1)){
    cout <<"\nYou won the Blackjack game!" <<endl;

    cout <<"\nRat_King: Nice job kid. You beat me fair and square. Here is your ring." << endl;

    cout <<"\nWill: Alright we did it! Come on " << playerLabel << ", let's get the hell out of here." <<endl;

    cout <<"\nYou and Will walk away from the Rat_King and head out of the sewers." <<endl;

    cout <<"\nEnter anything to continue >> "; cin >> choices;
     cout <<endl;
    
  }
  else if (results.at(0) < results.at(1)){
    cout <<"\nYou lost the Blackjack game." <<endl;
    cout <<"\nRat_King: HA HA HA HA HA HA! I WIN!!! Now both of you have to work for me!" <<endl;
    cout <<"\nAs you and Will sunk in despair, you look at Will and silently nod" <<endl;
    cout <<"\n(whispers)Will: Do it " << playerLabel <<"." <<endl;
    
    cout <<"\nEnter anything to continue >> "; cin >> choices;
     cout <<endl;

    cout <<"\nYou pull out the gun you received from the Pest Control store and shoot the Rat_King." <<endl;
    
    cout <<"\nBANG! BANG!"<<endl;
    ASCII_Art2();
    cout <<"\nEnter anything to continue >> "; cin >> choices;
     cout <<endl;

    cout <<"\nRat_King: AHHH! WHAT THE F@*$*#!! YOU SHOT MY LEG!!!"<<endl;
    cout <<"\nWill: Grab the ring and head out of here " << playerLabel <<"!" <<endl;
    cout <<"\nYou and Will grabbed the ring and run out of the sewers."<<endl;

    cout <<"\nEnter anything to continue >> "; cin >> choices;
     cout <<endl;
  }
}

void TheEnd::ASCII_Art(){
  cout <<"\n";
  cout << " Z "<<endl;
  cout << "  Z           _  _          " << endl;
  cout << "   Z_ _      (=)(=)-._  _.-'^^'^^'^^'^^'^^'--." << endl;
  cout << "   (.(.)----'`        ^^'                /^   ^^-._" << endl;
  cout << "   (    `                 \\             |    _    ^^-._" << endl;
  cout << "    VvvvvvvVv~~`__,/.._>  /:/:/:/:/:/:/:/\\  (_..,______^^-." << endl;
  cout << "    `^^^^^^^^`/  /   /  /`^^^^^^^^^>^^>^`>  >        _`)  )" << endl;
  cout << "              (((`   (((`          (((`  (((`        `'--'^" << endl;
  cout <<"\n";
  /****************
  This art was made by:
  Joan G. Stark
  https://www.asciiart.eu/animals/reptiles/alligators
  Accessed: Dec. 2023
  (I added the Z's to make it look like it is sleeping)
  *********************/
  
}

void TheEnd::ASCII_Art2(){
  cout <<endl;
  cout << "                                             ("<<endl;
  cout << "                                             )"<<endl;
  cout << "  +--^----------,--------,-----,--------^--, (" << endl;
  cout << "  | |||||||||   `--------'     |           O )" << endl;
  cout << "  `+---------------------------^----------|" << endl;
  cout << "   `\\_,---------,---------,--------------'" << endl;
  cout << "     / XXXXXX /'|       /'" << endl;
  cout << "    / XXXXXX /  `\\    /'" << endl;
  cout << "   / XXXXXX /`-------'" << endl;
  cout << "  / XXXXXX /" << endl;
  cout << " / XXXXXX /" << endl;
  cout << "(________(" << endl;
  cout << " `------'  " << endl;
  cout <<endl;

  /*******************
  This art was made by:
  Steven Paul Adams
  https://www.asciiart.eu/weapons/guns
  Accessed: Dec. 2023
  (I added the () to make it look like it is shooting)
  ************************/
}