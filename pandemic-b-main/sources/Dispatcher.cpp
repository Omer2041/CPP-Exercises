#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Player &Dispatcher::fly_direct(City c)
    {

        if (this->currCity != c)
        {
            if (this->board.isResearchStationIn(this->currCity))
            {
                this->currCity = c;
            }
            else
            {
                return Player::fly_direct(c);
            }
            return *this;
        }
        throw std::invalid_argument{"you already in this city "};
    }
}