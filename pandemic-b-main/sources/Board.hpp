#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "City.hpp"
#include "Color.hpp"

using namespace std;
const int CityNum = 48;

namespace pandemic
{

    class Board
    {
    protected:
        map<City, int> deseaseLevel;
        set<City> researchStations;
        set<Color> cureDiscoverd;

    public:
        Board() {}

        // inline Board() : deseaseLevel()
        // {
        // }

        bool is_clean();
        bool isResearchStationIn(City c);
        bool isCureDiscoveredIn(City c);
        void foundCure(Color c);
        void buildResStation(City c);
        void remove_cures();
        void remove_stations();
        int &operator[](City c);

        friend ostream &operator<<(std::ostream &out, const Board &b);
    };
}