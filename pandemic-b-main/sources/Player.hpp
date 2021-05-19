#pragma once

#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic
{
    const int FiveCards = 5;
    class Player
    {
    protected:
        string Role;
        Board &board;
        City currCity;
        set<City> cards;

    public:
        inline Player(Board &b, City c, string pr = "Player") : currCity(c), board(b), Role(pr) {}

        string role();
        Player &take_card(City c);
        Player &remove_cards(City c);

        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        Player &build();
        virtual Player &discover_cure(Color col);
        virtual Player &treat(City c);
    };
}