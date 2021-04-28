#include "NumberWithUnits.hpp"
#include <map>
using namespace ariel;
using namespace std;

namespace ariel
{
    map<string, map<string, double>> NumberWithUnits::convUnit;

    NumberWithUnits::NumberWithUnits(const double &s, const string &un) : size(s), unit(un)
    {
        if (convUnit[un][un] != 0)
        {
            this->size = s;
            this->unit = un;
        }
        else
        {
            throw invalid_argument(un + " is illegal unit!");
        }
    }

    void NumberWithUnits::read_units(ifstream &unitfile)
    {
        string un1, un2, cmp;
        double n1 = 0;
        double n2 = 0;

        while (unitfile >> n1 >> un1 >> cmp >> n2 >> un2)
        {
            convUnit[un1][un1] = 1;
            convUnit[un2][un2] = 1;
            convUnit[un1][un2] = n2;
            convUnit[un2][un1] = 1 / n2;
            newConversion(un1, un2);
            newConversion(un2, un1);
        }

    }

    //convUnit[g][kg][1\1000]
    //convUnit[kg][ton][1\1000]
    //convUnit[g][ton][1\1000\1000]
    void NumberWithUnits::newConversion(const string &u1, const string &u2)
    {
        for (pair<string, double> element : NumberWithUnits::convUnit[u1])
        {
            NumberWithUnits::convUnit[u2][element.first] = NumberWithUnits::convUnit[u1][element.first] * NumberWithUnits::convUnit[u2][u1];
            NumberWithUnits::convUnit[element.first][u2] = 1 / NumberWithUnits::convUnit[u2][element.first];
        }
    }
    

    // Arithmetic operators: - + += -= ++ --
    NumberWithUnits operator-(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        if (NumberWithUnits::convUnit[n2.unit][n1.unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to subtract 2 strange units";
        }
        return NumberWithUnits{n1.size - (n2.size * NumberWithUnits::convUnit[n2.unit][n1.unit]), n1.unit};
    }
    NumberWithUnits operator+(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        if (NumberWithUnits::convUnit[n2.unit][n1.unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to add 2 strange units";
        }
        return NumberWithUnits{n1.size + (n2.size * NumberWithUnits::convUnit[n2.unit][n1.unit]), n1.unit};
    }
    NumberWithUnits operator-(const NumberWithUnits &n1)
    {
        return NumberWithUnits(-n1.size, n1.unit);
    }
    NumberWithUnits operator+(const NumberWithUnits &n1)
    {
        return NumberWithUnits(n1.size, n1.unit);
    }

    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &other)
    {
        if (convUnit[other.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to subtract 2 strange units";
        }
        size -= other.size * convUnit[other.unit][unit];
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &other)
    {
        if (convUnit[other.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to add 2 strange units";
        }
        size += other.size * convUnit[other.unit][unit];
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator--()
    {
        size--;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int flag)
    {
        double s = size;
        size--;
        return NumberWithUnits(s, unit);
    }
    NumberWithUnits &NumberWithUnits::operator++()
    {
        size++;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int flag)
    {
        double s = size;
        size++;
        return NumberWithUnits(s, unit);
    }




    // Mult operators: * *=
    NumberWithUnits operator*(const double x, const NumberWithUnits &n1)
    {
        return NumberWithUnits(x * n1.size, n1.unit);
    }

    NumberWithUnits operator*(const NumberWithUnits &n1, const double x)
    {
        return NumberWithUnits(x * n1.size, n1.unit);
    }

    NumberWithUnits &NumberWithUnits::operator*=(double x)
    {
        size *= x;
        return *this;
    }




    // Compare operators: == != < <= > >=
    bool NumberWithUnits::operator==(const NumberWithUnits &n) const
    {
        if (convUnit[n.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to compare 2 strange units";
        }
        return this->size >= (n.size * convUnit[n.unit][this->unit]) - EPS && this->size <= (n.size * convUnit[n.unit][this->unit]) + EPS;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &n) const
    {
        if (convUnit[n.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to compare 2 strange units";
        }
        return !(*this == n);
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &n) const
    {
        if (convUnit[n.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to compare 2 strange units";
        }
        return this->size < (n.size * convUnit[n.unit][this->unit]);
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &n) const
    {
        if (convUnit[n.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to compare 2 strange units";
        }
        return this->size < (n.size * convUnit[n.unit][this->unit]) || *this == n;
    }
    bool NumberWithUnits::operator>(const NumberWithUnits &n) const
    {
        if (convUnit[n.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to compare 2 strange units";
        }
        return this->size > (n.size * convUnit[n.unit][this->unit]);
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &n) const
    {
        if (convUnit[n.unit][unit] == INVALIDUNIT)
        {
            throw "Invalid Operation: trying to compare 2 strange units";
        }
        return this->size > (n.size * convUnit[n.unit][this->unit]) || *this == n;
    }



    // Stream operators: << >>
    ostream &operator<<(ostream &out, const NumberWithUnits &n)
    {
        return out << n.size << '[' << n.unit << ']';
    }
    istream &operator>>(istream &in, NumberWithUnits &n)
    {
        double Size = 0;
        string Unit;
        char openbrc = ' ';
        char closebrc = openbrc;
        in >> skipws >> Size >> openbrc >> Unit;
        size_t len = Unit.length() - 1;
        if (Unit[len] == ']')
        {
            Unit = Unit.substr(0, len);
        }
        else
        {
            in >> closebrc;
        }
        if (NumberWithUnits::convUnit[Unit][Unit] == INVALIDUNIT || len + 1 == 0)
        {
            throw "Invalid unit input";
        }
        n.size = Size;
        n.unit = Unit;
        return in;
    }
}

