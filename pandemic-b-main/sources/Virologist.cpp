#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Player &Virologist::treat(City c)
    {

        if (this->board[c] == 0)
        {
            throw invalid_argument("Cannot treat a clean city");
        }
        if (this->cards.count(c) == 0 && this->currCity != c)
        {
            throw invalid_argument("There is no compatible card");
        }
        if (this->board.isCureDiscoveredIn(c))
        {
            this->board[c] = 0;
        }
        else
        {
            board[c] -= 1;
        }
        return *this;
    }

}