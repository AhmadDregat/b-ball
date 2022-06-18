
#include <iostream>
#include <random>
#include "Game.hpp"

using namespace std;

const int min_Homescore = 55; // min score home team
const int min_Awayscore = 50; // min score away team
const int max_Points = 100;   // max score
const int bonus = 10;

/**
 * Constructor for the Game.
 * get 2 Team pointers and generate random score.
 *Then add point to each Team base on their talent to
 * @param A
 * @param B
 */
Game::Game(Team *home, Team *away)
{
    this->home = home;
    this->away = away;
    score_home = (rand() % (max_Points - min_Homescore + 1) + min_Homescore) + bonus;
    score_away = (rand() % (max_Points - min_Awayscore + 1) + min_Awayscore) + bonus;
}

Team *Game::getTeam_h() const
{
    return home;
}

Team *Game::getTeam_a() const
{
    return away;
}

int Game::gethome_p() const
{
    return score_home;
}

int Game::getaway_p() const
{
    return score_away;
}

Team *Game::getWinner() const
{

    if (this->score_home > this->score_away)
    {
        return home;
    }

    else if (this->score_home < this->score_away)
    {
        return away;
    }

    else
    {
        if (this->home->getTalent() >= this->away->getTalent())
        {
            return home;
        }

        else
        {
            return away;
        }
    }
}
