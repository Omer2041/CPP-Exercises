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

    public:
        inline FieldDoctor(Board &b, City c) : Player(b, c, "FieldDoctor") {}
        Player &treat(City c) override;
    };
}