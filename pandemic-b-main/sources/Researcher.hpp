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

    class Researcher : public Player
    {
    public:
        inline Researcher(Board &b, City c) : Player(b, c, "Researcher") {}
        Player &discover_cure(Color col) override;
    };
}