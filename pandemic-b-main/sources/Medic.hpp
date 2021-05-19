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

    class Medic : public Player
    {
    public:
        inline Medic(Board &b, City c) : Player(b, c, "Medic")  {}
        Player &treat(City c) override;
        Player &drive(City c) override;
        Player &fly_direct(City c) override;
        Player &fly_charter(City c) override;
        Player &fly_shuttle(City c) override;

    };
}