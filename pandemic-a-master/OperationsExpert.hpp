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

    class OperationsExpert : public Player
    {
        City C;
        Board B;
    public:
        OperationsExpert(Board b, City c) : Player(), C(c), B(b)    {
            this->C = City::Madrid;
        }
        OperationsExpert() : Player(), C(City::Atlanta) {

        };



        string role();
        OperationsExpert &take_card(pandemic::City c);

        OperationsExpert &drive(City c);
        OperationsExpert &fly_direct(City c);
        OperationsExpert &fly_charter(City c);
        OperationsExpert &fly_shuttle(City c);
        OperationsExpert &build();
        OperationsExpert &discover_cure(Color col);
        OperationsExpert &treat(City c);

    };
}