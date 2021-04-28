#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>
#include <sstream>
const double EPS = 0.001;
const int INVALIDUNIT = 0;

using namespace std;

namespace ariel
{
    class NumberWithUnits
    {

        double size;
        string unit;

    public:
        static map<string, map<string, double>> convUnit;
        NumberWithUnits(const double &s, const string &un);
        void static newConversion(const string &u1, const string &u2);

        void static read_units(ifstream &unitfile);

        // Arithmetic operators: - + += -= ++ --
        friend NumberWithUnits operator-(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend NumberWithUnits operator+(const NumberWithUnits &n1, const NumberWithUnits &n2);
        friend NumberWithUnits operator-(const NumberWithUnits &n1);
        friend NumberWithUnits operator+(const NumberWithUnits &n1);

        NumberWithUnits &operator-=(const NumberWithUnits &other);
        NumberWithUnits &operator+=(const NumberWithUnits &other);

        NumberWithUnits &operator--();        // pre-decrement // --a
        NumberWithUnits operator--(int flag); // post-decrement // a--
        NumberWithUnits &operator++();        // pre-increment // ++a
        NumberWithUnits operator++(int flag); // post-increment // a++

        // Compare operators: == != < <= > >=
        bool operator==(const NumberWithUnits &n) const;
        bool operator!=(const NumberWithUnits &n) const;
        bool operator<(const NumberWithUnits &n) const;
        bool operator<=(const NumberWithUnits &n) const;
        bool operator>(const NumberWithUnits &n) const;
        bool operator>=(const NumberWithUnits &n) const;

        // Mult operators: * *=
        friend NumberWithUnits operator*(const double x, const NumberWithUnits &n1);
        friend NumberWithUnits operator*(const NumberWithUnits &n1, const double x);
        NumberWithUnits &operator*=(double x);

        // Stream operators: << >>
        friend ostream &operator<<(std::ostream &out, const NumberWithUnits &n);
        friend istream &operator>>(std::istream &in, NumberWithUnits &n);
    };
}