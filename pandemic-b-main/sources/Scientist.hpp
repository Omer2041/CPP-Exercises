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
        int n;

    public:
        inline Scientist(Board &b, City c, int nx) : n(nx), Player(b, c, "Scientist") {}
        Player &discover_cure(Color col) override;

    };
}