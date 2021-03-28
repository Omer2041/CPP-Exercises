#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "Board.hpp"
#include "Direction.hpp"

using namespace std;

namespace ariel
{

    void Board::post(unsigned int row, unsigned int col, Direction a, string x)
    {
        for (size_t i = 0; i < x.length(); i++)
        {
            if (a == Direction::Horizontal)
            {
                this->board[row][col + i] = x[i];
                this->rowMax = (unsigned int)max((row), (this->rowMax));
                this->colMax = (unsigned int)max((int)(col + x.length()), (int)(this->colMax));
            }
            else
            {
                this->board[row + i][col] = x[i];
                this->rowMax = (unsigned int)max((int)(row + x.length()), (int)(this->rowMax));
                this->colMax = (unsigned int)max((int)(col), (int)(this->colMax));
            }
        }
        this->rowMin = (unsigned int)min(row, this->rowMin);
        this->colMin = (unsigned int)min(col, this->colMin);
    }

    string Board::read(unsigned int row, unsigned int col, Direction a, unsigned int len)
    {

        string ans;
        for (unsigned int i = 0; i < len; i++)
        {
            if (a == Direction::Horizontal)
            {
                if (this->board[row][col + i] != 0)
                {
                    ans += this->board[row][col + i];
                }
                else
                {
                    ans += (char)CHAR_;
                }
            }
            else
            {
                if (this->board[row + i][col] != 0)
                {
                    ans += this->board[row + i][col];
                }
                else
                {
                    ans += (char)CHAR_;
                }
            }
        }
        return ans;
    }

    void Board::show()
    {

        for (unsigned int i = rowMin; i < rowMax; i++)
        {
            cout << i;
            cout << ":";
            for (unsigned int j = colMin; j < colMax; j++)
            {
                if (this->board[i][j] != 0)
                {
                    cout << this->board[i][j];
                }
                else
                {
                    cout << (char)CHAR_;
                }
            }
            cout << endl;
        }
    }

}



