#include "Player.hpp"

using namespace std;

namespace pandemic
{
    string Player::role() { return this->Role; }

    Player &Player::take_card(City c)
    {
        if (this->cards.count(c) == 0)
        {
            this->cards.insert(c);
        }
        return *this;
    }

    Player &Player::remove_cards(City c)
    {
        for (auto i : this->cards)
        {
            this->cards.erase(i);
        }
        return *this;
    }

    Player &Player::drive(City c)
    {
        if (this->currCity == c)
        {
            throw invalid_argument("you already in this city");
        }
        if (pandemic::connections.at(currCity).count(c) > 0)
        {
            this->currCity = c;
        }
        else
        {
            throw "Cities not connected!";
        }

        return *this;
    }
    Player &Player::fly_direct(City c)
    {
                if (this->currCity == c)
        {
            throw invalid_argument("you already in this city");
        }
        if (cards.count(c) > 0)
        {
            this->currCity = c;
            this->cards.erase(c);
        }
        else
        {
            throw invalid_argument("Illegal action11");
        }
        return *this;
    }
    Player &Player::fly_charter(City c)
    {
        if (this->currCity == c)
        {
            throw invalid_argument("you already in this city");
        }
        if (cards.count(this->currCity) > 0)
        {
            this->cards.erase(currCity);
            this->currCity = c;
        }
        else
        {
            throw invalid_argument("No city card");
        }

        return *this;
    }

    Player &Player::fly_shuttle(City c)
    {
        if (this->currCity == c)
        {
            throw invalid_argument("you already in this city");
        }
        if (this->board.isResearchStationIn(this->currCity) && this->board.isResearchStationIn(c))
        {
            this->currCity = c;
        }
        else
        {
            throw invalid_argument("There is not a research station in your current city or in the destination");
        }
        return *this;
    }
    Player &Player::build()
    {
        if (this->Role == "OperationsExpert")
        {
            this->board.buildResStation(this->currCity);
        }
        else if (this->cards.count(currCity) > 0)
        {
            this->board.buildResStation(this->currCity);
            this->cards.erase(currCity);
        }
        else
        {
            throw invalid_argument("not enough cards");
        }
        return *this;
    }
    Player &Player::discover_cure(Color col)
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
    Player &Player::treat(City c)
    {

        if (this->board[c] == 0)
        {
            throw invalid_argument("Cannot treat a clean city");
        }
        if (this->currCity != c)
        {
            throw invalid_argument("Can treat only your current city");
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