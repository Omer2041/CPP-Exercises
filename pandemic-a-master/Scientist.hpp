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

    class Scientist : public Player
    {
        City C;
        Board B;
    public:
        Scientist(Board b, City c, int x) : Player(), C(c), B(b)    {
            this->C = City::Madrid;
        }
        Scientist() : Player(), C(City::Atlanta) {

        };



        string role();
        Scientist &take_card(pandemic::City c);

        Scientist &drive(City c);
        Scientist &fly_direct(City c);
        Scientist &fly_charter(City c);
        Scientist &fly_shuttle(City c);
        Scientist &build();
        Scientist &discover_cure(Color col);
        Scientist &treat(City c);

    };
}