#include "Scientist.hpp"

using namespace std;

namespace pandemic
{
        Player &Scientist::discover_cure(Color col)
        {
                if (!board.isResearchStationIn(this->currCity))
                {
                        throw invalid_argument("City hasn`t research station");
                }

                int counter = 0;
                for (const auto &city : cards)
                {
                        if (ColorsOfCities.at(city) == col)
                        {
                                counter++;
                        }
                        if (counter == this->n)
                        {
                                break;
                        }
                }
                if (counter < this->n)
                {
                        throw invalid_argument("Illegal action - not enough cards");
                }
                int i = 0;

                for (auto it = cards.begin(); it != cards.end(); i++)
                {
                        if (i == FiveCards)
                        {
                                break;
                        }
                        if (ColorsOfCities.at(*it) == col)
                        {
                                it = cards.erase(it);
                        }
                        else
                        {
                                ++it;
                        }
                }

                board.foundCure(col);

                return *this;
        }

}