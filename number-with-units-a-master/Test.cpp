#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace ariel;
using namespace std;

// TEST_CASE("check output operator <<")
// {
//     NumberWithUnits ton{10, "ton"};
//     CHECK(cout << ton == string("10[ton]"));
//     CHECK(cout << ton == string("10[ton]"));

//     NumberWithUnits kg{100, "kg"};
//     CHECK(cout << kg == string("100[kg]"));
//     CHECK(cout << kg == string("100[kg]"));

//     NumberWithUnits m{55, "m"};
//     CHECK(cout << m == string("55[m]"));
//     CHECK(cout << m == string("55[m]"));

//     NumberWithUnits km{17, "km"};
//     CHECK(cout << km == string("17[km]"));
//     CHECK(cout << km == string("17[km]"));

//     NumberWithUnits g{43, "g"};
//     CHECK(cout << g == string("43[g]"));
//     CHECK(cout << g == string("43[g]"));

//     NumberWithUnits min{90, "min"};
//     CHECK(cout << min == string("90[min]"));
//     CHECK(cout << min == string("90[min]"));
// }

TEST_CASE("check comparison operator ==")
{
    NumberWithUnits ton{10, "ton"};
    NumberWithUnits kg{10000, "kg"};
    NumberWithUnits g{10000000, "g"};
    CHECK(kg == g);
    CHECK(ton == kg);
    NumberWithUnits cm{1000, "cm"};
    NumberWithUnits m{10, "m"};
    NumberWithUnits km{0.01, "km"};
    CHECK(cm == m);
    CHECK(m == km);

}

TEST_CASE("check comparison operator !=")
{
    NumberWithUnits ton{100, "ton"};
    NumberWithUnits kg{10000, "kg"};
    CHECK(ton != kg);
    NumberWithUnits min{20, "min"};
    NumberWithUnits hour{0.01, "hour"};
    CHECK(min != hour);

    CHECK(ton != min);
    CHECK(kg != hour);

}

TEST_CASE("check arithmetic operator +")
{
    NumberWithUnits ton{100, "ton"};
    NumberWithUnits kg{10000, "kg"};
    NumberWithUnits res{110,"ton"};
    CHECK(ton+kg == res);
    NumberWithUnits min{20, "min"};
    NumberWithUnits sec{120, "sec"};
    NumberWithUnits res2{22,"min"};
    CHECK(min+sec == res2);
}

TEST_CASE("check arithmetic operator -")
{
    NumberWithUnits ton{100, "ton"};
    NumberWithUnits kg{10000, "kg"};
    NumberWithUnits res{90000,"kg"};
    CHECK(ton-kg == res);
    NumberWithUnits min{20, "min"};
    NumberWithUnits sec{120, "sec"};
    NumberWithUnits res2{18,"min"};
    CHECK(min-sec == res2);
}

TEST_CASE("check arithmetic operator *")
{
    NumberWithUnits USD{100, "USD"};
    NumberWithUnits ILS{10000, "ILS"};
    NumberWithUnits resu{500,"USD"};
    NumberWithUnits resi{6.66,"ILS"};
    CHECK(5*USD == resu);
    CHECK(2*ILS == resi);

    NumberWithUnits m{5000, "m"};
    NumberWithUnits km{21, "km"};
    NumberWithUnits resm{2500,"m"};
    NumberWithUnits reskm{84,"km"};
    CHECK(0.5*m == resm);
    CHECK(4*km == reskm);

}


TEST_CASE("check arithmetic operator >")
{
    NumberWithUnits USD{100, "USD"};
    NumberWithUnits ILS{10000, "ILS"};
    NumberWithUnits resu{500,"USD"};
    NumberWithUnits resi{6.66,"ILS"};
    CHECK(resu > USD);
    CHECK(resi > ILS);

    NumberWithUnits m{5000, "m"};
    NumberWithUnits km{21, "km"};
    NumberWithUnits resm{2500,"m"};
    NumberWithUnits reskm{84,"km"};
    CHECK(m > resm);
    CHECK(reskm > km);

}

TEST_CASE("check arithmetic operator <")
{
    NumberWithUnits USD{100, "USD"};
    NumberWithUnits ILS{10000, "ILS"};
    NumberWithUnits resu{500,"USD"};
    NumberWithUnits resi{6.66,"ILS"};
    CHECK(USD < resu);
    CHECK(ILS < resi);

    NumberWithUnits m{5000, "m"};
    NumberWithUnits km{21, "km"};
    NumberWithUnits resm{2500,"m"};
    NumberWithUnits reskm{84,"km"};
    CHECK(resm < m);
    CHECK(m < reskm);

}
