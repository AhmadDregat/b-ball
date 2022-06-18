#include "doctest.h"
#include <vector>
#include <stdexcept>
#include <string>
#include <time.h>

#include "Game.hpp"
#include "Leauge.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
//#include "Game.cpp"
const int NUM_T = 20;
const int SOM_T = 10;
using namespace std;

TEST_CASE("Good Tests")
{
    srand((unsigned)time(NULL)); // Random Number Between 0 And 1

    CHECK_NOTHROW(Leauge lg = Leauge()); // creates a leauge without giving teams
    Leauge lg = Leauge();
    CHECK_EQ(NUM_T, lg.getTeams().size()); // Checks there are 20 teams in the leauge
    vector<Team *> teams = lg.getTeams();

    for (size_t i = 0; i < NUM_T; i++) // Checks teams level is  0<lvl<1
    {
        CHECK(0 < teams.at(0)->getTalent());
        CHECK(teams.at(0)->getTalent() < 1);
    }

    // Now lets try and create vector with less then 20 teams and create a new leauge !
    vector<Team *> vec_t;
    for (size_t i = 0; i < SOM_T; i++)
    {
        string nm = std::to_string(i);
        vec_t.push_back(new Team(nm, 0.5));
    }

    CHECK_EQ(10, vec_t.size()); // Now we have a vector with 10 teams
    Leauge lg1 = Leauge(vec_t);
    CHECK_EQ(NUM_T, lg1.getTeams().size()); // Checks there are 20 teams in the leauge

    vector<Team *> teams1 = lg1.getTeams();
    // Lets run again the tests we did on the first leauge to check the leauge is valid!
    for (size_t i = 0; i < NUM_T; i++) // Checks teams level is  0<lvl<1
    {
        CHECK(0 < teams1.at(0)->getTalent());
        CHECK(teams1.at(0)->getTalent() < 1);
    }

    // now lets add to our vector 10 more teams and try to create the leauge with vector filled by 20 teams!
    for (size_t i = 10; i < NUM_T; i++)
    {
        string nm = std::to_string(i);
        vec_t.push_back(new Team(nm, 0.5));
    }

    CHECK_EQ(NUM_T, vec_t.size()); // Check that we have vector with 20 teams!
    Leauge lg2 = Leauge(vec_t);
    CHECK_EQ(NUM_T, lg2.getTeams().size()); // Checks there are 20 teams in the leauge

    vector<Team *> teams2 = lg2.getTeams();
    // Lets run again the tests we did on the first leauge to check the leauge is valid!
    for (size_t i = 0; i < NUM_T; i++) // Checks teams level is  0<lvl<1
    {
        CHECK(0 < teams2.at(0)->getTalent());
        CHECK(teams2.at(0)->getTalent() < 1);
    }

    // lets run the leauge games and check that its going
    CHECK_NOTHROW(Schedule(lg.getTeams()));
    Schedule s = Schedule(lg.getTeams());

    // Lets try a game with two teams
    Team Hapoel = Team("Hapoel", 0.5);
    Team Maccabi = Team("Maccabi", 0.3);
    Game g = Game(&Hapoel, &Maccabi);
    CHECK_NOTHROW(g.getWinner());
}
TEST_CASE("Bad Tests")
{
    // lets try and create a leauge with more then 20 teams
    vector<Team *> vec_t;
    for (size_t i = 0; i < NUM_T + 1; i++)
    {
        string nm = std::to_string(i);
        vec_t.push_back(new Team(nm, 0.5));
    }
    CHECK_THROWS(Leauge L = Leauge(vec_t));

    CHECK_THROWS({"Maccabi Tel Aviv", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Tel Aviv", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Jerusalem", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Holon", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Maccabi Haifa", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Galil Elyon", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Maccabi Rishon LeZion", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Gilboa Galil", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Ramat Gan", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Ironi Ramat Gan", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Gvat", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Haifa", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Hapoel Eilat", (float)rand() / RAND_MAX});
    CHECK_THROWS({"Bnei Herzliya", (float)rand() / RAND_MAX});

    // Lets try to do a game with two teams with the same name

    Team Hapoel = Team("Hapoel", 0.5);
    Team Maccabi = Team("Maccabi", 0.3);
    CHECK_THROWS(Game g = Game(&Hapoel, &Maccabi));
}
