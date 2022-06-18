
#include "Round.hpp"
#include <vector>
using namespace std;

Round::Round()
{
}
Round::Round(vector<Game *> newGames)
{
    for (size_t i = 0; i < newGames.size(); ++i)
    {
        this->games.push_back(newGames[i]);
    }
}
void Round::addGame(Game *game)
{
    this->games.push_back(game);
}

vector<Game *> Round::getGames() const
{
    return this->games;
}
void Round::printRound()
{
    for (size_t i = 0; i < games.size(); ++i)
    {
        cout << "\n \n";

        cout << "Team " << games[i]->getTeam_h()->getName() << "Talent=" << games[i]->getTeam_h()->getTalent() << " vs Team " << games[i]->getTeam_a()->getName() << "Talent=" << games[i]->getTeam_a()->getTalent() << " =The winner is team " << games[i]->getWinner()->getName() << '\n';
    }
}
