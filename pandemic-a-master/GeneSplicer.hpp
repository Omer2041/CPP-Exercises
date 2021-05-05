#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"


using namespace std;

namespace pandemic
{

    class GeneSplicer : public Player
    {
        City C;
        Board B;
    public:
        GeneSplicer(Board b, City c) : Player(), C(c), B(b)    {
            this->C = City::Madrid;
        }
        GeneSplicer() : Player(), C(City::Atlanta) {

        };



        string role();
        GeneSplicer &take_card(pandemic::City c);

        GeneSplicer &drive(City c);
        GeneSplicer &fly_direct(City c);
        GeneSplicer &fly_charter(City c);
        GeneSplicer &fly_shuttle(City c);
        GeneSplicer &build();
        GeneSplicer &discover_cure(Color col);
        GeneSplicer &treat(City c);

    };
}