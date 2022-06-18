
    #pragma once

    #include <vector>
    #include <string.h>

    #include "Schedule.hpp"

    /**
     * The league class represent a league of 20 teams.
     */

    class Leauge
    {
        std::vector<Team *> vec_teams; // vector of teams
        Schedule schedule;

    public:
        Leauge();                             // default Constructor
        Leauge(std::vector<Team *>);          // Constructors
        ~Leauge();                            // distructor
        std::vector<Team *> getTeams() const; // get the teams
        Schedule getSchedule() const;         // get the schedule
        void print();
    };
