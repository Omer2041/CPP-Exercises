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
    public:
        inline GeneSplicer(Board &b, City c) : Player(b, c, "GeneSplicer") {}
        Player &discover_cure(Color col) override;
    };

}