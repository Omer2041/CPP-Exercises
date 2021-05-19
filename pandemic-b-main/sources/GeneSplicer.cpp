#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{
    Player &GeneSplicer::discover_cure(Color col)
    {
        if (!board.isResearchStationIn(this->currCity))
        {
            throw invalid_argument("City hasn`t research station");
        }
        int counter = 0;
        for (const auto &city : cards)
        {
            counter++;
            if (counter == FiveCards)
            {
                break;
            }
        }
        if (counter < FiveCards){
            throw invalid_argument("Illegal action - not enough cards");
        }
        int i = 0;

        for (auto it = cards.begin(); it != cards.end(); i++)
        {

            it = cards.erase(it);
            ++it;
        }

        board.foundCure(col);

        return *this;
    }

}