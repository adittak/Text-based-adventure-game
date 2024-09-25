#ifndef MAP_H
#define MAP_H

#include "TheEnd.h"
#include <string>
using namespace std;

class Map {
  public:
    void Location1();
    void Location2();
    void Location3();
    void Location4();
    void Location5();
    void LocationA();
    void LocationB();
    void Apartment(string name);
    void HighSchool();
    void DiscountStore();
    void Hospital();
    void PestControlStore();
    void ParkPlace();

  private:
    string playerChoice;
    TheEnd last;
};

#endif