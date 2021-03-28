
#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;
const int MAXSIZE = 500;
const int CHAR0 = 48;
const int CHAR_ = 95;
const int INT_MAX = 2147483647;

namespace ariel
{
    class Board
    {

        map <unsigned int, map<unsigned int, char>> board;
        unsigned int rowMax, colMax, rowMin, colMin;

    public:
        Board()
        {
            this->rowMax = 0;
            this->colMax = 0;
            this->rowMin = INT_MAX;
            this->colMin = INT_MAX;
        }

        void post(unsigned int row, unsigned int col, Direction a, string x);
        string read(unsigned int row, unsigned int col, Direction a, unsigned int len);
        void show();
    };
}