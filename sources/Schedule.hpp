
#pragma once

#include <vector>
#include <string.h>
#include "Round.hpp"

class Round;
class Schedule
{
    std::vector<Round *> rounds;

public:
    //-----Constructors-----
    Schedule();                                 // default Constructor
    Schedule(const std::vector<Team *> &teams); // Constructor
    ~Schedule();

    void print();
};
