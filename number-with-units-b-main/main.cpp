#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <fstream>
#include<time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include "NumberWithUnits.cpp"
using namespace std;
using namespace ariel;

int main()
{

  ifstream units_file{"units.txt"};
  ariel::NumberWithUnits::read_units(units_file);

  ariel::NumberWithUnits x{2, "km"};
  ariel::NumberWithUnits y{500, "m"};
  ariel::NumberWithUnits z{0, "km"};
  z = x - y;
  cout << boolalpha;
  cout << endl
       << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl
       << endl;

  cout << "****************************************ARITHMETIC OPERATORS****************************************" << endl;

  cout << "CHECK OPERATOR -" << endl;
  cout << "x-y = " << z << endl;
  cout << "-x = " << -x << endl;

  cout << "CHECK OPERATOR +" << endl;
  z = x + y;
  cout << "x+y = " << z << endl;
  cout << "+y = " << +y << endl;


  cout << "CHECK OPERATOR *" << endl;
  cout << "z*2 = " << z * 2 << endl;
  cout << "2*z = " << 2 * z << endl;
  cout << "2*(z) = " << 2 * (z) << endl
       << endl;

  cout << "CHECK OPERATOR +=" << endl;
  z += x;
  cout << "z+=x = " << z << endl;

  cout << "CHECK OPERATOR -=" << endl;
  z -= x;
  cout << "z-=x = " << z << endl;

  cout << "CHECK OPERATOR *=" << endl;
  z *= 2;
  cout << "z*=2 = " << z << endl
       << endl;

  cout << "CHECK OPERATOR ++" << endl;
  cout << "(x++) = " << x++ << endl;
  cout << "x = " << x << endl;
  cout << "(++x) = " << ++x << endl;
  cout << "x = " << x << endl
       << endl;

  cout << "CHECK OPERATOR --" << endl;
  cout << "(x--) = " << x-- << endl;
  cout << "x = " << x << endl;
  cout << "(--x) = " << --x << endl;
  cout << "x = " << x << endl
       << endl;
  cout << endl
       << endl;

  cout << endl
       << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl
       << endl;
    cout << endl
       << endl;

  cout << "****************************************COMPARE OPERATORS****************************************:" << endl;

  cout << "CHECK OPERATOR ==" << endl;
  cout << "(x == y) = " << (x == y) << endl;
  cout << "(y == x) = " << (y == x) << endl;
  cout << "(y == y) = " << (y == y) << endl;
  cout << "(x == x) = " << (x == x) << endl;

  cout << "CHECK OPERATOR !=" << endl;
  cout << "(x != y) = " << (x != y) << endl;
  cout << "(y != x) = " << (y != x) << endl;
  cout << "(y != y) = " << (y != y) << endl;
  cout << "(x != x) = " << (x != x) << endl;

  cout << endl;

  cout << "CHECK OPERATOR < " << endl;
  cout << "(x < y) = " << (x < y) << endl;
  cout << "(y < x) = " << (y < x) << endl;
  cout << "(y < y) = " << (y < y) << endl;
  cout << "(x < x) = " << (x < x) << endl;

  cout << "CHECK OPERATOR > " << endl;
  cout << "(x > y) = " << (x > y) << endl;
  cout << "(y > x) = " << (y > x) << endl;
  cout << "(y > y) = " << (y > y) << endl;
  cout << "(x > x) = " << (x > x) << endl;

  cout << endl;

  cout << "CHECK OPERATOR >= " << endl;
  cout << "(x >= y) = " << (x >= y) << endl;
  cout << "(y >= x) = " << (y >= x) << endl;
  cout << "(y >= y) = " << (y >= y) << endl;
  cout << "(x >= x) = " << (x >= x) << endl;

  cout << "CHECK OPERATOR <= " << endl;
  cout << "(x <= y) = " << (x <= y) << endl;
  cout << "(y <= x) = " << (y <= x) << endl;
  cout << "(y <= y) = " << (y <= y) << endl;
  cout << "(x <= x) = " << (x <= x) << endl;

    cout << endl
       << endl;



  x = NumberWithUnits{320, "m"};
  istringstream sample_input{"320 [ m ]"};
  sample_input >> x;
  cout << "check input and output\n";
  cout << x << endl;                                      // Prints "320[m]"
  cout << (x += ariel::NumberWithUnits{9, "km"}) << endl; // prints "9320[kg]"
  cout << x << endl;                                      // Prints "9320[m]". Note that x has changed.

  cout << "random numbers test\n";
  srand(time(0));
  for (int i = 0; i < 100; i++)
  {
    int rand1 = rand() % 70;
    ariel::NumberWithUnits x{(double)rand1, "hour"};
    ariel::NumberWithUnits y{(double)rand1 * 3600, "sec"};
    if (!(x == y))
      cout << "false" << endl;
    if (!(x * 2 == y + y))
      cout << "false" << endl;

    cout << x << "  ==  " << y << endl;
  }
  return 0;
}

/*
clear && clang-9 -o run main.cpp -lstdc++ && ./run
*/