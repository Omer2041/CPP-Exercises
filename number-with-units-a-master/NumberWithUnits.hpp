#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>
#include <sstream>
const int DISTANCE = 0;
const int WEIGHT = 1;
const int TIME = 2;
const int MONEY = 3;

using namespace std;

namespace ariel
{
    class NumberWithUnits
    {

        double size;
        string unit;
        int type;
        map<string, map<string, double>> convUnit;

    public:
        NumberWithUnits(double s = 0, string un = "") : size(s), unit(un)
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
            }
        }

        void static read_units(ifstream &unitfile);

        // Arithmetic operators: - + += -= ++ --
        friend const NumberWithUnits operator-(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend const NumberWithUnits operator+(const NumberWithUnits &n1, const NumberWithUnits &n2);
        const NumberWithUnits operator-() const;
        const NumberWithUnits operator+() const;

        NumberWithUnits &operator-=(const NumberWithUnits &other);
        NumberWithUnits &operator+=(const NumberWithUnits &other);

        NumberWithUnits &operator--();        // pre-decrement // --a
        NumberWithUnits operator--(int flag); // post-decrement // a--
        NumberWithUnits &operator++();        // pre-increment // ++a
        NumberWithUnits operator++(int flag); // post-increment // a++

        // Compare operators: != == < <= > >=
        friend bool operator==(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend bool operator!=(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend bool operator>(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend bool operator>=(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend bool operator<(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend bool operator<=(const NumberWithUnits &n1, const NumberWithUnits &n2);

        // Mult operators: * *=
        friend const NumberWithUnits operator*(const double x, const NumberWithUnits &n1);
        friend const NumberWithUnits operator*(const NumberWithUnits &n1, const double x);
        NumberWithUnits &operator*=(double x);

        // Stream operators: << >>
        friend ostream &operator<<(std::ostream &out, const NumberWithUnits &n);
        friend istream &operator>>(std::istream &in, NumberWithUnits &n);
    };
}