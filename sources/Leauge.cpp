
#include "Leauge.hpp"
#include "Team.hpp"
#include "Game.hpp"
#include <string>

using namespace std;

const int Rang_teams = 20;

/**
 * Empty constructor:
 * Create 20 random teams.
 */
Leauge::Leauge()
{
    if (vec_teams.size() > Rang_teams)
    {
        throw invalid_argument("No more than 20 Teams");
    }

    for (size_t i = 0; i <= Rang_teams; ++i)
    {
        double rand_num = (rand() % (25 - 0 + 1) + 0) / RAND_MAX;
        Team *randomTeam = new Team(to_string(i), rand_num);
        vec_teams.push_back(randomTeam);
    }
}

//  Constructor gets vector of teams.

Leauge::Leauge(vector<Team *> teamVec)
{
    // Constructor get less than 20 teams-create random teams to fill Vector up
    if (vec_teams.size() < Rang_teams)
    {
        for (size_t i = teamVec.size(); i <= Rang_teams; ++i)
        {
            double rand_num = (rand() % (25 - 0 + 1) + 0) / RAND_MAX;
            Team *randomTeam = new Team(to_string(i), rand_num);
            teamVec.push_back(randomTeam);
        }
    }
    for (size_t i = 0; i < Rang_teams; ++i)
    {
        vec_teams.push_back(teamVec[i]);
    }
}
Leauge::~Leauge()
{
    for (size_t i = 0; i <= vec_teams.size(); ++i)
    {
        delete vec_teams[i];
    }
}
vector<Team *> Leauge::getTeams() const
{
    return this->vec_teams;
}
Schedule Leauge::getSchedule() const
{
    return this->schedule;
}

void Leauge::print()
{
    for (size_t i = 0; i < vec_teams.size(); ++i)
    {
        cout << vec_teams[i]->getName() << " " << vec_teams[i]->getTalent() << '\n';
    }
}
