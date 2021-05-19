#include "Board.hpp"
#include <map>
using namespace pandemic;

using namespace std;

namespace pandemic
{

    int &Board::operator[](City c)
    {
        return this->deseaseLevel[c];
    }

    bool Board::is_clean()
    {
        for (const auto &i : deseaseLevel)
        {
            if (i.second > 0)
            {
                return false;
            }
        }
        return true;
    }
    void Board::foundCure(Color col)
    {
        this->cureDiscoverd.insert(col);
    }
    void Board::buildResStation(City c)
    {
        this->researchStations.insert(c);
    }
    bool Board::isResearchStationIn(City c)
    {
        return this->researchStations.count(c) > 0;
    }
    bool Board::isCureDiscoveredIn(City c)
    {
        return this->cureDiscoverd.count(ColorsOfCities.at(c)) > 0;
    }

    void Board::remove_cures()
    {
        this->cureDiscoverd.clear();

    }
    void Board::remove_stations()
    {
        for (const auto &i : this->researchStations)
        {
            researchStations.erase(i);
        }
    }

    ostream &operator<<(std::ostream &out, const Board &b)
    {
        return out;
    }

}
