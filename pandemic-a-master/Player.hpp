#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic
{
    class Player
    {
        Board board;
        City city;

    public:
        Player(Board b, City c) : city(c), board(b)
        {
            this->city = City::LosAngeles;
        }

        Player() : city(City::London) {}
        // Player() {}

        // ~Player();

        string role();
        Player &take_card(pandemic::City c);

        Player &drive(City c);
        Player &fly_direct(City c);
        Player &fly_charter(City c);
        Player &fly_shuttle(City c);
        Player &build();
        Player &discover_cure(Color col);
        Player &treat(City c);
    };
}