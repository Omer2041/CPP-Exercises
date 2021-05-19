#include "Medic.hpp"

using namespace std;

namespace pandemic
{

    Player &Medic::drive(City c)
    {
        if (this->board.isCureDiscoveredIn(c))
        {
            this->board[c] = 0;
        }
        return Player::drive(c);
    }
    Player &Medic::fly_direct(City c)
    {
        if (this->board.isCureDiscoveredIn(c))
        {
            this->board[c] = 0;
        }
        return Player::fly_direct(c);
    }
    Player &Medic::fly_charter(City c)
    {
        if (this->board.isCureDiscoveredIn(c))
        {
            this->board[c] = 0;
        }
        return Player::fly_charter(c);
    }

    Player &Medic::fly_shuttle(City c)
    {
        if (this->board.isCureDiscoveredIn(c))
        {
            this->board[c] = 0;
        }
        return Player::fly_shuttle(c);
    }
    Player &Medic::treat(City c)
    {
        if (this->board[this->currCity] == 0)
        {
            throw "cannot treat a clean city";
        }
        this->board[this->currCity] = 0;

        return *this;
    }
}