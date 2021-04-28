#include "NumberWithUnits.hpp"
#include <map>
using namespace ariel;
using namespace std;

namespace ariel
{
    map<string, map<string, double>> convUnit;

    NumberWithUnits::NumberWithUnits(double s, string un)
    {

        if (convUnit[un][un] != 0)
        {
            this->size = s;
            this->unit = un;
            if (un == string("cm") || un == string("m") || un == string("km"))
            {
                this->type = DISTANCE;
            }

            if (un == string("g") || un == string("kg") || un == string("ton"))
            {
                this->type = WEIGHT;
            }

            if (un == string("sec") || un == string("min") || un == string("hour"))
            {
                this->type = TIME;
            }

            if (un == string("USD") || un == string("ILS"))
            {
                this->type = MONEY;
            } else {
                this->type = INVALIDUNIT;
            }
        }
        else
        {
            throw invalid_argument(un + "is illegal unit!");
        }
        // try
        // {
        //     convUnit[un];
        //     this->size = s;
        //     this->unit = un;
        // }
        // catch (exception &e)
        // {
        //     cout << un << "is illegal unit!" << endl;
        //     throw e.what();
        // }
    }

    void NumberWithUnits::read_units(ifstream &unitfile)
    {
        string un1, un2, cmp;
        double n1, n2;

        while (unitfile >> n1 >> un1 >> cmp >> n2 >> un2)
        {
            // cout << "n1:" << n1 << endl
            //      << "n2:" << n2 << endl
            //      << "un1:" << un1 << endl
            //      << "un2:" << un2 << endl;
            convUnit[un1][un1] = 1;
            convUnit[un2][un2] = 1;
            convUnit[un1][un2] = n2;
            convUnit[un2][un1] = 1 / n2;
        }
    }

    // Arithmetic operators: - + += -= ++ --
    const NumberWithUnits operator-(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return NumberWithUnits(n1.size - (n2.size * convUnit[n2.unit][n1.unit]), n1.unit);
    }
    const NumberWithUnits operator+(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return NumberWithUnits(n1.size + (n2.size * convUnit[n2.unit][n1.unit]), n1.unit);
    }
    const NumberWithUnits NumberWithUnits::operator-() const
    {
        return NumberWithUnits(-size, unit);
    }
    const NumberWithUnits NumberWithUnits::operator+() const
    {
        return NumberWithUnits(size, unit);
    }

    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &other)
    {
        size -= other.size * convUnit[unit][other.unit];
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &other)
    {
        size += other.size * convUnit[unit][other.unit];
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
    const NumberWithUnits operator*(const double x, const NumberWithUnits &n1)
    {
        return NumberWithUnits(x * n1.size, n1.unit);
    }

    const NumberWithUnits operator*(const NumberWithUnits &n1, const double x)
    {
        return NumberWithUnits(x * n1.size, n1.unit);
    }

    NumberWithUnits &NumberWithUnits::operator*=(double x)
    {
        size *= x;
        return *this;
    }

    // Compare operators: == != < <= > >=
    bool operator==(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return n1.size == (n2.size * convUnit[n2.unit][n1.unit]);
    }
    bool operator!=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return n1.size != n2.size * convUnit[n2.unit][n1.unit];
    }
    bool operator>(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return n1.size > n2.size * convUnit[n2.unit][n1.unit];
    }
    bool operator>=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return n1.size >= n2.size * convUnit[n2.unit][n1.unit];
    }
    bool operator<(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return n1.size < n2.size * convUnit[n2.unit][n1.unit];
    }
    bool operator<=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return n1.size <= n2.size * convUnit[n2.unit][n1.unit];
    }

    // Stream operators: << >>
    ostream &operator<<(ostream &out, const NumberWithUnits &n)
    {
        out << n.size << '[' << n.unit << ']';
        return out;
    }
    istream &operator>>(istream &in, NumberWithUnits &n)
    {
        // n.size = in
        return in;
    }

}

// int main()
// {
//     ifstream units_file{"units.txt"};
//     NumberWithUnits::read_units(units_file);
//     NumberWithUnits a{2,"km"};
//     NumberWithUnits a2{2,"USD"};

//     NumberWithUnits b{100,"m"};
//     NumberWithUnits c{2,"kg"};
//     double d = 11;
//     cout << (a == a2) << endl;
//     return 0;
// }
