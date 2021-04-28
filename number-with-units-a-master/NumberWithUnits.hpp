#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>
#include <sstream>
const int INVALIDUNIT = 0;
const int DISTANCE = 1;
const int WEIGHT = 2;
const int TIME = 3;
const int MONEY = 4;

using namespace std;

namespace ariel
{
    class NumberWithUnits
    {

        double size;
        string unit;
        int type;

    public:
        NumberWithUnits(double s, string un);

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