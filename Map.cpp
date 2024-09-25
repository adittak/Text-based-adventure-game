#include <iostream>
#include <string>
#include <unistd.h>
#include "Map.h"
using namespace std;

// global variables
bool legBroken = false;
bool discountststoreCheck = false;
bool pestCtrlStoreCheck = false;
bool hasGun = false;
int coupon;
string playerTag;

void Map::Apartment(string name) {
  bool goodchoice = false;
  playerTag = name;
  // Starting the game
  string choice;
  cout << "\nYou are in an apartment located on the third floor. Your friend, Will, is with you. You droped your mother's ring and a rat stole it. Your goal is to find and retrieve the ring before your mother comes home.\n" << endl;
  cout << "Now you've to go to outside to get the rat. Do you wanna use the stairs ('stairs')? Or jump out of the window ('jump')?" << endl;
  cout << ">> "; cin >> choice;

  while (!goodchoice) {
    if (choice == "jump") {
      goodchoice = true;
      cout << "\nWill: Are you crazy! You could've got yourself killed " << name << "! \n\n";
      cout << "You jumped out the window. Now your leg is broken" << endl;
      legBroken = true;
      Location1();
    } 
    else if (choice == "stairs") {
      goodchoice = true;
      cout << "\nYou chose the stairs, pass through your lobby, and now your outside" << endl;
      Location1();
    } 
    else {
      cout << "Invalid input! Try again." << endl;
      goodchoice = false;
      cout << ">> ";
      cin >> choice;
    }
  }
}

void Map::Location1(){
  
  cout <<"\nYou are now in 173rd St., outside of the bulding. Do you want to go back to your apratment (A) or to Amstradam Ave. (B)?" << endl;
  cout << "Enter A or B: "; cin >> playerChoice;
  bool goodChoice = false;
  
  while (!goodChoice){
    if(playerChoice == "A" || playerChoice == "B"){
      goodChoice = true;
    }
    else { 
      cout<< "Invalid choice. Please enter A or B: ";
      cin >> playerChoice;
      goodChoice = false;  
    }
  }

  if (playerChoice == "A"){
    Apartment(playerTag);
  }
  else if (playerChoice == "B"){
    Location2();
  }
  
}



void Map::Location2(){//173rd St. Amstradam Ave.
  cout <<"\nYou are now in 173rd St. Amstradam Ave. Do you want to go to 173rd St (A), College St.(B), or Park Place (C)?" << endl;
  cout << "Enter A, B, or C: "; cin >> playerChoice;
  
  while (true){
    if(playerChoice == "A" || playerChoice == "B" || playerChoice == "C"){
      break;
    }
    else { 
      cout<< "Invalid choice. Please enter A, B, or C: ";
      cin >> playerChoice;  
    }
  }

  if (playerChoice == "A"){
    Location1();
  }
  else if (playerChoice == "B"){
    Location3();
  }
  else if (playerChoice == "C"){
    ParkPlace();  
  }
  
}

void Map::ParkPlace(){
  cout<<"--------------------------";
  cout << "\nYou are now in Park Place." << endl;

  if (legBroken){//can't procced if leg is broken
    cout << "\nYou can't advance with that broken leg of yours. Come back later." << endl;
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;
    Location2();
  }
  else if (!pestCtrlStoreCheck){//have to vist the pest control store first
    cout << "\nYou enter Park Place and look around." << endl;
    cout << "\nWill: This park is nice. I like the renovations they did." << endl;
    cout << "\nYou and Will walk around to enjoy the scenery. There is nothing much to do so you head out of Park Place" << endl;
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;
    Location2();
  }
  else{
    cout << "\nYou enter Park Place and look around. With the map you got." <<endl; 
    cout <<"\nWill: Oh my God! This map is vague AF! This map is the map of the old Park Place. It's going to take a while to find this stupid entrance." << endl;
    cout<<"\nAfter an hour of searching you and Will found the seceret entrance to the sewage system. You enter the sewage and walked around for a bit." << endl;
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;
    //TheEnd class, this is the last stages of the game
      last.FinalLevel(playerTag);
  }
}

void Map::Location3(){//College St. 
  cout <<"\nYou are now in College St. Do you want to go to 170th St (A), The Discount store (B), or 173rd St. Amstradam Ave (C)" <<endl;
  cout << "Enter A, B, C: "; cin >> playerChoice;

  while (true){
    if(playerChoice == "A" || playerChoice == "B" || playerChoice == "C"){
      break;
    }
    else { 
      cout<< "Invalid choice. Please enter A, B, or C: ";
      cin >> playerChoice;  
    }
  }

  if (playerChoice == "A"){
    Location4();
  }
  else if (playerChoice == "B"){
    DiscountStore();
  }
  else if (playerChoice == "C"){
    Location2(); 
  }
  
}


//DiscountStore() is connected to Location3();
void Map::DiscountStore() {
  string response;
  cout<<"--------------------------";
  cout << "\nNow you are in a discount store." << endl;
  if (legBroken) { 
    cout << "\nYou have the chance to win a coupon by spinning the wheel. So that it could be used towards to your medical expenses." << endl;
    cout << "Do you wanna spin the wheel? (type 'spin')" << endl;
    cout << ">> ";
    cin >> response;
    if (response == "spin") {
      discountststoreCheck = true;
      coupon = (rand() % 100) + 1; // generate random number from 1 to 100
      cout << "HOORY! You got a coupon of " << coupon << "% discount" << endl;
      Location3();
    }
    else{
      cout <<"Enter anything to continue >> "; cin >> playerChoice;
      cout <<endl;       
      Location3();
    }   
  }
  else if(!legBroken){
    cout <<"\nYou don't have any reason to come here. Come back if you break a leg or something." << endl; 
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;       
    Location3();
  }
}

void Map::Location4(){//170th St. Amstradam Ave.
  cout <<"\nYou are now in 170th St. Do you want to go to 168th St.(A), Nicholas Ave.(B), or College St. (C)." <<endl;
  cout << "Enter A, B, C: "; cin >> playerChoice;

  while (true){
    if(playerChoice == "A" || playerChoice == "B" || playerChoice == "C"){
      break;
    }
    else { 
      cout<< "Invalid choice. Please enter A, B, or C: ";
      cin >> playerChoice;  
    }
  }

  if (playerChoice == "A"){
    Location5();
  }
  else if (playerChoice == "B"){
    LocationA();
  }
  else if (playerChoice == "C"){
    Location3(); 
  }
  
}

void Map::Location5(){//168th St. between Amstradam Ave and Broadway Ave
  cout <<"\nYou are now in 168th St. Do you want to go to Broadway Ave.(A), enter your high school(B), or 170th St. Amstradam Ave (C).";
  cout << "Enter A, B, C: "; cin >> playerChoice;

  while (true){
    if(playerChoice == "A" || playerChoice == "B" || playerChoice == "C"){
      break;
    }
    else { 
      cout<< "Invalid choice. Please enter A, B, or C: ";
      cin >> playerChoice;  
    }
  }

  if (playerChoice == "A"){
    LocationB();
  }
  else if (playerChoice == "B"){
    HighSchool();
  }
  else if (playerChoice == "C"){
    Location4(); 
  }
  
}

//HighSchool() is connected to Location5() function
void Map::HighSchool(){
  cout<<"--------------------------";
  cout << "\nYou entered your high school. You are now walking to the cafeteria, and see your classmate Jeremy finishing a gambling macth with your other classmates. You decide to walk over to him and ask him what game he is playing." << endl;

  cout << "\nJeremy: Yo whats up " << playerTag << " and Will! How's everything?" << endl;
  cout <<"\nWill: Nothing much, we're just doing a rat hunt. What game you were playing?" << endl;
  cout << "\nJeremy: Well I was playing Blackjack, but I lost $5." << endl;
  cout << "\nWill: Damn that suck. You were unlucky." << endl;
  cout << "\nJeremy: I mean some of it have to deal with skill. But yeah. Hey do you guys know how to play Blackjack?" <<endl;
  cout << ">> Yes or No? (lower case) "; cin >> playerChoice; 
  cout << endl;
  usleep(1000000);
  
  if (playerChoice == "yes" || playerChoice == "Yes"){
    cout << "\nJeremy: Alright then I catch you guys later." << endl;
    cout <<"\nYou and your friend begin to walk out of the school." << endl;
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;
    Location5();
  }
  else if (playerChoice == "no" ||playerChoice == "No"){
    cout <<"\nJeremy: Blackjack can be played with 2 or more people. Each player, including the dealer, is dealt two cards initially. Players decide whether to 'hit' (take another card) or 'stand' (keep the current hand). Players can continue to hit as many times as they want, but if the total value of their hand exceeds 21, they bust and lose the game. If a player's hand is closer to 21 than the dealer's hand without busting, the player wins. If both the player and the dealer have the same hand value, it's a push (tie), and the player's bet is returned or go for another round." << endl;
    usleep(1000000);
    cout <<"\nWill: Wow, now that could be helpful for the future." << endl;
    cout << "\nJeremy: Yeah, because people could play tricks and scam you guys if you don't know ho to play."<<endl;
    cout << "\nWill: Alright we will head out now." <<endl;

    cout <<"\nYou and Will begin to walk out of the school." << endl;
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;
    Location5();
  }
  }

void Map::LocationA(){//170th St. Nicholas Ave.
  cout <<"\nYou are now in 170th St. Nicholas Ave. Do you want to go to the Pest Control store (A) or to Amstradam Ave. (B).";
  cout << "Enter A or B: "; cin >> playerChoice;

  while (true){
    if(playerChoice == "A" || playerChoice == "B"){
      break;
    }
    else { 
      cout<< "Invalid choice. Please enter A or B: ";
      cin >> playerChoice;  
    }
  }

  if (playerChoice == "A"){
    PestControlStore();
  }
  else if (playerChoice == "B"){
    Location4();
  }
}

void Map::LocationB(){//168th St. Broadway Ave
  cout <<"\nYou are now in 168th St. Broadway Ave. Do you want to enter the Hospital (A) or to 168th St. (B)." <<endl;
  cout << "Enter A or B: "; cin >> playerChoice;

  while (true){
    if(playerChoice == "A" || playerChoice == "B"){
      break;
    }
    else { 
      cout<< "\nInvalid choice. Please enter A or B: ";
      cin >> playerChoice;  
    }
  }

  if (playerChoice == "A"){
    Hospital();
  }
  else if (playerChoice == "B"){
    Location5();
  }
  
}

//Pest Store is connected to LocationA() function
void Map::PestControlStore(){
  cout<<"--------------------------";
  cout << "\nYou are now in the Pest Control Store." << endl;

  if (!pestCtrlStoreCheck){
    cout << "\nManeger: Welcome to the Pest Control Store. How can I help you?" << endl;
    cout << "\nWill: Yes we have a rat problem." << endl;
    cout << "\nManeger: What type of problem?" << endl;
    cout << "\nWill: Well one of " << playerTag <<"'s jewlery got stolen by a rat and we was wondering if you have any idea where it has gone." <<endl;
    cout << "\nManeger: A RAT?!?! Oh no. I'm sorry guys but that rat must've taken it to the Rat_King." << endl;
    cout << "\nWill: Why does it sound like it has happend before?" << endl;
    cout << "\nManeger: Thats because it has. I gotten calls of rats stealing jewlery or money from people and delivering it to the Rat_King." << endl;
    
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;
    
    cout << "\nWill: Why is the police not involed with this?" << endl;
    cout << "\nManeger: Thats because they don't see it as a traditional crime. The Rat_King is a legend around here, and the police don't take these incidents seriously. The police believe see it as a folklore." << endl;
    
    cout <<"\nWill: So, how do we get to this Rat_King and retrieve the jewelry?"<<endl;

    cout <<"\nManager: Well, the entrance to the Rat_King's lair is hidden in the old sewage system, and not many people know about it. However, I have a map that will lead you to the Rat_King's domain." <<endl;
    usleep(1000000);
    
    cout <<"Enter anything to continue >> "; cin >> playerChoice;
    cout <<endl;
    
    cout << "\nYou recived a map!" << endl;
    cout << "\nManager: You also need this aswell." << endl;
    cout << "\nWill: Whoa, a gun!?!?" <<endl;
    cout << "\nManager: Just in case." << endl;
    cout << "\nEnter anything to take the gun" << endl;
    cin >> playerChoice;
    
    hasGun = true;
    pestCtrlStoreCheck = true;
    
    cout << "\nManeger: good luck on your travel." << endl;
    LocationA();
  }
  else if(pestCtrlStoreCheck){
    cout << "\nManeger: Welcome back! Were you able to get your jewlery back from the Rat_King? ('yes' or 'no')" << endl;
    cout <<">> "; cin >> playerChoice;
    
    if (playerChoice == "yes"){
      cout << "\nManeger: Great! I hope that rodent learn his lesson. By the way where is that gun I gave you?" <<endl;
      cout << "\nYou walked out of the store akwardly with no response." << endl;
      cout <<"Enter anything to continue >> "; cin >> playerChoice;
      cout <<endl;
      LocationA();
    }
    else if (playerChoice == "no"){
      cout << "\nManeger: Well you better hurry or else the Rat_King will cash in that jewlery" << endl;
      cout << "\nYou walked out of the store with urgency" << endl;
      cout <<"Enter anything to continue >> "; cin >> playerChoice;
      cout <<endl;
      LocationA();
    }
  }
}

//Hospital is connected to LocationB() function
void Map::Hospital(){
  string response;
  string response2;
  cout<<"--------------------------";
  cout << "\nNow you are in a hospital." << endl;
  if(legBroken){
    cout << "\nDoctor: I see your leg is broken. Would you like to fix your leg? (type 'yes')" << endl;
    cout << ">> ";
    cin>> response;
    
    if(response == "yes"){
      cout << "\nDoctor: Great! Your leg is fixed now." << endl;
      cout << "And the bill would be $600." << endl;
      legBroken = false;

      if(coupon > 0){
        cout << "\nDoctor: You got a coupon of " << coupon << "% discount." << endl;
        cout << "Doctor: Would you like to use it towards your bill? (type 'yes')" << endl;
        cout << ">> "; cin>> response;

        if(response == "yes" || response == "Yes"){
          cout << "\nDoctor: Great! Your bill is now $" << 600 - (600*coupon/100) << ". You're all settled and remeber to stay safe." << endl;
          coupon = 0;
          cout << "\nYou walk out of the hospital." << endl;
          LocationB();
        }     
      }
   }
    
 }
  else{
    cout << "\nDoctor: Welcome to the hospital. It looks like you guys are in no need of medical assistant. Come back if you are injured or sick. Remember to stay healthy." << endl;
    usleep(500000);
    cout << "\nYou walk out of the hospital." << endl;
    LocationB();
  }
}




//example of map below here (Test it in a C++ compiler)
/* // Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

string choose; 
class Locations{
    public:
    void Place1();
    void Place2();
    
};

void Apartment(){
    Locations sal;
    cout << "choose a place!\n";
    cout << ">> ";
    cin >> choose;
    
    if (choose == "A's"){
        sal.Place1();
    }
    else if (choose == "B's"){
        sal.Place2();
    }
}

void Locations::Place1(){
    cout <<"\nYou are in place 1 function!" <<endl;
    cout <<"would you like to go to place 2? >> \n";
    cin >> choose;
    
    if (choose =="Yes" || choose =="yes"){
        Place2();
    }
}

void Locations::Place2(){
    cout <<"\nYou are in place 2 function!" <<endl;
    cout <<"Do u wnat to go to Place 1 or Apartment? >>";
    cin >> choose;
    cout <<endl;
    
    if (choose == "Place1"){
        Place1();
    }
    else if (choose == "Apartment"){
        Apartment();
    }
}

int main() {

    cout << "Hello world!" <<endl;
    Apartment();

    return 0;
}*/