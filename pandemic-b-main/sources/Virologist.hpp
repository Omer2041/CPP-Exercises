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
    public:
        inline Virologist(Board &b, City c) : Player(b, c, "Virologist") {}
        Player &treat(City c) override;
    };
}