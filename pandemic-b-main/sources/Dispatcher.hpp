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

    class Dispatcher : public Player
    {
    public:
        inline Dispatcher(Board &b, City c) : Player(b, c, "Dispatcher") {}
        Player &fly_direct(City c) override;
    };

}