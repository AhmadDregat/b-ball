#pragma once

#include "Team.hpp"

class Game
{
    Team *home;     // home team
    Team *away;     // away team
    int score_home; // home points
    int score_away; // away points
public:
    Game(Team *home, Team *away); //  constuctor
    //-----Getters-----
    Team *getTeam_h() const;
    Team *getTeam_a() const;
    int gethome_p() const;
    int getaway_p() const;
    Team *getWinner() const; // get the team winner
};
