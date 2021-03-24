#include <iostream>
#include <stdexcept>
#include "Board.hpp"

using namespace std;
const int CHAR0 = 48;
const int CHAR_ = 95;


namespace ariel
{
        char table [MAXSIZE][MAXSIZE];
        unsigned int row;
        unsigned int col;

            void Board::initTable()
        {
            if (!INIT)
            {                          
                for (unsigned int i = 0; i < MAXSIZE; i++)
                {
                    this->table[0][i] = CHAR0;
                    this->table[i][0] = CHAR0;
                    // this->arr.at
                }
                for (unsigned int i = 1; i < MAXSIZE; i++)
                {
                    for (unsigned int j = 1; j < MAXSIZE; j++)
                    {
                        this->table[i][j] = CHAR_;
                    }
                }
            }
            this->INIT = true;
        }

    void Board::post(unsigned int row, unsigned int col, Direction a, string x)
    {
        initTable();

        for (unsigned int i = 0; i < x.length(); i++)
        {
            if (a == Direction::Horizontal)
            {
                this->table[row][col + i] = x[i];
            }
            else
            {
                this->table[row + i][col] = x[i];
            }
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction a, unsigned int len)
    {

        initTable();

        string ans;
        for (unsigned int i = 0; i < len; i++)
        {
            if (a == Direction::Horizontal)
            {
                ans += this->table[row][col + i];
            }
            else
            {
                ans += this->table[row + i][col];
            }
        }
        return ans;
    }

    void Board::show()
    {
        for (unsigned int i = 0; i < MAXSIZE; i++)
        {
            for (unsigned int j = 0; j < MAXSIZE; j++)
            {
                cout << this->table[i][j];
            }
            cout << endl;
        }
    }

}
