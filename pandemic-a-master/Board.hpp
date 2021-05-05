#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "City.hpp"

using namespace std;
const int CityNum = 48;

namespace pandemic
{

    class Board
    {
        int arr;

    public:
        Board() : arr()
        {
        }
        // ~Board() { delete arr; }

        bool is_clean();

        const int operator[](size_t index) const;
        int &operator[](size_t index);

        // const int operator[](uint index) const;
        // int &operator[](uint index);
        int operator[](City c) const
        {
            return 1;
        }

        int &operator[](City c)
        {

            return arr;
        }

        friend ostream &operator<<(std::ostream &out, const Board &b);
    };
}