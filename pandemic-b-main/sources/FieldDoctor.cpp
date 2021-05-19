#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    Player &FieldDoctor::treat(City c)
    {
        if (this->board[c] == 0)
        {
            throw invalid_argument("Cannot treat a clean city");
        }
        if (pandemic::connections.at(currCity).count(c) > 0 || c == currCity)
        {
            this->board[c] -= 1;
            if (this->board.isCureDiscoveredIn(c))
            {
                this->board[c] = 0;
            }
        }
        else
        {
            throw invalid_argument("Cannot treat non-neighbor city");
        }
        return *this;
    }
}