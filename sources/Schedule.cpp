
#include "Schedule.hpp"

using namespace std;
int Rang_teams = 20;

Schedule::Schedule()
{
}
Schedule::Schedule(const vector<Team *> &teams)
{
    vector<vector<Team *>> table(2, vector<Team *>(10));

    if (teams.size() > Rang_teams)
    {
        throw invalid_argument("No more than 20 Teams");
    }

    for (size_t i = 0; i < 2; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            table[i][j] = teams[i * 10 + j];
        }
    }

    for (size_t i = 0; i < Rang_teams - 1; ++i)
    {
        Round *round = new Round();
        for (size_t j = 0; j < 10; ++j)
        {
            Game *new_game = new Game(table[0][j], table[1][j]);
            round->addGame(new_game);
        }
        rounds.push_back(round);

        Team *eleven = table[1][0];
        table[1][9] = table[0][9];

        for (size_t j = 0; j < 9; ++j)
        {
            table[1][j] = table[1][j + 1];
        }
        for (size_t j = 9; j > 0; --j)
        {
            table[0][j] = table[0][j - 1];
        }
        table[0][1] = eleven;
    }
}
Schedule::~Schedule()
{
    for (size_t i = 0; i < rounds.size(); ++i)
    {
        for (size_t j = 0; j < rounds[i]->getGames().size(); ++j)
        {
            delete rounds[i]->getGames()[j];
        }
        delete rounds[i];
    }
}

void Schedule::print()
{
    for (size_t i = 0; i < rounds.size(); ++i)
    {
        cout << "Round number: " << i + 1 << '\n';
        cout << "\n \n";
        this->rounds[i]->printRound();
        cout << "\n \n";
    }
}
