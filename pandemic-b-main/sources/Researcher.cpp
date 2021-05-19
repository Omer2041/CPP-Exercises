#include "Researcher.hpp"

using namespace std;

namespace pandemic
{

    Player &Researcher::discover_cure(Color col)
    {
        int counter = 0;
        for (const auto &city : cards)
        {
            if (ColorsOfCities.at(city) == col)
            {
                counter++;
            }
            if (counter == FiveCards)
            {
                break;
            }
        }
        if (counter < FiveCards)
        {
            throw invalid_argument("Illegal action - not enough cards");
        }
        int i = 0;

        for (auto iter = cards.begin(); iter != cards.end(); i++)
        {
            if (ColorsOfCities.at(*iter) == col)
            {
                iter = cards.erase(iter);
            }
            else
            {
                ++iter;
            }
        }

        board.foundCure(col);

        return *this;
    }

}