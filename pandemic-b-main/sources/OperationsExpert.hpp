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
    public:
        inline OperationsExpert(Board &b, City c) : Player(b, c, "OperationsExpert") {} 

        // Player &build();
    };
}