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

    class Virologist : public Player
    {
        City C;
        Board B;
    public:
        Virologist(Board b, City c) : Player(), C(c), B(b)    {
            this->C = City::Madrid;
        }
        Virologist() : Player(), C(City::Atlanta) {

        };



        string role();
        Virologist &take_card(pandemic::City c);

        Virologist &drive(City c);
        Virologist &fly_direct(City c);
        Virologist &fly_charter(City c);
        Virologist &fly_shuttle(City c);
        Virologist &build();
        Virologist &discover_cure(Color col);
        Virologist &treat(City c);

    };
}