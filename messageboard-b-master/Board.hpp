
#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;
const int CHAR0 = 48;
const int CHAR_ = 95;
const int MAX_INT = 2147483647;

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
            this->rowMin = MAX_INT;
            this->colMin = MAX_INT;
        }

        void post(unsigned int row, unsigned int col, Direction a, string x);
        string read(unsigned int row, unsigned int col, Direction a, unsigned int len);
        void show();
    };
}