#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    string Virologist::role() { return ""; }

    Virologist &Virologist::take_card(City c)
    {
        return *this;
    }
    Virologist &Virologist::drive(City c) {
        return *this;
    }
    Virologist &Virologist::fly_direct(City c){return *this;}
    Virologist &Virologist::fly_charter(City c){return *this;}
    Virologist &Virologist::fly_shuttle(City c){return *this;}
    Virologist &Virologist::build(){return *this;}
    Virologist &Virologist::discover_cure(Color col){return *this;}
    Virologist &Virologist::treat(City c){return *this;}

}