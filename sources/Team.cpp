#include "Team.hpp"
using namespace std;

// Constructor

Team::Team(string name, double talent)
{

    this->name = std::move(name);
    this->talent = talent;
}

// Getters

double Team::getTalent() const
{
    return talent;
}

string Team::getName() const
{
    return name;
}
void Team::print()
{
    std::cout << "Talent: " << getTalent() << " | name: " << getName() << std::endl;
}
