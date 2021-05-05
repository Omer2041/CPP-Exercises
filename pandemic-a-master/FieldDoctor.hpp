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

    class FieldDoctor : public Player
    {
        City C;
        Board B;
    public:
        FieldDoctor(Board b, City c) : Player(), C(c), B(b)    {
            this->C = City::Madrid;
        }
        FieldDoctor() : Player(), C(City::Atlanta) {

        };



        string role();
        FieldDoctor &take_card(pandemic::City c);

        FieldDoctor &drive(City c);
        FieldDoctor &fly_direct(City c);
        FieldDoctor &fly_charter(City c);
        FieldDoctor &fly_shuttle(City c);
        FieldDoctor &build();
        FieldDoctor &discover_cure(Color col);
        FieldDoctor &treat(City c);

    };
}