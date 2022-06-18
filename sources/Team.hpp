
#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Team
{
    string name;   // name of the team
    double talent; // level of the team (0-1)
public:
    //-----Constructors-----
    Team(string name, double talent);
    string getName() const;   // get the name of the team
    double getTalent() const; // get the talent of the team
    void print();
};
