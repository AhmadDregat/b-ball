
#pragma once

#include "Game.hpp"
#include <vector>
#include <string.h>

class Round
{
    std::vector<Game *> games;

public:
    //-----Constructor-----
    Round();                              // default Constructor
    Round(std::vector<Game *>);           // Constructor
// --------------------Functions-----------------
    std::vector<Game *> getGames() const; // get all the games
    void addGame(Game *);                 // add a new game
    void printRound();
};
