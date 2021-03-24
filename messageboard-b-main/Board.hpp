
#include <string>
#include "Direction.hpp"
using namespace std;
const int MAXSIZE = 400;

namespace ariel
{
    class Board
    {
        char table [MAXSIZE][MAXSIZE];
        bool INIT = false;
        unsigned int row;
        unsigned int col;

    public:
        void initTable();
        void post(unsigned int row, unsigned int col, Direction a, string x);
        string read(unsigned int row, unsigned int col, Direction a, unsigned int len);
        void show();

    };
}