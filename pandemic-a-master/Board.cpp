#include "Board.hpp"
#include <map>
using namespace pandemic;

using namespace std;

namespace pandemic
{

    bool Board::is_clean()
    {
        return true;
    }
    const int Board::operator[](size_t index) const
    {
        // if (c >= CityNum)
        //     throw out_of_range("Array index out of bounds: " + to_string(index));
        return 1;
    }

    int &Board::operator[](size_t index)
    {
        // this->cubes[x] = x;
        // if (c >= CityNum)
        //     throw out_of_range("Array index out of bounds: " + to_string(x));
        Board b;
        return arr;
    }
    ostream &operator<<(std::ostream &out, const Board &b)
    {
        return out;
    }

}
