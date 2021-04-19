#include "NumberWithUnits.hpp"
using namespace ariel;
using namespace std;

namespace ariel
{
    void NumberWithUnits::read_units(ifstream &unitfile)
    {

    }

    // Arithmetic operators: - + += -= ++ --
    const NumberWithUnits operator-(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return NumberWithUnits(n1.size - n2.size, n1.unit);
    }
    const NumberWithUnits operator+(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return NumberWithUnits(n1.size + n2.size, n1.unit);
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
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &other)
    {
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



    // Compare operators: != == < <= > >=
    bool operator==(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return true;
    }
    bool operator!=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return true;
    }
    bool operator>(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return true;
    }
    bool operator>=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return true;
    }
    bool operator<(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return true;
    }
    bool operator<=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return true;
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
        return *this;
    }







    // Stream operators: << >>
    ostream &operator<<(std::ostream &out, const NumberWithUnits &n)
    {
        out << n.size << '[' << n.unit << ']';
        return out;
    }
    istream &operator>>(std::istream &in, NumberWithUnits &n)
    {
        return in;
    }

}
